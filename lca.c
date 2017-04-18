#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
int arr[100004];
typedef struct node{
    struct node *next;
    int vertex;    
}node;
char *names[100004];
int  child[100004];
int  parent[100004];
node *nodes[100004];
int pwr(int  a,int b,int  mod){
	if(b==0)
		return 1;
	int temp=pwr(a,b/2,mod);
	temp=(temp*temp)%mod;
	if(b&1)
		temp=(temp*a)%mod;
	return temp;
}
void traverse(){
	int x=hash("bin");
	node *p=nodes[x];
	while(p!=NULL){
		printf("%d ",(p->vertex));
		p=p->next;
	}
	printf("\n");
}
int hash(char* str){
	int m =100003;
	int p =503;
	int c;
	int hash=0;
	while(c = *str++){
		hash +=  pwr(p,c,m); 
		hash+=m;
		hash %=  m;
	}
	return hash;
}
int find(int a,int b){		
    if(nodes[a]==NULL || arr[a]==0 || arr[b]==0){
    	// printf("boom\n");
    	return 0;  
    }
    else{
        //go to end of the linked list
        node *p;
        p=nodes[a];
        while(p!=NULL){
            if(p->vertex==b){
            	return 1;
            }
            p=p->next;
        }
    	
    }
    return 0;
}
void insert(int a,int b){
    node *p,*q;
    q=(node*)malloc(sizeof(node));
    q->vertex=b;
    q->next=NULL;
		
    if(nodes[a]==NULL){
        // printf("newbie\n");
        nodes[a]=q;
    }
    else{
        //go to end of the linked list
        p=nodes[a];
        while(p->next!=NULL){
            if(p->vertex==b){
            	return;
            }
            p=p->next;

        }
        p->next=q;
    }
}
void parser_insert(char * str){
	char * dlmtrs = "/";
	char * runn  ;
	char * token ;
	runn =strdup(str);
	int cnt=1;
	int prev;
	while((token =strsep(&runn,dlmtrs))!=NULL ){
		int x,y;
		if(cnt==1)
			token="/";
		// printf("%s\n",token);
		x=hash(token);
		// printf("%d\n",x);
		if(!arr[x] && x!=0){
			arr[x]=1;
		}
		if(cnt!=1 && x!=0){
			insert(prev,x);
		}
		cnt++;
		prev=x;
	}
}



int parser_find(char * str){
	char * dlmtrs = "/";
	char * runn  ;
	char * token ;
	runn =strdup(str);
	int cnt=1;
	int prev;
	while((token =strsep(&runn,dlmtrs))!=NULL ){
		if(cnt==1)
			token="/";
		int x,y;
		// printf("%s\n",token);
		x=hash(token);
		// printf("%d\n",x);
		if(cnt!=1 && x!=0){
			y=find(prev,x);
			if(y==0){
				return 0;
			}
		}
		cnt++;
		prev=x;
	}
	return 1;
}



int main(){
	int n,c;
	scanf("%d",&c);
	while(c!=-1){
		if(c==1){
			scanf("%d",&n);
			while(n--){
				char * x = (char *)malloc(sizeof(char)*180);
				scanf("%s",x);
				parser_insert(x);
			}
			// printf("done\n");
		}				
		if(c==2){
			char * x = (char *)malloc(sizeof(char)*180);
			scanf("%s",x);
			if(parser_find(x)==1){
				printf("YES\n");
			}
			else{
				printf("NO\n");	
			}
		}	
		scanf("%d",&c);
	}
	// traverse();
}