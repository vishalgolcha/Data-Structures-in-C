#include<stdio.h>
#include<stdlib.h>
  
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
/* function prototypes */
struct node* merge(struct node* a, struct node* b);
void split(struct node* source,
          struct node** frontRef, struct node** backRef);
 
/* sorts the linked list by changing next pointers (not data) */
void mergesort(struct node** headRef){
  struct node* head = *headRef;
  struct node* a;
  struct node* b;
 
  /* Base case -- length 0 or 1 */
  if ((head == NULL) || (head->next == NULL)){
    return;
  }
 
  /* Split head into 'a' and 'b' sublists */
  split(head, &a, &b); 
  /* Recursively sort the sublists */
  mergesort(&a);
  mergesort(&b);
  /* answer = merge the two sorted lists together */
  *headRef = merge(a, b);
}
 
struct node* merge(struct node* a, struct node* b){
  struct node* result = NULL;
 
  /* Base cases */
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->data <= b->data){
     result = a;
     result->next = merge(a->next, b);
  }
  else{
     result = b;
     result->next = merge(a, b->next);
  }
  return(result);
}
void split(struct node* source,
          struct node** frontRef, struct node** backRef){
  struct node* fast;
  struct node* slow;
  if (source==NULL || source->next==NULL){
    /* length < 2 cases */
    *frontRef = source;
    *backRef = NULL;
  }
  else{
    slow = source;
    fast = source->next;
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL){
      fast = fast->next;
      if (fast != NULL){
        slow = slow->next;
        fast = fast->next;
      }
    }
 
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *node){
  while(node!=NULL){
   printf("%d ", node->data);
   node = node->next;
  }
}
 
/* Function to insert a node at the beginging of the linked list */
void push(struct node** head_ref, int new_data){
  struct node* new_node =
            (struct node*) malloc(sizeof(struct node));  
  new_node->data  = new_data;
  new_node->next = (*head_ref);    
  (*head_ref)    = new_node;
} 
  
int main(){
  /* Start with the empty list */
  struct node* res = NULL;
  struct node* a = NULL;
  
  push(&a, 15);
  push(&a, 10);
  push(&a, 5); 
  push(&a, 20);
  push(&a, 3);
  push(&a, 2); 
  
  /* Sort the above created Linked List */
  mergesort(&a);
  
  printf("\n Sorted Linked List is: \n");
  printList(a);             
  return 0;
}