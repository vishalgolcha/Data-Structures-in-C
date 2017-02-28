#include "queue.h"
#include "hashed.h"
#define ptoqueue queued* 
#define ptoarr ptoqueue*

int (*p[8]) (int x, dats y);
dats brr[100];
int main(){
	
	// set the function pointers 
	p[0]=&h1;p[1]=&h2;
	p[2]=&h3;p[3]=&h4;
	p[4]=&h5;p[5]=&h6;
	p[6]=&h7;p[7]=&h8;		

	ptoqueue *arr= (ptoqueue *)malloc(20*sizeof(queued*));

	// need to initialize these to NULL 	
	int i,k,l;
	
	for(i=0;i<10;i++){
		scanf("%s %d",brr[i].name,&brr[i].id);
	}
	// declared 8 hash tables 
	ptoarr* arrarr = (ptoarr*)malloc(8*sizeof(ptoarr));
	int j;
	
	for(i=0;i<8;i++){
		// declared number of slots 
		int slots;
		
		if(i%2==0)
			slots=20;
		else
			slots=200;

		arrarr[i]=(ptoqueue *)malloc(slots*sizeof(queued*));
		
		for(j=0;j<slots;j++){
			arrarr[i][j]=(queued *)malloc(sizeof(queued));
			arrarr[i][j]->first=NULL;
			arrarr[i][j]->rear=NULL;
		}
	}
	
	//trial

	for(i=0;i<8;i++){
		int slots;
	
		if(i%2==0)
			slots=20;
		else
			slots=200;

		for(j=0;j<10;j++){
			int slot=p[i](slots,brr[j]);
			queue_add(arrarr[i][slot],brr[j].id);
		}
	}
	for(j=0;j<10;j++){
	
		for(i=0;i<8;i++){
			int slots;
	
			if(i%2==0)
				slots=20;
			else
				slots=200;

			int slot=p[i](slots,brr[j]);
			node * outp = search(arrarr[i][slot],brr[j].id);
			printf("%d ",outp->counter);
			
		}
		printf("\n");
	}
	//check
	// for(j=0;j<8;j++){
		// for(i=0;i<20;i++){
			// print_list(arrarr[j][i]);
			// printf("\n");
		// }
	// }

}




// check	
// for(i=0;i<20;i++){
// 	arr[i]=(queued *)malloc(sizeof(queued));
// 	arr[i]->first=NULL;
// 	arr[i]->rear=NULL;
// }	

// for(i=0;i<20;i++){
// 	queue_add(arr[i],i);
// }

// for(i=0;i<20;i++){
// 	print_list(arr[i]);
// 	printf("\n");
// }
