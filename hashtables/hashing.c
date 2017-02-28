#include <stdio.h>
#include <stdlib.h>
// define type nodes
#include "hashed.h"
int (*p[8]) (int x, dats y);
// doubt : assigning values to function pointers creates errros ? 

int main(){
	p[0]=&h1;p[1]=&h2;
	p[2]=&h3;p[3]=&h4;
	p[4]=&h5;p[5]=&h6;
	p[6]=&h7;p[7]=&h8;		
	return 0;	
}
