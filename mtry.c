#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int val ;
	struct node * next ;
}node ;
typedef struct linkedlist{
	node *first ;
	node *rear;
	int count ;
}linkedlist;

#define  link linkedlist

node *insert(link *head ,int ele){
	node * add =(node*)malloc(sizeof(node*));
	add->val=ele;
	add->next=head->first;
	head->first=add;		
	head->count++;
}
void split(node * src ,node** f,node**s){
	node *fast = *f;
	node *slow = *s;
	
	if(src->next==NULL){
		*f =NULL;
		*s =src;	
		return;
	}

	fast=src;
	slow=src;

	while(fast->next!=NULL){
		// slow=fast;
		fast=fast->next;
		
		if(fast->next!=NULL){			
			slow=slow->next;
			fast=fast->next;
			// if(fast==slow){
			// 	cout<<"cycle"<<"\n";
			// }
		}
	}
	// printf("%d\n",slow->val);
	// printf("%d\n",fast->val);
	*f =slow->next;
	*s =slow;
	 slow->next=NULL;
}
// node *ins_middle(link *head ,int ele){

// }
// node *delete(link *head ,int ele){

// }
node *merge(node *a ,node* b){
   struct node* result = NULL;
   if (a == NULL){
   		return(b);
   }
   else if (b==NULL)
     	return(a);
 
   if (a->val <= b->val){
    	result = a;
     	result->next = merge(a->next, b);
   }
   else{
    	result = b;
    	result->next = merge(a, b->next);
   }
   return(result);
}

void * mergesort(node **sref){
	node * src= *sref;
	node* a,*b;
	if ((src == NULL) || (src->next == NULL)){
    	return;
	}
	split(src,&b,&a);
	mergesort(&a);
	mergesort(&b);
	(*sref)= merge(a,b);
}

// dont inititalize for inside the loop
void traverse(node * src){
	while(src){
		src=src->next;
		printf("%d\n",src->val);
	}
}
int main(){
	link * head =(link *)malloc(sizeof(link *));
	head->first=NULL;
	insert(head,8);
	insert(head,10);
	insert(head,2);
	insert(head,5);
	node *fast=(node*)malloc(sizeof(node*));
	node *slow=(node*)malloc(sizeof(node*));
	mergesort(&(head->first));
	traverse(head->first);
	// cycle_detect(head,&fast,&slow);
	// printf("%d\n",slow->val);
	// printf("%d\n",fast->val);
}