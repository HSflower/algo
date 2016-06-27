//
//  ITES.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 4. 5..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "ITES.hpp"

/*
 • A[0] = 1983
 • A[i] = (A[i-1] * 214013 + 2531011) % 2의 32승
 이 때 i(1 <= i <= N)번째 입력 신호는 A[i-1] % 10000 + 1입니다. 문제의 해법은 입력을 생성하는 방식과는 아무 상관이 없습니다. 이 규칙에 따르면 첫 5개의 신호는 각각 1984, 8791, 4770, 7665, 3188입니다.
 */

//결국 나오는 수는 10000 이하. 그래서 int를 사용한다.
//이전 원소로 만들 수 있으므로, 덱에서 바로 직전 원소를 이용해 다음 값을 만든다. 는 안됨. 덱에 있는 것은 이미 후처리가 된 거다. 우리가 필요 한 건
//A[i]를 쌩으로 원하는 거라... 쟤는 따로 만들어 줘야 할 듯 하다. 아냐, %10000 + 1을 거꾸로 돌릴 수 있으면 되지 않나? 벗, 하우? *10000으로는 돌려놔지지 않음! 결국 어딘가에 직전 원소를 저장하게 만들었다.

//계산한 입력이 저장되는 덱
deque<int> dequeItes;
//A[i-1]을 저장하는 곳
unsigned long long int before;
const unsigned long long int twoThirtytwo = (UINT32_MAX + 1ULL);
const int firstItem = 1983; // A[0]

int inputGenerator() {
     //before = A[i-1]

    unsigned long long int result = 0ULL;
    result = (before * 214013ULL + 2531011ULL) % twoThirtytwo; // A[i]
    before = result;
    return (int)(result % 10000) + 1;
}

void inputGeneratorTest() {
    int numOfTestCase;
    cin >> numOfTestCase;
    
    before = firstItem;
    
    while(numOfTestCase > 0) {
        cout << inputGenerator() << endl;
        numOfTestCase--;
    }
}

void ites() {
    
    int numOfTestCases;
    unsigned long long int K, NItes;
    unsigned long long int patialSum = 0, result = 0;
    
    
    cin >> numOfTestCases;
    
    while(numOfTestCases > 0){
    
        //N과 K를 받는다.
        scanf("%llu %llu", &K, &NItes);
        
        //필요한 초기화 작업
        dequeItes.push_back(firstItem); // A[0] = 1983
        patialSum += firstItem;
        before = firstItem;
        
    //알고리즘 시작.
    while((NItes > 0) || (!dequeItes.empty())){
        
        while (patialSum < K) {
            
            //만약 N번째 까지 수열 전체가 나왔다면, 더 이상 추가하지 않는다. 바로 리턴한다.
            if(NItes <= 0) {
                break;
            }
            
            int value = inputGenerator();
            dequeItes.push_back(value);
            patialSum += value;
            NItes--;
        }
        
        
        //부분 수열의 합이 K와 같거나 큰 경우
        // K와 같은 경우
        if(patialSum == K) {
            result++; //모든 원소의 합이 K인 부분 수열 발견.
        }
        
        
        //머리를 떼낸다. 그리고 부분 수열에서도 제외하면서, 그 합에서도 제외한다.
        if(!dequeItes.empty()) {
            int removedValue = dequeItes.front();
            patialSum -= removedValue;
            dequeItes.pop_front();
        }
    }
    
        //결과를 출력한다.
        cout << result << endl;
        
        
    //다시 실행하기 위해서 초기화
        NItes = 0;
        K = 0;
        patialSum = 0;
        dequeItes.clear();
        result = 0;
        
        //반복회수 줄이기
        numOfTestCases--;
        
    }
    
    
}

