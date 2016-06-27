//
//  BinaryTree.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 5. 16..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "BinaryTree.hpp"

/*
 중위 순회
 */

void inOrder(node *root) {
        //왼쪽 서브트리 중위순회
        if(root->left != NULL) {
            inOrder(root->left);
        }
        //현재 노드 방문
        cout << root->data << " ";
        //오른쪽 서브트리 중위순회
        if(root->right != NULL) {
            inOrder(root->right);
        }
    
    
}

//스택을 사용하여 재귀 호출을 없앤 중위 순회
void inOrderWithoutRecursion(node *root) {
    //스택을 초기화한다.
    stack<node*> treversalStack = stack<node*>();
    //현재 노드를 가져온다.
    node* presentNode = root;
    
    if(root != NULL) {
        treversalStack.push(presentNode);
    }
    
    while(!treversalStack.empty()) {
        if(presentNode != NULL) {
            presentNode = treversalStack.top();
            
            //왼쪽 서브트리를 순회한다
            presentNode = presentNode->left;
            while(presentNode != NULL) {
                treversalStack.push(presentNode);
                presentNode = presentNode->left;
            }
        }
        
        //현재 노드 방문
        presentNode = treversalStack.top();
        cout << presentNode->data << " ";
        treversalStack.pop();
        
        //오른쪽 서브트리를 방문한다
        presentNode = presentNode->right;
        if(presentNode != NULL) {
            treversalStack.push(presentNode);
        }
    }
}

void inOrderTest() {
    node e = {6, NULL, NULL};
    node d = {4, NULL, NULL};
    node c = {1, NULL, NULL};
    node b = {2, &e, NULL};
    node a = {5, &c, &d};
    node root = {3, &a, &b};
    
    cout << "재귀 호출 : ";
    inOrder(&root);
    cout << endl;
    cout << "스택 사용 비재귀 : ";
    inOrderWithoutRecursion(&root);
}

/*
 후위순회
 */
//재귀 사용
void postOrder(node *root) {
    
    if(root != NULL) {
    //왼쪽 서브트리 순회
    if(root->left != NULL) {
        postOrder(root->left);
    }
    
    //오른족 서브트리 순회
    if(root->right != NULL) {
        postOrder(root->right);
    }
    
    //비로소 자신을 출력한다.
    cout << root->data << " ";
    }
    
    return;
}

//재귀 없이, 스택을 사용하여 이전 상태를 저장한 후위 순회
void postOrderWithoutRecursion(node *root) {
    //스택 초기화
    stack<node*> treversalStack = stack<node*> ();
    
    if(root != NULL) {
        treversalStack.push(root);
    } else {
        return;
    }
    
    
    node* node = treversalStack.top();
    
    
    
}

void postOrderTest() {
    node e = {6, NULL, NULL};
    node d = {4, NULL, NULL};
    node c = {1, NULL, NULL};
    node b = {2, &e, NULL};
    node a = {5, &c, &d};
    node root = {3, &a, &b};
    
    cout << "재귀 사용 : ";
    postOrder(&root);
    cout << "스택 사용 비재귀 : ";
    postOrderWithoutRecursion(&root);
}

//스택에 이전 내용을 저장함으로서 재귀호출을 없앤 전위 순회
void preOrderWithoutRecursion(node *root){
    
    //재귀 호출을 없애기 위한 스택
    stack<node*> treversalStack = stack<node*>();
    node* node = root;
    
    //루트가 비지 않았으면 우선 넣는다.
    if(node != NULL) {
        treversalStack.push(node);
    } else {
        return;
    }
    
    //거의 재귀호출과 흡사하다. 다만, 재귀는 이전 함수 호출에 이전에 방문한 노드가 저장된 반면, 여기서는 스택에 이전 방문 노드가 저장되는 것 뿐이다.
    while(!treversalStack.empty()){
        node = treversalStack.top();
        //루트 방문 확인
        cout << node->data << " ";
        treversalStack.pop();
        
        //노드의 오른쪽 서브트리를 조사한다. 스택의 순서 때문에, 나중에 나와야 하는 것 먼저 넣는 것이다.
        if(node -> right != NULL){
            treversalStack.push(node->right);
        }
        
        //자신의 왼쪽 서브트리를 조사한다.
        if(node -> left != NULL) {
            treversalStack.push(node -> left);
        }
    }
}


//재귀호출로 짠 전위 순회
void preOrder(node *root) {
    if( root != NULL && root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }
    else {
        
        //전위 순회이므로, 루트인 자신이 먼저 출력된다
        cout << root->data << " ";
        
        //왼자식
        if(root->left != NULL) {
            preOrder(root->left);
        }
        
        //오른자식
        if(root->right != NULL) {
            preOrder(root->right);
        }
        
        
    }
}

void preOrderTest() {
    node e = {6, NULL, NULL};
    node d = {4, NULL, NULL};
    node c = {1, NULL, NULL};
    node b = {2, &e, NULL};
    node a = {5, &c, &d};
    node root = {3, &a, &b};
    
    cout << "재귀 호출 : ";
    preOrder(&root);
    cout << endl;
    cout << "스택 사용 비재귀 : ";
    preOrderWithoutRecursion(&root);
}