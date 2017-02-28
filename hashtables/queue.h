#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node * next;
	int element;
	int counter;
} node;

typedef struct queued{
	node * first;
	node * rear;
	int count;
} queued;

void queue_add(queued *head, int ele);
node* queue_rem(queued *head);
void print_list(queued * head);
node * search(queued *head,int ele);
