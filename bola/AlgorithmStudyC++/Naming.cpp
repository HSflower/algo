//
//  Naming.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 4. 29..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "Naming.hpp"


//KMP의 접두사도 되고 접미사도 되는 알고리즘을 그대로 쓰면 된다.
vector<int> naming(const string& f, const string& m) {
    
    vector<int> results, pi;
    //1. 두 문자열을 합친 새로운 S만들기
    string s = f + m; //아버지와 어머니 이름을 합친다.
    pi = getPartialMatch(s);
    //접두사도 되고 접미사도 되는 부분 문자열 길이 배열 만들기
    
    //가장 긴, 자기 자신을 먼저 추가한다.
    int k = s.length();
    while(k > 0) {
        results.push_back(k);
        k = pi[k-1];
    }
    
    return results;
}

void namingTest() {
    
}