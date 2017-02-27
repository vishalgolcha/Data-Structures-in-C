#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	struct node * next;
	int element;
} node;

typedef struct ll{
	node * first;
	int count;
} ll;

void push(ll *head, int ele);
node *pop(ll *head);
void print_list(ll * head);
int search(ll *head, int ele);
node *delt(ll *head , int ele);
void insert(node *ptr, int ele);
void sinsert(ll *head, int ele)