#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
int arr[100004];
int main(){
	// node *root=(node *)malloc(sizeof(node));
	// root->name="/";
	// printf("%p\n",root);
	int n,c;
	scanf("%d",&c);

	while(c!=-1){
		printf("%d ",c);
		if(c==1){
			scanf("%d",&n);
			printf("%d\n",n);
			while(n--){
				char * x = (char *)malloc(sizeof(char)*500);

				scanf("%s",x);
				printf("%s\n",x);
				// parser_insert(root,x,ip);
			}
			// printf("done\n");
		}				
		if(c==2){
			char * x = (char *)malloc(sizeof(char)*500);
			char * ip = (char *)malloc(sizeof(char)*500);			
			scanf("%s %s",x,ip);
			printf("%s %s\n",x,ip);
			// parser_find(root,x);
		}	
		scanf("%d",&c);
	}

}
