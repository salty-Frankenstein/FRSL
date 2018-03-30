#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<malloc.h>

/*
a stack structure has these functions as listed:
  init(int maxsize)
  push(int an element)
  pop():pop the top
  prtop():print the top
  get_top():return the top
  make_empty()
  is_empty():return if the stack is empty
  dispose()
  pop_top():return top and then pop
  
*/
using namespace std;
class stack{
	public:
		void init(int max);
		
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
		void dispose(){
			free(data);
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

void stack::init(int max){
	data=(int *)malloc(sizeof(int)*max);
	top=0;
}

void stack::push(int num){
	data[top]=num;
	top++;
}
