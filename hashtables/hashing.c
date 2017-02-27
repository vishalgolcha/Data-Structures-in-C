#include <stdio.h>
#include <stdlib.h>
// define type nodes
#include "hashed.h"
int h1(int tlen,dats x){
	int sum=0;
	int i=0;
	for(i=0;i<8;i++){
		sum += x.name[i];
	}
	sum%=89;
	return sum%tlen;
}
int h2(int tlen,dats x){
	int sum=0;
	int i=0;
	for(i=0;i<8;i++){
		sum+=x.name[i];
	}
	sum%=105943;
	return sum%tlen;
}
int h3(int tlen,dats x){
	int sum=0;
	int i;
	for(i=0;i<8;i++){
		sum+=x.name[i];
	}
	sum%=89;
	return sum%tlen;	
}
int h4(int tlen,dats x){
	int sum=0;
	int i;
	for(i=0;i<8;i++){
		sum+=x.name[i];
	}
	sum%=105943;
	return sum%tlen;	
}
int h5(int tlen,dats x){
	int sum=x.id;
	sum%=89;
	return sum%tlen;
}
int h6(int tlen,dats x){
	int sum=x.id;
	sum%=105943;
	return sum%tlen;
}
int h7(int tlen,dats x){
	int sum=x.id;
	sum%=89;
	return sum%tlen;
}
int h8(int tlen,dats x){
	int sum=x.id;
	sum%=105943;
	return sum%tlen;
}
int (*p[8]) (int x, dats y)={h1,h2,h3,h4,h5,h6,h7,h8};
int main(){	
	
	return 0;	
}