#ifndef HEAP_H
#define HEAP_H
#include<iostream>
#include<malloc.h>
const int inf=2147483647;
class heap{
	public:
		void push(int x);
		int pop();
		void del();
		heap(int max);
		~heap(){}
	private:
		int *data;
		int end; 
};

heap::heap(int max){
	data=(int *)malloc(sizeof(int)*max);
	end=1;
}

int heap::pop(){
	return data[1];
}

void heap::push(int x){
    int i,t;
    data[end]=x;
    i=end;
    while(data[i]<data[i>>1]){
      t=data[i>>1];
      data[i>>1]=data[i];
      data[i]=t;
      i>>=1;
    }
    end++;
}

void heap::del(){
	int empty=1,last=end-1;
    int l=empty<<1,r=empty<<1|1;
    if(data[l]==0)data[l]=inf;
    if(data[r]==0)data[r]=inf;
    while(!(data[l]>data[last]
	      &&data[r]>data[last])){
        if(data[l]<data[r]){
            data[empty]=data[l];
            empty=l;
        }
        else{
            data[empty]=data[r];
            empty=r;
        }
        l=empty<<1;
        r=empty<<1|1;
        if(data[l]==0)data[l]=inf;
        if(data[r]==0)data[r]=inf;
    }
    data[empty]=data[last];
    data[last]=0;
    end--;
}
#endif

