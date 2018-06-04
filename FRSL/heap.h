#ifndef HEAP_H
#define HEAP_H
#include<iostream>
#include<cstdio>
#include<cstdlib>
const int inf = 2147483647;
template<typename STU, typename ORD>
class heap {
public:
	void push(STU x);
	STU pop();
	void del();
	heap(int max, ORD * (*func)(STU *t));
	~heap() {}
private:
	STU * data;
	int end;
	ORD * (*ord_data)(STU *t); 
};

template<typename STU, typename ORD>
heap<STU, ORD>::heap(int max, ORD * (*func)(STU *t)) {
	ord_data=func;
	data = (STU *)malloc(sizeof(STU)*max);
	for (int i = 0; i < max; i++) 
		*ord_data(&data[i]) = 0;
	
	end = 1;
}

template<typename STU, typename ORD>
STU heap<STU, ORD>::pop() {
	return data[1];
}

template<typename STU, typename ORD>
void heap<STU, ORD>::push(STU x) {
	int i;
	STU t;
	data[end] = x;
	i = end;
	while (*ord_data(&data[i])<*ord_data(&data[i >> 1])) {
		t = data[i >> 1];
		data[i >> 1] = data[i];
		data[i] = t;
		i >>= 1;
	}
	end++;
}

template<typename STU, typename ORD>
void heap<STU, ORD>::del() {
	int empty = 1, last = end - 1;
	int l = empty << 1, r = empty << 1 | 1;
	ORD *data_l = ord_data(&data[l]),
		*data_r = ord_data(&data[r]),
		*data_last = ord_data(&data[last]);
	if ((*data_l) == 0)*data_l = inf;
	if ((*data_r) == 0)*data_r = inf;
	while (!((*data_l)>(*data_last)
		&& (*data_r)>(*data_last))) {
		if ((*data_l)<(*data_r)) {
			data[empty] = data[l];
			empty = l;
		}
		else {
			data[empty] = data[r];
			empty = r;
		}
		l = empty << 1;
		r = empty << 1 | 1;
		data_l = ord_data(&data[l]);
		data_r = ord_data(&data[r]);
		if ((*data_l) == 0)*data_l = inf;
		if ((*data_r) == 0)*data_r = inf;

	}
	data[empty] = data[last];
	*data_last = 0;
	end--;
}
/*
struct node {
	int data;
};

int *out(node *t) {
	return &(*t).data;
}

*/
#endif
