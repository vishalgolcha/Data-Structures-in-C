#include "stack.h"
void push(stacked *head, int ele){
	node* link = (node*)malloc(sizeof(node));
	link->element=ele;
	link->next=head->first;
	head->first=link;
	head->count++;
}

int pop(stacked *head){
	node * temp ;
	temp=head->first;
	head->first=temp->next;
	temp->next=NULL;
	head->count--;
	int i=temp->element;
	free(temp);
	return i;
}

void print_list(stacked * head){
	node* ptr=head->first;
	printf("\n[ ");
	while(ptr!=NULL){
		printf("%d, ",ptr->element);
		ptr = ptr->next;
	}	
}