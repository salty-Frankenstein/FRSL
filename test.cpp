#include<iostream>
#include<cstdio>
#include<heap.h>
using namespace std;
int main(){
	heap a(1000);
	int n,i,j,t1,t2;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&t1);
      if(t1==1){
        scanf("%d",&t2);
        a.push(t2);
      }
      else if(t1==2)
        printf("%d\n",a.pop());
      else
        a.del();
    }
	return 0;
}
