//
//  FIBONACCI.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 4. 12..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "FIBONACCI.hpp"

 /*
 재귀를 공부하기 위해서 짠 코드입니다. 
 그 중 피보나치를 짜 봅니다.
 */

//재귀 호출로 짠 피보나치 수열 발생기

//피보나치 수열의 정의
// F(0) = 0, F(1 || 2) = 1, F(N) = F(N-1) + F(N-2)

int fibonacci(int n) {
    
    if (n <= 0) {
        return 0;
    }
    else if (n == 1 || n == 2) {
        return 1;
    }
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}


//반복문으로 최적화한 피보나치
int fibonacciRepeat(int n) {
    
    int next = 0; // f(n)
    int before = 1, after = 1; // f(n-1), f(n-2)
    
    if (n <= 0) return 0;
    else if (n == 1 || n == 2) return 1;
    
    for(; n > 2 ; n--) {
        next = before + after; //f(n) = f(n-1) + f(n-2)
        before = after;
        after = next;
    }
    
    return next;
}

//피보나치의 n번째 원소를 반환한다.
void fibonacciTest() {
    int n = 0;
    cout << "피보나치의 N번째 원소를 반환합니다. N을 입력해주세요!" << endl;
    cin >> n;
    cout <<  n << "번째 원소는 " << fibonacciRepeat(n) << "입니다." << endl;
}

//n까지의 피보나치 수열을 보여준다.
void fibonacciSequenceTest() {
    int n = 0;
    cout << "피보나치 수열의 0부터 N번째 원소까지의 배열을 반환합니다. N을 입력해주세요!" << endl;
    cin >> n;
    for(int i = 0; i <= n ; i++) {
    cout <<  fibonacciRepeat(i) <<  " ";
    }
    cout << endl;
}

