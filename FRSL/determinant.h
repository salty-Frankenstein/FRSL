/*
	FRSL determinant library
	included matrix.h
	public value(this->size(Row))	calculate the value of the determinant
*/
#ifndef DET_H
#define DET_H
#include<matrix.h> 
class det:public matrix{
	public:
		double value(int i);
		det(int a,int b):matrix(a,b){}
}; 

void next(int n,int &i,int &j){
	if(j>=n-1){
		j=0;
		i++;
		return;
	} 
	j++;
}

double det::value(int i){
	if(i==1)return this->ele(0,0);
	det a[i]=det(i-1,i-1);
	int t,Max,k,l,io,jo,ix,jx;
	double ans=0; 
	Max=(i-1)*(i-1);
	for(int j=0;j<i;j++){
		t=1;
		io=1;
		jo=0;//origin 
		ix=0;
		jx=0;
		while(t<=Max){
			if(jo!=j){
				t++;
				a[j].elex(ix,jx,this->ele(io,jo));
				next(i-1,ix,jx);
			}
			next(i,io,jo);
		}
	}
	for(int j=0;j<i;j++){
		ans+=pow(-1,j)*(a[j].value(a[j].size(Row)))*this->ele(0,j);
	}
	return ans;
}
#endif 
