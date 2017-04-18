#include <stdio.h>
#include <stdlib.h>
#define  p(x) printf("%d ",&x)

typedef struct node{
	int val ;
	struct node * right;
	struct node * left;
}node;

void insert(int val, node ** root ){
	if((*root)==NULL){
		node * temp = (node *)malloc(sizeof(node));
		temp->val =val ;
		(*root)=temp ;
	}
	else if((*root)->val>val){
		if((*root)->left!=NULL){
			insert(val,&((*root)->left));
		}
		else{
			node * temp = (node *)malloc(sizeof(node));
			temp->val =val ;
			(*root)->left=temp;
		}
	}
	else{
		if((*root)->right!=NULL){
			insert(val,&((*root)->right));
		}
		else{
			node * temp = (node *)malloc(sizeof(node));
			temp->val =val ;
			(*root)->right=temp;
		}
	}
}

node * min_finder(node * root){
	if(root->left==NULL){
		return root;
	}
	return min_finder(root->left);
}

void delete(int val , node ** root){
	if((*root) == NULL) 
		return  ;

	else if(val < (*root)->val) 
		delete(val,&((*root)->left));
	
	else if (val > (*root)->val) 
		delete(val,&((*root)->right));
	
	else {		
		if((*root)->left == NULL && (*root)->right == NULL) { 
			free ((*root));
			(*root) = NULL;
		}
		else if((*root)->left == NULL) {
			node *temp = (*root);
			(*root) = (*root)->right;
			free (temp);
		}
		else if((*root)->right == NULL) {
			node *temp = (*root);
			(*root) = (*root)->left;
			free (temp);
		}
		else{ 
			node *temp = min_finder((*root)->right);
			(*root)->val = temp->val;
			delete(temp->val,&((*root)->right));
		}
	}
}

void inorder(node * root){
    if(root==NULL)
    	return ;
    if(root->left!=NULL)
    	inorder(root->left);
	
	printf("%d ",root->val);
	
	if(root->right!=NULL)
		inorder(root->right);
}

int main(){
	node * r =NULL ;	
	insert(11,&r);
	insert(12,&r);
	insert(10,&r);
	insert(9,&r);
	insert(1,&r);
	delete(11,&r);
	inorder(r);
}