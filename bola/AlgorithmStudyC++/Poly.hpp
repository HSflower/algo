//
//  Poly.h
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 3. 31..
//  Copyright © 2016년 bolastudy. All rights reserved.
//



#ifndef Poly_hpp
#define Poly_hpp

#include <stdio.h>
#include <iostream>

void test();
int polyTest(int n) ;
int poly(int n, int first);

const int MOD = 10 * 1000 * 1000; //폴리오미노의 수가 10,000,000 이상일 경우 10,000,000으로 나눈 나머지를 출력합니다.

int cachePoly[101][101]; //동적 계획법을 위한 캐시. 각 줄에 폴리오미노를 구성할 정사각형의 수 n (1≤n≤100)이 주어집니다. 최대 크기의 사각형까지 다루기 위해서 크기가 저 모양임.
//여기에 모든 계산의 값의 기록되어, 나중에 중복되는 부분 문제의 계산값이 필요한 경우 여기서 꺼내 쓴다.
#endif /* Poly_h */
