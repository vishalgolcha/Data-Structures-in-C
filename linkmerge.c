#include <stdio.h>
#include "linkedlist.h"

void merge(node* one, node* two){
	if(two==NULL){
		return;
	}
	else{
		node* temp = delt() 
	}
}
void split(node *head , int sz){
	if(sz==1)
		return ;
	else{
		node * two = head;
		int cnt=0;
		while( cnt<=(sz>>1) ){
			two=two->next;
			cnt++;
		}
		split(two,sz-(sz>>1));
		merge(head,two);
	}
}