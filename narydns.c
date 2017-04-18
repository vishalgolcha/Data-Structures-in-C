#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
int arr[100004];
typedef struct node{
    struct node *next[400];
    char *name ;
    int vertex;    
    int id;
    char * ip;
}node;
node *nodes[100004];
node *traverse (node * x , char * y,char * ip ){
	int i;
	for(i=0;i<400;i++){
	 	if(x->next[i]==NULL){
		 	x->next[i] =(node *)malloc(sizeof(node));
			x->next[i]->name = y;
			x->next[i]->ip=ip;
			x->next[i]->id=i;
			return x->next[i];
		}
		else if(strcmp(x->next[i]->name,y)==0){    // made the same mistake here 
			return x->next[i];
		}
	}
}
void tracel(node *x){
	int i;
	for(i=0;i<400;i++){
	 	if(x->next[i]==NULL){
			return ;
		}
		else{
			printf("%s\n",x->next[i]->name);
		}
	}
}
node *find (node * x , char * y){
	int i;
	// 	else if(x->next[i]->name==y){  // this is totally wrong
	// 		return x->next[i];
	// 	}
	// comparing pointers not working // remember chutiyap kar sakta h ye
	
	i=0;
	while(x->next[i]!=NULL){
		char * a = x->next[i]->name ;
		// printf("%s %d \n",a,x->next[i]->id);
		if(strcmp(a,y)==0){
			// printf("id %d\n",x->next[i]->id);
			return x->next[i];
		}
		i++;
	}
	return NULL;
	// printf("%d\n",i);
}
void parser_find(node * root ,char * str){
	char * dlmtrs = ".";
	char * runn  ;
	char * token ;
	runn =strdup(str);
	int cnt=0;
	int prev;
	char *temp[500];
	char *temp2[500];
	while((token =strsep(&runn,dlmtrs))!=NULL ){
		temp[cnt]=token;
		cnt++;
		// prev=x;
	}
	int i,j;
	// printf("printing reversed orderd\n");
	for(i=0,j=cnt-1;i<cnt,j>=0;i++,j--){
		temp2[i]=temp[j];
		// printf("%s\n",temp2[i]);

	}
	int child[1000];
	for(i =0;i<cnt;i++){
		root=find(root,temp2[i]);

		if(root==NULL ){
			// printf("%s\n",root->name);
			int k;
			for(k=i-1;k>=0;k--){
				printf("%d ",child[k]);
			}
			printf("\n");
			return ;
		}
		else {
			// printf("%d\n",root->id);
			if(root->ip!=NULL){
		
				printf("%s\n",root->ip);
				return ;	

			}
			child[i]=root->id;
		}
	}
	// printf("YES\n");
	// return ;
}

void parser_insert(node * root ,char * str,char *ip){
	char * dlmtrs = ".";
	char * runn  ;
	char * token ;
	runn =strdup(str);
	int cnt=0;
	int prev;
	char *temp[500];
	char *temp2[500];
	// token =strsep(&runn,dlmtrs);
	// temp[0]="/";
	// node * last=traverse(root,temp[0]);
	while((token =strsep(&runn,dlmtrs))!=NULL ){
		temp[cnt]=token;
		cnt++;
		// prev=x;
	}
	int i,j;
	for(i=0,j=cnt-1;i<cnt,j>=0;i++,j--){
		temp2[i]=temp[j];
	}
	for(i =0;i<cnt;i++){
		if(i==cnt-1)
			root = traverse(root,temp2[i],ip);
		else
			root = traverse(root,temp2[i],NULL);
		// printf("%p\n",root);
	}
}
int main(){
	node *root=(node *)malloc(sizeof(node));
	root->name="/";
	// printf("%p\n",root);
	int n,c;
	scanf("%d",&c);
	while(c!=-1){
		if(c==1){
			scanf("%d",&n);
			while(n--){
				char * x = (char *)malloc(sizeof(char)*500);
				char * ip = (char *)malloc(sizeof(char)*500);
				scanf("%s %s",x,ip);
				parser_insert(root,x,ip);
			}
			// printf("done\n");
		}				
		else if(c==2){
			char * x = (char *)malloc(sizeof(char)*500);
			scanf("%s",x);
			// tracel(root);
			parser_find(root,x);
		}	
		scanf("%d",&c);
	}
}
