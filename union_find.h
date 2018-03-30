#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
	int father;
	int data;
};

class union_find{
	public:
		void init(int max);
		
		int find(int x);
	
		void unite(int x,int y){
 	   	set[find(x)].father=find(y);
		}
	
		bool same_set(int x,int y){
			return find(x)==find(y);
		}
		
		void set_data(int index,int val){
			set[index].data=val;
		}
		
		void dispose(){
			free(set);
			free(t);
		}
	
	private:
		int *t;
		struct node *set;
};
void union_find::init(int max){
	set=(struct node *)malloc(sizeof(struct node)*max);
	t=(int *)malloc(sizeof(int)*max);
	for(int i=0;i<max;i++){
		set[i].father=i;
		set[i].data=i;
	}
}

int union_find::find(int x){
    int k=0,i;
    while(set[x].father!=x){
        k++;
        t[k]=x;
        x=set[x].father;
    }
    for(i=1;i<=k-1;i++)
        set[t[i]].father=x; 
    return x;
}
