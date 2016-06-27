//
//  BinaryTree.hpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 5. 16..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

/*
 해커랭크 문제 풀이가 포함되어 있습니다
 https://www.hackerrank.com/challenges/tree-preorder-traversal
 
 
 */

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#import <stdio.h>
#import <iostream>
#import <stack>
using namespace std;

//해커랭크 제공 트리 노드
struct node
{
    int data;
    node* left;
    node* right;
};

//스레드 이진 트리를 위한 노드. 스레드 이진 트리는 자식이 없는 경우, 자리가 빈 자식 노드 링크에 '스레드' 개념으로, 오른쪽이 빌 경우, 다음 순회에 방문할 노드(후속자라고 함), 왼쪽이 빌 경우 이전에 방문한 노드(선행자)의 주소를 넣는다.(물론 어떤 순회를 하느냐에 따라 넣을 노드는 달라진다.) (물론, 여기서 기준은 무조건 왼쪽 서브트리를 방문하는 순회의 예다. 중위여도, 후위여도 왼쪽 서브트리부터 받는 경우)예를 들어, 중위 순회 노드에서 오른쪽 자식이 없는 노드의 경우, 오른쪽 자식 링크에 이 다음 자신의 방문 노드, 자신의 부모 노드가 들어있다.
struct threadNode{
    int data;
    node* left;
    bool lt; //이것이 스레드인가 자식인가 여부. true면 스레드
    node* right;
    bool rt;
};

/*
 후위순회
 */
void postOrder(node *root);
void postOrderWithoutRecursion(node *root);
void postOrderTest();

void postOrderForThreadTree(threadNode *root);
void postOrderWithoutRecursionForThreadTree(threadNode *root);
void postOrderTestForThreadTree();
/*
 중위 순회
 */
void inOrder(node *root);
void inOrderWithoutRecursion(node *root); //스택을 사용해 재귀 제거
void inOrderTest();

void inOrderForThreadTree(threadNode *root);
void inOrderWithoutRecursionForThreadTree(threadNode *root);
void inOrderTestForThreadTree();

/*
 전위 순회
 */
void preOrder(node *root); //재귀를 사용한 전위 순회
void preOrderWithoutRecursion(node *root); //스택을 이용해서 재귀호출을 없앰
void preOrderTest();

void preOrderForThreadTree(threadNode *root);
void preOrderWithoutRecursionForThreadTree(threadNode *root);
void preOrderTestForThreadTree();

#endif /* BinaryTree_hpp */
