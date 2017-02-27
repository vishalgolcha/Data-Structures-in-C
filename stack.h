#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	struct node * next;
	int element;
} node;

typedef struct stacked{
	node * first;
	int count;
} stacked;

void push(stacked *head, int ele);
int pop(stacked *head);
void print_list(stacked * head);