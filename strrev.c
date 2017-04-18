#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
int arr[100004];
typedef struct node{
    struct node *next;
    int vertex;
    char * ip;    
    int id;
}node;
node *nodes[100004];
char *names[100004];

int pwr(int  a,int b,int  mod){
	if(b==0)
		return 1;
	int temp=pwr(a,b/2,mod);
	temp=(temp*temp)%mod;
	if(b&1)
		temp=(temp*a)%mod;
	return temp;
}

int hash(char* str){
	int m =100003,p =503,c;
	int hash=0;
	while(c = *str++){
		hash +=  pwr(p,c,m); 
		hash+=m;
		hash %=  m;
	}
	return hash;
}

void insert(int a,int b,char *ip ){
    node *p,*q;
   
    q=(node*)malloc(sizeof(node));
    q->vertex=b;
    q->ip=ip;
    q->next=NULL;
	
    if(nodes[a]==NULL){
        // printf("newbie\n");
        q->id=0;
        nodes[a]=q;	
    }
    else{
    	int cnt=0;
        p=nodes[a];
        while(p->next!=NULL){
            if(p->vertex==b){
            	return;
            }
            p=p->next;
            cnt++;
        }
        q->id=cnt;
        p->next=q;
    }
}

void parser_insert(char * str,char * ip){
	char * dlmtrs = ".";
	char * runn  ;
	char * token ;
	runn =strdup(str);
	int cnt=1,prev;
	char * temp[200];
	char * temp2[200];
	int num=1;
	char * root = "/";
	char * ender = "//"
	temp[0]=ender;
	while((token =strsep(&runn,dlmtrs))!=NULL ){
		temp[num]=token;
		num++;
	}
	temp[num]= root;
	int i,j;
	for(i=0,j=num;i<=num,j>=0;i++,j--){
		temp2[i]=temp[j];
		printf("%s\n",temp2[i]);
	}
	for(i=0;i<num;i++){
		names[hash(temp2[i])]=temp2[i];
		names[hash(temp2[i+1])]=temp2[i+1];
		if(hash(temp2[i+1])==hash("//")){
			insert(hash(temp2[i]),hash(temp2[i+1]),ip);
		}
		else{
			insert(hash(temp2[i]),hash(temp2[i+1]),NULL);
		}
	}

}
node * find(int a,int b){		
    node *p=NULL;

    if(nodes[a]==NULL){
    	return NULL;  
    }
    else{
        p=nodes[a];
        while(p!=NULL){
            if(p->vertex==b){
            	return p;
            }
            p=p->next;
        }
    	
    }
    return nodes[a];
}
void parser_find(char * str){
	char * dlmtrs = ".";
	char * runn  ;
	char * token ;
	runn =strdup(str);
	int cnt=1,prev;
	char * temp[200];
	char * temp2[200];
	int num=0;
	while((token =strsep(&runn,dlmtrs))!=NULL ){
		temp[num]=token;
		num++;
	}
	int i,j;
	for(i=0,j=num-1;i<num,j>=0;i++,j--){
		temp2[i]=temp[j];
		printf("%s\n",temp2[i]);
	}
	int seq[200];
	int cnt=0;
	node *x ;
	for(i=0;i<num-1;i++){
		x=find(hash(temp2[i]),hash(temp2[i+1]));
		if(x==NULL){
			break;
		}
		else if(x->ip==NULL){
			seq[cnt]=x->id;
			cnt++;
		}
	}
	if(x->ip==NULL){

	}
}
int main(){
	char *j ="swd.bits-pilani.ac.in";
	parser_insert(j,"123.123.123.0");

}