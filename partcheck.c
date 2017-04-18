#include <stdio.h>
#include <stdlib.h>
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

int partition(int lo,int hi){
	int piv=hi;//pivot(lo,hi);
	int y=hi;
	// swap(piv,hi);
	hi--;
	if(lo==hi){
		return lo;
	}
	else if(lo<hi){
		while(lo!=hi && lo<hi){
			if(p[lo].x<=p[piv].x){
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
