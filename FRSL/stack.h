
/*
a stack structure has these functions as listed:
  push(int an element)
  pop():pop the top
  prtop():print the top
  get_top():return the top
  make_empty()
  is_empty():return if the stack is empty
  pop_top():return top and then pop
  
*/
#ifndef STACK_H
#define STACK_H
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<malloc.h>

class stack{
	public:
		stack(int max);
		~stack(){}
		void push(int num);
		
		void pop(){
			if(!is_empty())
				top--;
			
		}
		
		void prtop(){
			cout<<data[top-1];
			cout<<"\n";
		}
		
		int get_top(){
			return data[top-1];
		}
		
		void make_empty(){
			top=0;
		}
		
		bool is_empty(){
			return top==0;
		}
		
		int pop_top(){
			if(!is_empty()){
				top--;
				return data[top];
			}
			Error("Empty stack");
			return 0;
		}
	private:
		int top;
		int *data;
			
};

stack::stack(int max){
	data=(int *)malloc(sizeof(int)*max);
	top=0;
}

void stack::push(int num){
	data[top]=num;
	top++;
}
#endif
