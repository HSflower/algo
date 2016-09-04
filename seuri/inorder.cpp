#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct treeNode{
	int data;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

//void createBT();
void inorder(treeNode* T);
void preorder(treeNode* T);
void postorder(treeNode* T);
/*
int main(){
	//creatBT();
	treeNode d={5,NULL,NULL};
	treeNode c={4,NULL,NULL};
	treeNode b={3,NULL,NULL};
	treeNode a={2,&c,&d};
	treeNode r={1,&a,&b};	
	cout<<"inorder: ";
	inorder(&r);
	cout<<"\npreorder: ";
	preorder(&r);
	cout<<"\npostorder: ";
	postorder(&r);
	cin>>r.data;
	return 0;
}
/*
void creatBT(){

	return 0;
}
*/
void inorder(treeNode* T){
	if(T!=NULL){
		if(T->left!=NULL)	inorder(T->left);
		cout << T->data;
		if(T->right!=NULL)	inorder(T->right);
	}
}

void preorder(treeNode* T){
	if(T!=NULL){
		cout<<T->data;
		if(T->left!=NULL)	preorder(T->left);
		if(T->right!=NULL)	preorder(T->right);
	}
}

void postorder(treeNode* T){
	if(T!=NULL){
		if(T->left!=NULL)	postorder(T->left);
		if(T->right!=NULL)	postorder(T->right);
		cout<<T->data;
	}
}