//
//  Day16.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 6. 2..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

/*
 Day 16 : Exception Handling
 스위프트의 에러 처리, 특히 문제에서 요구하는 문자열 - 정수 변환은 그저 옵셔널 언래핑으로만 할 수 있다.
 if문을 사용하지 않고는 try를 사용할 수 없었다. 
 그러나, 문제의 요건은 사용하는 언어의 라이브러리에 존재하는 문자열 - 정수 변환 함수를 사용할 것을 명시했고, 또한 어떠한 조건문, 반복문을 사용하지 않는 것이기 때문에 어쩔수 없이 C++로 문제를 풉니당.
 
 */

#include "Day16.hpp"

void day16(){
    
    string s;
    int i;
    cin >> s;
    
    try {
        i = stoi(s);
        printf("%d\n" , i);
    }
    catch(exception e) {
        printf("Bad String\n");
    }
}
