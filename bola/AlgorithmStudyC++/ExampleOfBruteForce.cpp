//
//  ExampleOfBruteForce.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 4. 27..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "ExampleOfBruteForce.hpp"


//코드 6.2 중첩 반복문 재귀로 대체하기. 재귀는 간단하고 직관적인 코딩이 가능하게 한다. 다만 성능과 좀 타협해야 한다.
//n개의 원소 중 m개를 고르는 모든 조합 찾기 및 출력. 다만, 원소는 각기 다른 정수
void pick4fromN(int n) {//반복
    //n개에서 r개를 고르는 조합 = n!/r!(n-r)!

    
    //코드도 길어질 뿐더러,
    //m개 만큼 for문이 생겨야한다. 그래서, 골라야 할 원수의 수가 입력에 따라 달라지는 경우 반복문으로는 사용할 수 없다.
    
    //여기는 0 ~ 7까지의 원소 중 4개를 고른다.
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                for(int l = k + 1; l < n; l++) {
                    printf("%d %d %d %d\n",i,j,k,l);
                }
            }
        }
    }
    
}

//완전 탐색의 예. 재귀는 완전 탐색을 구현 할 때 매우 좋다.
//m = 전체 원소 수 , n = 고를 원소 수, picked : 만들어지는 조합이 들어갈 벡터
void recursivePickMfromN(int m, int n, vector<int>& picked){ //재귀
    //1개를 고른다. 그리고 나머지는 다음의 자기 자신에게 넘겨버린다.
    
    //기저 사례. n개를 다 골랐으면 더 이상 문제를 쪼갤 필요가 없으므로, 고른 것들을 출력하고 종료한다.
    if(n == 0) {
        
        //모아놨던 조합을 출력한다.
        for(int a : picked) {
            printf("%d ", a);
        }
        printf("\n");
        return;
    }
    
    //고를 수 있는 가장 작은 원소를 고른다.
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    
    //원소를 1개 골라서 조합에 넣는다.
    for(int next = smallest; next < n; ++ next) {
        picked.push_back(next);
        recursivePickMfromN(m, n-1, picked);
        picked.pop_back(); //아까 골랐던 원소는 뺀다.
    }
    
    
}

void testExam2(){
    
    vector<int> picked;
    int n, m;
    
    printf("예제 2 번: m개의 원소 중 n개를 고르는 모든 조합 찾기 및 출력. \n");
    
    printf("반복문 : n 개에서 4개 고르는 조합 \n");
    pick4fromN(7);
    
    
    printf("재귀 : m개의 원소 중 n개를 고르는 모든 조합 찾기 및 출력.\n");
    scanf("%d %d", &m, &n);
    recursivePickMfromN(m, n, picked);
    
}

//코드 6.1 1 ~ n까지 합 구하기. for문과 재귀 함수로 각각 구현
//재귀로 구현한 1 ~ n까지 합 구하기
int recursiveSum(int n) {
    //1 부터 n을 1개씩 쪼개, 더할 각 숫자가 하나의 조각이 된다.
    
    // n = 1이면 마지막 조각이고, 더이상 쪼개어 지지 않는다. 쪼개어지지 않는 가장 작은 작업들을 기저 사례라고 한다.
    // 재귀 호출을 사용하는 경우, 이 기저 사례를 잘 처리해 줘야 한다. 기저 사례가 입력 될 경우를 처리하지 않으면 나중에 문제 생긴다.
    if(n == 1) {
    return 1;
    }
    
    //하나의 조각은 자신이 해결하고, 나머지는 자기자신을 호출해 해결.
    return n + recursiveSum(n-1);
}
//반복문으로 구현하기
int sum(int n) {
    int result = 0;
    for(int i = 1; i <= n ; i++) {
        result += i;
    }
    
    return result;
}

void testExam1() {
    int n = 0;
    
    printf("예제 1번 : 1 ~ n까지 합 구하기\n");
    scanf("%d", &n);
    
    printf("1 ~ %d 까지의 합 (재귀) : %d\n", n, recursiveSum(n));
    printf("1 ~ %d 까지의 합 (반복) : %d\n", n, sum(n));
    
}

void testAllExamples() {
    testExam1();
    testExam2();
}