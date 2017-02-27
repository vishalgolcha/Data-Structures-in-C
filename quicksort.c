#include <stdio.h>
#include <stdlib.h>
#define sc(x) scanf("%d",&x)

struct data{
	int x;
	char y[20];
} nodes[10];
// treat last element as pivot
void swap(int x,int y){
	struct data temp ;
	temp =nodes[x];
	nodes[x]=nodes[y];
	nodes[y]=temp;
}
int part(int lo,int hi){
	int pivot=hi;
	hi--;
	if(lo==hi){
		return lo;
	}
	else if(lo<hi){
		while(lo!=hi && lo<hi){
			if(nodes[lo].x<=nodes[pivot].x){
				lo++;
			}
			else{
				swap(hi,lo);
				hi--;
			}
		}
		if(nodes[lo].x>nodes[pivot].x){
			swap(pivot,lo);
			return lo ;
		}
		else{
			swap(pivot,hi+1);	
			return hi+1;
		}
	}

}
void quicksort(int lo , int hi){
	if(lo<hi){
		int p=part(lo,hi);
		quicksort(lo,p-1);
		quicksort(p+1,hi);	
	}
}
int main(){
	int i;

	for(i=0;i<10;i++){
		scanf("%s %d",nodes[i].y,&nodes[i].x);
	}
	quicksort(0,9);
	for(i=0;i<10;i++){
		printf("%s",nodes[i].y);
		printf(" %d\n",nodes[i].x);
	}
	return 0;
}