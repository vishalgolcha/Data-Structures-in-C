#include "linkedlist.h"

void push(ll *head, int ele){
	node* link = (node*)malloc(sizeof(node));
	link->element=ele;
	link->next=head->first;
	head->first=link;
	head->count++;
}

node *pop(ll *head){
	node * temp ;
	temp=head->first;
	head->first=temp->next;
	temp->next=NULL;
	head->count--;
	return temp;
}

void print_list(ll * head){
	node* ptr=head->first;
	printf("\n[ ");
	while(ptr!=NULL){
		printf("%d, ",ptr->element);
		ptr = ptr->next;
	}	
}

int search(ll *head, int ele){
	node* ptr=head->first;
	int flag=0;
	while(ptr!=NULL){
		if(ptr->element >ele){
			flag=1;
			break ;
		}
		ptr = ptr->next;
	}	
	return flag;
}

void sinsert(ll *head, int ele){
	node* ptr=head->first;
	int flag=0;
	while(ptr!=NULL){
		if(ptr->element >ele){
			flag=1;
			break ;
		}
		ptr = ptr->next;
	}	
	insert(ptr,ele);	
}

void insert(node *ptr, int ele){
	node *temp;
	temp=ptr->next; 
	node* in= (node*)malloc(sizeof(node));
	in->element=ele;
	in->next=tmp;
	ptr->next=in;
}

node *delt(ll *head , int ele){
	if(!search(head,ele)){
		return NULL;
	}
	else if((head->first)->element==ele){
		delt_first(head);	
	}
	else{
		node* ptr=head->first;
		int flag=0;
		while(ptr!=NULL){
			if((ptr->next)->element==ele){
				node* temp ;
				temp = ptr->next;
				ptr->next=temp->next;
				head->count--;
				return temp;
			}
			ptr = ptr->next;
		}	
		return NULL;		
	}
}

// node *delta(node *node){

// }
// int main(){
// 	ll* head = (ll*)malloc(sizeof(ll));
// 	head->first=NULL;
// 	head->count=0;
// 	inst_first(head,1);
// 	inst_first(head,2);
// 	inst_first(head,2);
// 	inst_first(head,2);
// 	delt_first(head);
// 	print_list(head);
// }