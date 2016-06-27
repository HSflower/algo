//
//  ExampleOfBruteForce.hpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 4. 27..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#ifndef ExampleOfBruteForce_hpp
#define ExampleOfBruteForce_hpp

#include <stdio.h>
#import <iostream>
#import <vector>
using namespace std;

//코드 6.2 중첩 반복문 재귀로 대체하기. 재귀는 간단하고 직관적인 코딩이 가능하게 한다. 다만 성능과 좀 타협해야 한다.
//n개의 원소 중 m개를 고르는 모든 조합 찾기 및 출력. 다만, 원소는 각기 다른 정수
void pick4fromN(int n); //반복. 반복 자체의 한계로 n개에서 4개 고르기 까지만 구현 가능
void recursivePickMfromN(int m, int n, vector<int>& picked); //재귀
void testExam2();

//코드 6.1 1 ~ n까지 합 구하기. for문과 재귀 함수로 각각 구현
int recursiveSum(int n);
int sum(int n);
void testExam1();

void testAllExamples();

#endif /* ExampleOfBruteForce_hpp */
