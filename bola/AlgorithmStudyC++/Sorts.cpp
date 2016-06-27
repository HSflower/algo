//
//  Sorts.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 6. 26..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "Sorts.hpp"

//선택 정렬
/*
 5 3 4 1 2
 1 3 4 5 2
 1 2 4 5 3
 1 2 3 5 4
 1 2 3 4 5
 1 2 3 4 5
 */
int* selectionSort(int* array, int length) {
 
 
    
    
    for(int i = 0; i < length ; i++) {
        int indexOfMin = i;
        int min = array[i];
        
        //i번째 인덱스 이상에서 가장 작은 값 찿기
        for(int j = i + 1; j < length; j++) {
            
            if(min > array[j]) {
                min = array[j];
                indexOfMin = j;
            }
        }
        
        //자리 바꾸기
        int temp = array[i];
        array[i] = min;
        array[indexOfMin] = temp;
    }
    
    
    return array;
}

//버블 정렬
/*
  5 3 4 1 2
  3 5 4 1 2
  3 4 5 1 2
  3 4 1 5 2
  3 4 1 2 5
  3 4 1 2 5
  3 1 4 2 5
  3 1 2 4 5
  1 3 2 4 5 
  1 2 3 4 5
 */
int* bubbleSort(int* array, int length) {
    
    
    //뒤부터 정렬되기 시작하는 녀석이라 매번 정렬해야 할 길이가 1씩 줄어든다
    for(int i = length - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(array[j] > array[j + 1]) {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
    
    return array;
}

//삽입 정렬
/*
 5 3 4 1 2
 3 5 4 1 2
 3 4 5 1 2
 1 3 4 5 2
 1 2 3 4 5
 */
int* insertionSort(int* array, int length){
    
    //key의 원소보다 크다면 다 오른쪽으로 밀어버린다
    for(int i = 1; i < length; i++) {
        
        int key = array[i];
        int j = i;
        
        //조심! 메모리가 정리가 안 되어 있다면, j가 0보다 작을 때 돌아갈 수 도 잇다!
        while(array[j - 1] > key && j > 0) {
            array[j] = array[j - 1];
            j = j - 1;
        }

        array[j] = key;
    }
    
    return array;
}
//쉘 정렬
/*
 h-4 
 5 3 4 1 2 [5 1] -> [1 5]
 1 3 4 5 2
 h-1 일반 삽입정렬이랑 똑같음
 1 2 3 4 5
 
 멀리 떨어진 원소와의 교환이 가능하기 때문에 일반 삽입 정렬보다 빠르다고 함.
 */

int* shellSort(int* array, int length){
    
    // h(i) = h(i -1) * 3 + 1
    // h값을 감소시키면서 진행된다. h = h / 3
       //초기 h값을 계산
    int h = 1;
    while(h < length) {
        h = h * 3 + 1;
    }
    
    //각각의 h번째 배열 원소에 대해 삽입정렬 시도
    //h가 0보다 클 동안 h를 감소시켜 가며 반복
    for(; h > 0; h = h/3) {
        
        //h번째 앞에 있는 애들도 다 옮기긴 해야 하니까.
        for(int i = h; i < length; i++) {
            
            int key = array[i];
            int j = i;
            
            //j는 0 부터 length - 1까지 가능하기 때문이다. 난 인덱스가 0부터 시작하기 때문에, 피피티와는 많이 다를 수도 있다.
            while(j >= h && (array[j - h] > key) ) {
                array[j] = array[j-h];
                j = j - h;
            }
            
            array[j] = key;
        }
        
    }
    
    return array;
}


void sortTest() {
    
    int a[] = {5, 4, 1, 3, 2, 9, 8, 3};
    
    for(int i = 0; i < 8; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    shellSort(a, 8);
    
    for(int i = 0; i < 8; i++) {
    printf("%d ", a[i]);
    }
}
