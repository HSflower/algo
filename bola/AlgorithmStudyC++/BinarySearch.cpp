//
//  BinarySearch.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 4. 13..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "BinarySearch.hpp"

//재귀를 이용한 이진 탐색 구현
int binarySearch(int a[], int start, int end, int key) {
    
    //배열의 중간 원소를 가져온다.
    int mid = ( start + end )/ 2;
    
    if((end - start) < 0) return -1; // 탐색 실패. 못 찾음
    
    //찾는 키가 중간 원소보다 크다면 중간 원소보다 작은 인덱스에서 이진 탐색을 수행한다.
    if(key > a[mid]) return binarySearch(a, mid + 1, end, key);
    //반대로 크다면 중간원소보다 큰 인덱스에서 이진 탐색을 수행한다.
    else if(key < a[mid]) return binarySearch(a, start, mid - 1, key);
    //찾았다면 그 위치를 반환한다. 정확히 하자면 그 원소와 위치를 동시에 반환해야겠지.
    else return mid;
}

void binarySearchTest() {
    
    int find[] = {1,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10};
    cout << binarySearch( find, 0, 10, 10) << endl;
    cout << binarySearch( find, 0, 10, 1) << endl;
    cout << binarySearch( find, 0, 10, 5) << endl;
    
    //경계값 테스트
    cout << binarySearch( find, 0, 10, 10) << endl;
    cout << binarySearch( find, 0, 10, 1) << endl;
    
    //예외가 발생할 경우 -- 존재하지 않는 원소 찾기
    cout << binarySearch( find, 0, 10, 2000) << endl;
    cout << binarySearch( find, 0, 10, -1) << endl;
}