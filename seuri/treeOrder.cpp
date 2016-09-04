#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

void btTraversal();
typedef struct treeNode{
	int data;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

int main(){
	btTraversal();
	return 0;
}

void btTraversal(){
	stack<treeNode*> nodeStack = stack<treeNode*>();
	treeNode d={5,NULL,NULL};
	treeNode c={4,NULL,NULL};
	treeNode b={3,NULL,NULL};
	treeNode a={2,&c,&d};
	treeNode r={1,&a,&b};

	treeNode* node = &r;

	if(node!=NULL){	
		nodeStack.push(node);
	}
	while(!nodeStack.empty()) {
		if(node!=NULL) {
			node = nodeStack.top();
			node = node->left;
			while(node!=NULL) {
				nodeStack.push(node);
				node = node->left;
			}
		}
		node=nodeStack.top();
		nodeStack.pop();
		cout << node->data;
		node = node->right;
		if(node!=NULL) {
			nodeStack.push(node);
		}
	}
	cin>>node->data;
}




