/*
    FRSL Matrix Library
    constructor: matrix(a,b) a matrix with a rows and b columns
    init();		input with std input
    finit(*fin);	input with file input
    refinit();	destruct and reinit by file
    pr();		print the matrix on the screen
    fpr(*fout);	print the matrix in a file
    operator +	calculate a+b //matrix c=a+b;
    operator *  calculate a*b //matrix c=a*b;
    operator -	matrix transpose c=a+(-b); 
    ele(i,j)	return the value of the element i,j
    elex(i,j,t)	replace the element i,j with t
    size(type)	return the row(or column) of this matrix 
				e.g: size(Row);size(Column);
    
*/
#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<cstdio>
#include<cmath>
#include<malloc.h>
#define Row 1
#define Column 0
class matrix{
	public:
		matrix(int a,int b);
		~matrix(){}
		void init();
		void finit(FILE *fin);
		void refinit(FILE *fin);
		void pr();
		void fpr(FILE *fout);
		bool add(matrix b);
		matrix operator+(matrix b){
			int ma,na,mb,nb;
			
			ma=this->size(Row);
			na=this->size(Column);
			mb=b.size(Row);
			nb=b.size(Column);
			
			matrix a(mb,nb);
			if(ma!=mb||na!=nb)
			  return a;
			  
	    	int i,j;
		  	for(i=0;i<ma;i++)
	  	    	for(j=0;j<na;j++)
	          		a.elex(i,j,this->ele(i,j)+b.ele(i,j));
	        return a;
		}
		matrix mul(matrix b);
		matrix operator*(matrix b){
			int ma,na,mb,nb;
			
			ma=this->size(Row);
			na=this->size(Column);
			mb=b.size(Row);
			nb=b.size(Column);
			matrix a(ma,nb);
			
			if(na!=mb)
	  			return a;
	  			
			int i,j,k;
			double t;
			for(i=0;i<ma;i++){
	  			for(j=0;j<nb;j++){
	  				t=0;
	  				for(k=0;k<na;k++)
	  	  				t+=this->ele(i,k)*b.ele(k,j);
	    			a.elex(i,j,t);
	  			}
			}
				return a;
		}
		matrix operator-(){
			matrix a(n,m);
			int i,j;
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
					a.elex(j,i,data[i][j]);
			return a;
		}
		double ele(int i,int j);
		void elex(int i,int j,double t); 
		int size(int type);
		
	private:
		int m;//Row
		int n;//Column
		double **data;
};

matrix::matrix(int a,int b){
	m=a;
	n=b;  
	int i;
    data=(double**)malloc(sizeof(double*)*m);    
    for(i=0;i<m;i++)    
    	data[i]=(double*)malloc(sizeof(double)*n);
}

void matrix::init(){
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
	    	scanf("%lf",&data[i][j]);
}

void matrix::finit(FILE *fin){
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
	    	fscanf(fin,"%lf",&data[i][j]);
}

void matrix::refinit(FILE *fin){
	int i,j;
	for(i=0;i<m;i++)    
    	free(data[i]);
    free(data);
    int a,b;
    fscanf(fin,"%d%d",&a,&b);
    m=a;
	n=b;  
    data=(double**)malloc(sizeof(double*)*m);    
    for(i=0;i<m;i++)    
    	data[i]=(double*)malloc(sizeof(double)*n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			fscanf(fin,"%lf",&data[i][j]);
}

void matrix::pr(){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
	  		printf("%lf ",data[i][j]);
	  	printf("\n");
	}
	printf("\n");
}

void matrix::fpr(FILE *fout){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
	    	fprintf(fout,"%lf ",data[i][j]);
	  	fprintf(fout,"\n");
	}
	fprintf(fout,"\n");
}

double matrix::ele(int i,int j){
	return data[i][j];
}

void matrix::elex(int i,int j,double t){
	data[i][j]=t;
}

int matrix::size(int type){
	if(type==Row)
		return m;
	if(type==Column)
		return n;
}

bool matrix::add(matrix b){
	if(m!=b.size(Row)||n!=b.size(Column))
		return false;
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			data[i][j]+=b.ele(i,j);
	return true;
}

matrix matrix::mul(matrix b){
	matrix a(this->size(Row),b.size(Column));
	if(this->size(Column)!=b.size(Row))
		return a;
	int i,j,k;
	double t;
	for(i=0;i<a.size(Row);i++){
		for(j=0;j<b.size(Column);j++){
	  		t=0;
	  		for(k=0;k<this->size(Column);k++)
	  	  		t+=this->ele(i,k)*b.ele(k,j);
	    	a.elex(i,j,t);
	  	}
	}
	return a;
}
#endif 
