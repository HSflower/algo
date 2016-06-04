//
//  Heap.cpp
//  AlgorithmStudyC++
//
//  Created by 김윤철 on 2016. 6. 4..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "Heap.hpp"

Heap::Heap() {
    vector.insert(vector.begin(), 0);
    //이진 트리를 배열로 구현하기 위해서 맨 앞에 더미 키를 넣는다.
    //넣는 이유는, 배열의 인덱스로 부모와 자식을 찾을 때, 트리가 인덱스 0부터 시작하면 인덱스로 부모 자식을 찾기 쉽기 때문이다.

}

//O(N)
void Heap::insert(int n) {
    
    if(n <= 0) {
        cout << "You cannot insert <= 0" << endl;
        return;
    }
    
    if(this->isEmpty()) {
        vector.push_back(n);
        return;
    }
    
    
    //우선 배열에 맨 끝에 넣은뒤, 우선순위에 맞춰서 이동한다.
    //여기서 우선순위는 키의 크기이다.
    vector.push_back(n);
    int parentIndex = (vector.size() - 1) / 2;
    int index = vector.size() - 1;
    
    
    while(index > START_OF_BINARY_TREE) {
        
        if(vector[parentIndex] < n ){
            int parent = vector[parentIndex];
            vector[index] = parent;
            vector[parentIndex] = n;
            
            index = parentIndex;
            parentIndex = index / 2;
        }else {
            //새로 추가된 값이 현재의 부모보다 작거나 같다면 반복을 종료한다.
            break;
        }
        
    }
}

//isEmpty
bool Heap::isEmpty(){
    return vector.size() <= 1;
}

//deleteHeap
// O(logN)
//왜 logN이냐면, 트리의 구조 때문이다. 배열로 표현되어 있긴 하지만, 실제로는 이진 트리이므로, 비교하는 건 logN번 뿐이다.
int Heap::deleteHeap() {
    
    if(this->isEmpty()) {
        cout << "heap is empty!" << endl;
        return 0;
    }
    
    //힙에 한 개의 원소만 있다면 그것만 반환하고 끝낸다.
    if(vector.size() == 1) {
        vector.pop_back();
        return vector.back();
    } else if(vector.size() < 1) {
        cout << "Heap is empty" << endl;
        return 0;
    }
    
    
    //반환할 값을 미리 꺼내 놓는다.
    int result = vector[START_OF_BINARY_TREE]; //heap's deletion is always happenend from its head!
    
    
    //맨 마지막 원소를 루트로 올린 뒤, 자식과 비교해 우선순위가 자식보다 작으면 아래로 내려간다.
    int last = vector.back();
    
    vector[START_OF_BINARY_TREE] = last;
    vector.pop_back();
    //삭제로 인해 힙의 루트 원소가 없어졌다. 다시 힙으로 돌아오기 위한 재구축 과정
    int index = START_OF_BINARY_TREE; //루트로 올라간 맨 마지막 원소가 힙을 재구축하는 솨정에서 최종적으로 들어갈 자리
    
    int leftChild = index * 2;
    int rightChild = index * 2 + 1;
    
    while(index < vector.size()) {
        
        leftChild = index * 2;
        rightChild = index * 2 + 1;
        
        //말단 노드까지 내려오면 종료한다.
        if(leftChild > vector.size() || rightChild > vector.size()) {
            break;
        }
        
        //두 자식 중 큰 노드와 키를 비교, 큰 노드와 자리를 바꾼다. 그 큰 노드도 부모보다는 큰 값을 가지고 있어야 한다.
        if(vector[leftChild] > last || vector[rightChild] > last) {
            
            if(vector[leftChild] > vector[rightChild] ) {
                int temp = vector[index];
                vector[index] = vector[leftChild];
                vector[leftChild] = temp;
                
                index = leftChild;
                
                
            } else{
                int temp = vector[index];
                vector[index] = vector[rightChild];
                vector[rightChild] = temp;
                
                index = rightChild;
            }
        }
        else {
            //만약 두 자식 노드 둘 다 부모(삭제 직전에는 힙의 마지막 원소) 노드보다 작다면, 맞는 장소에 있는 것이다.
            break;
        }
        
    }
    
    
    
    
    return result;
    
    
}

void Heap::printHeap() {
    
    for( int i : vector ){
        if(i != 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

//heapify - every complete binary tree could be change into heap!

//heap test
void heapTest() {
    Heap h = Heap();
    
    //insertion test
    h.insert(1); // 1
    h.insert(3); // 3 1
    h.insert(2); // 3 1 4 -> 4 1 3
    h.insert(3); // 4 1 3 5 -> 4 5 3 1 -> 5 4 3 1
    h.insert(8);
    h.insert(7);
    h.insert(10);
    h.insert(9);
    //
    h.printHeap(); //should print
    
    //delete
    int result = 0;
    while(!h.isEmpty()) {
        result = h.deleteHeap();
        cout << "the deleted is " <<result << " " << endl;
        h.printHeap();
    }
    
    
    //case 1 : try to delete heap when it is empty
    
    
    
    
    
}


