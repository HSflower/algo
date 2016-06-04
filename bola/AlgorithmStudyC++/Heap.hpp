//
//  Heap.hpp
//  AlgorithmStudyC++
//
//  Created by 김윤철 on 2016. 6. 4..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#ifndef Heap_hpp
#define Heap_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


//definition of Heap
//1. keys should be over 0.
//2. heap is a complete binary tree
//3. the children should have lower priority than their parents.

//이 힙은 최대 힙이다. 나중에는 최소 힙으로 스위칭 할 수 있
class Heap {
    
    const int START_OF_BINARY_TREE = 1;
    
    private :
    vector<int> vector; //완전 이진 트리를 배열로 구현했어!
    
    public :
    
    Heap(); //포화이진트리를 배열로 나타내려면 맨 앞 하나는 더미 키를 넣어놔야 한다.
    //insert
    void insert(int n) ;
    //isEmpty
    bool isEmpty();
    //deleteHeap -- if heap is empty, returns 0. I couldn't use delete as a name becuase it's reserved by language itself.
    int deleteHeap();
    
    void printHeap();
    
    //heapify - every complete binary tree could be change into heap!
    //in my implementaion, It only take a comlete binary tree 
    static Heap* heapify();
    
};


void heapTest();

#endif /* Heap_hpp */
