#include <stdio.h>
#include <stdlib.h>

struct{
	struct node * next;
	int element;
} node;

struct{
	struct node * first;
	int count;
} ll;

void inst_first(struct ll*head, int ele){
	struct node* link = (struct node*)malloc(sizeof(node));
	link->element=ele;
	link->next=head->first;
	head->first=link;
	head->count++;
}
node *delt_first(struct ll*head){
	node * temp ;
	temp->next=head->first;
	head->first=temp->next;
	temp->next=NULL;
}
void print_list(struct ll* head){
	struct node* ptr=head->first;
	printf("\n[ ");
	while(ptr!=NULL){
		printf("%d, ",ptr->element);
		ptr = ptr->next;
	}	

}
int search(struct ll*head, int ele){

}
node delt(struct ll*head , int ele){

}

int main(){
	struct ll* head = (struct ll*)malloc(sizeof(ll));
	head->first=NULL;
	head->count=0;
	inst_first(head,1);
	print_list(head);
}