//
//  Day15.hpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 5. 31..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#ifndef Day15_hpp
#define Day15_hpp

#include <stdio.h>
#include <iostream>
#include <cstddef>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

class Solution{
public:
    
    Node* insert(Node *head,int data)
    {
        //Complete this method
        
        //1. data를 이용해 새 노드를 만든다.
        Node *newNode = new Node(data);
        
        //2.넘겨받은 head를 이용해 현재 리스트의 끝까지 간다. head 자체가 NULL이면 그 자리에 집어넣고, 아니면 next가 NULL인 노드의 next에 새 노드를 넣는다.
        if(head == NULL) {
            head = newNode;
        }else {
            Node *presentNode = head; //현재 노드를 가리키는 포인터
            //다음 노드가 없는 노드, 즉 마지막 노드까지 이동한다.
            while(presentNode->next != NULL) {
                presentNode = presentNode->next;
            }
            //마지막 노드의 next에 새 노드를 추가한다.
            presentNode -> next = newNode;
        }
        
        return head; //제대로 리스트에 추가된 링크드리스트를 반납한다.
    }
    
    void display(Node *head)
    {
        Node *start=head;
        while(start)
        {
            cout<<start->data<<" ";
            start=start->next;
        }
    }
};

void day15();
#endif /* Day15_hpp */
