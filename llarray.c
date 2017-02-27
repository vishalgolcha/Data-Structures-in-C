#include "queue.h"
#define ptoqueue queued* 
#define ptoarr ptoqueue*
int main(){
	ptoqueue *arr= (ptoqueue *)malloc(20*sizeof(queued*));
	// need to initialize these to NULL 	
	int i;
	
	for(i=0;i<20;i++){
		arr[i]=(queued *)malloc(sizeof(queued));
		arr[i]->first=NULL;
		arr[i]->rear=NULL;
	}	
	
	for(i=0;i<20;i++){
		queue_add(arr[i],i);
	}
	
	for(i=0;i<20;i++){
		print_list(arr[i]);
		printf("\n");
	}
	
	ptoarr* arrarr = (ptoarr*)malloc(8*sizeof(ptoarr));
	
	int j;
	
	for(i=0;i<8;i++){
		arrarr[i]=(ptoqueue *)malloc(20*sizeof(queued*));
		for(j=0;j<20;j++){
			arrarr[i][j]=(queued *)malloc(sizeof(queued));
			arrarr[i][j]->first=NULL;
			arrarr[i][j]->rear=NULL;
		}
	}
	//trial
	for(j=0;j<20;j++){
		queue_add(arrarr[0][j],j);
	}
	//check
	for(i=0;i<20;i++){
		print_list(arrarr[0][i]);
		printf("\n");
	}
}