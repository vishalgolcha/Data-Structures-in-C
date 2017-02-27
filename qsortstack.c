#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#define print(x) printf("%d",x) 
#define push2(h,a,b) push(h,a), push(h,b)

// stacked* head =(stacked *)malloc(sizeof(stacked*)); // why does this not work ?
// partition using median of three
struct data{
	int x;
	char y[20];
} p[100];
// treat last element as pivot

void swap(int x,int y){
	struct data temp ;
	temp =p[x];
	p[x]=p[y];
	p[y]=temp;
}

int pivot(int lo,int hi){
	int mid = (lo+hi)>>1;
	if( p[lo].x <= p[hi].x && p[lo].x >=  p[mid].x){
		return lo;	
	}
	else if( p[hi].x <= p[lo].x && p[hi].x >= p[mid].x){
		return hi;	
	}
	else{
		return mid;
	}
}
int visit[10];
int partition(int lo,int hi){
	printf("%d %d\n",lo,hi);
	int piv=(rand()%(hi+1-lo))+lo;//pivot(lo,hi);
	int y=hi;
	swap(piv,hi);
	hi--;
	if(lo==hi){ // idhar galti thi chutiye 
		if(p[lo].x>p[y].x){
			swap(y,lo);
			return lo ;
		}
		else{
			swap(y,hi+1);	
			return hi+1;
		}
	}
	else if(lo<hi){
		while(lo!=hi && lo<hi){
			if(p[lo].x<=p[y].x){
				lo++;
			}
			else{
				swap(hi,lo);
				hi--;
			}
		}
		if(p[lo].x>p[y].x){
			swap(y,lo);
			return lo ;
		}
		else{
			swap(y,hi+1);	
			return hi+1;
		}
	}
}
int i=10;
void qusort(int lo , int hi ,stacked *head){
	push2(head,lo,hi);
	while(head->count!=0){
		int r=pop(head);
		int l=pop(head);
		if(r<=l)
			continue;
		int piv=partition(l,r);
		printf("pivot_sort\n");
		print(piv);
		printf("\n");

		if(piv-l > r-piv){
			// print(1001);
			push2(head,l,piv-1);
			push2(head,piv+1,r);
		}
		else{
			push2(head,piv+1,r);
			push2(head,l,piv-1);
		}
	}

}

int main(){
	stacked* head =(stacked *)malloc(sizeof(stacked*));
	head->first=NULL;
	head->count=0;
	p[0].x=4;
	p[1].x=4;
	p[2].x=2;
	p[3].x=3;
	p[4].x=6;
	p[5].x=5;

	qusort(0,5,head);
	print(p[0].x);
	print(p[1].x);
	print(p[2].x);
	print(p[3].x);
	print(p[4].x);
	print(p[5].x);
	// print_list(head);
}