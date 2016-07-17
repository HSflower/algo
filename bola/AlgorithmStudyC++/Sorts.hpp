//
//  Sorts.hpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 6. 26..
//  Copyright © 2016년 bolastudy. All rights reserved.
//


/*
 정렬 유틸리티들. 만약 정렬을 해야하는 일이 있다면 여기서 꺼내 쓰면 됨
 만일 필요하다면 타입을 바꿔서 사용하면 됨
 모든 정렬은 오름차순을 기본으로 함.
 
 나중에 Generic과 비교함수를 받는 형식으로 만든다면 사용성이 높아질 것임:)
 */


#ifndef Sorts_hpp
#define Sorts_hpp

#include <stdio.h>
#import <iostream>
#include <stack>
using namespace std;

//선택 정렬
int* selectionSort(int* array, int length);

//버블 정렬
int* bubbleSort(int* array, int length);

//삽입 정렬
int* insertionSort(int* array, int length);
//쉘 정렬
int* shellSort(int* array, int length);

//퀵 정렬 -- 재귀
int* quickSortRecursive(int* array, int l, int r);
int partition(int* array ,int l, int r); //파티션 함수. 다음에 돌릴 피봇의 인덱스를 반환
//퀵 정렬 -- 스택으로 재귀 제거
int*  quickSortStack(int* a, int l, int r);

//합병 정렬 -- 재귀
int* mergeSort(int* array, int l, int r);
void merge(int* array, int l, int m, int r);
//자연 합병 정렬 - 런을 나눌 때, 나눈 런이 부분적이나마 순서를 가지고 있다면
int* naturalMergeSort(int* array, int l, int r);

//힙 정렬
int* heapSort(int *array, int length);
int* heapify(int* array, int h, int m);

void sortTest();

#endif /* Sorts_hpp */
