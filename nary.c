#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
int arr[100004];
typedef struct node{
    struct node *next[180];
    char *name ;
    int vertex;    
}node;
node *nodes[100004];
node *traverse (node * x , char * y){
	int i;
	for(i=0;i<180;i++){
	 	if(x->next[i]==NULL){
		 	x->next[i] =(node *)malloc(sizeof(node));
			x->next[i]->name = y;
			// printf("%s\n","created" );
			// printf("%p\n",(x->next[i]));
			return x->next[i];
		}
		else if(strcmp(x->next[i]->name,y)==0){    // made the same mistake here 

			return x->next[i];
		}
	}
}
void tracel(node *x){
	int i;
	for(i=0;i<180;i++){
	 	if(x->next[i]==NULL){
			return ;
		}
		else{
			printf("%p\n",&(x->next[i]));
		}
	}
}
node *find (node * x , char * y){
	int i;
	// printf("%s\n",y);
	// for(i=0;i<180;i++){
	//  	if(x->next[i]==NULL){
	// 		printf("%s\n",x->name);
	// 		return NULL;
	// 	}
	// 	else if(x->next[i]->name==y){
	// 		return x->next[i];
	// 	}
	// }
	i=0;
	// comparing pointers not working // remember chutiyap kar sakta h ye
	
	while(x->next[i]!=NULL){
		char * a = x->next[i]->name ;
		char * b = y;
		// printf("%s\n",a);
		if(strcmp(a,b)==0){
			return x->next[i];
		}
		i++;
	}
	return NULL;
	// printf("%d\n",i);
}
void parser_find(node * root ,char * str){
	char * dlmtrs = "/";
	char * runn  ;
	char * token ;
	runn =strdup(str);
	int cnt=0;
	int prev;
	char *temp[200];
	token =strsep(&runn,dlmtrs);
	// temp[0]="/";
	// node * last=traverse(root,temp[0]);
	while((token =strsep(&runn,dlmtrs))!=NULL ){
		temp[cnt]=token;
		cnt++;
		// prev=x;
	}
	int i;
	// printf("%d\n",cnt);
	for(i =0;i<cnt;i++){
		root=find(root,temp[i]);	
		if(root!=NULL){
			;// printf("%s\n",root->name);
		}
		else{
			printf("NO\n");
			return ;
		}
	}
	printf("YES\n");
	return ;
}

void parser_insert(node * root ,char * str){
	char * dlmtrs = "/";
	char * runn  ;
	char * token ;
	runn =strdup(str);
	int cnt=0;
	int prev;
	char *temp[200];
	token =strsep(&runn,dlmtrs);
	// temp[0]="/";
	// node * last=traverse(root,temp[0]);
	while((token =strsep(&runn,dlmtrs))!=NULL ){
		temp[cnt]=token;
		cnt++;
		// prev=x;
	}
	int i;
	for(i =0;i<cnt;i++){
		root = traverse(root,temp[i]);	
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
				char * x = (char *)malloc(sizeof(char)*180);
				scanf("%s",x);
				parser_insert(root,x);
			}
			// printf("done\n");
		}				
		if(c==2){
			char * x = (char *)malloc(sizeof(char)*180);
			scanf("%s",x);
			parser_find(root,x);
		}	
		scanf("%d",&c);
	}

	// char* addr ="/root/dev/bin";
	// char* addr2="/root/dev/bind";
	// char* addr3="/root/dev/bindi";
	// parser_insert(root,addr2);
	// parser_insert(root,addr);
	// parser_find(root,addr3);
	// tracel(root);
}
