#include "queue.h"

void queue_add(queued *head, int ele){
	node* link = (node*)malloc(sizeof(node));
	link->element=ele;
	

	if(head->count==0){
		head->rear=link	;
		head->first=link;
		// printf("%s\n",);
	}
	else{	
		head->rear->next=link ;
		link->next=NULL;
		head->rear=link;
	}
	head->count++;
	head->rear->counter= head->count;
	// free(link);
}

node *queue_rem(queued *head){
	node * temp ;
	temp=head->first;
	head->first=temp->next;
	temp->next=NULL;
	head->count--;
	return temp;
}

void print_list(queued * head){
	node* ptr=head->first;
	printf("\n[ ");
	while(ptr!=NULL){
		printf("%d, ",ptr->element);
		ptr = ptr->next;
	}	
}

node * search(queued *head, int ele){
	node* ptr=head->first;
	int flag=0;
	while(ptr!=NULL){
		if(ptr->element==ele){
			flag=1;
			return ptr;
		}
		ptr = ptr->next;
	}	
	// return flag;
}