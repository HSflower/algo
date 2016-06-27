//
//  Palindromize.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 4. 29..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "Palindromize.hpp"


int palindromize(const string& a, const string& b) {

    //a의 접두사면서 b의 접미사 인 녀석을 찾으면 된다.
    //KMP 알고리즘의 접두사 & 접미사 찾기를 응용한다.
    
    int n = a.length();
    int m = b.length();
    vector<int> pi = getPartialMatch(b);//거꾸로 뒤집은 문자열의 접미사도 되고 접두사도 되는 문자열의 최고 길이를 알아놓는다.
    
    //begin = matched = 0에서 시작한다
    int begin = 0;
    int matched = 0;
    
    while(begin < n) {
        //만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
        if(matched < m && a[begin + matched] == b[matched]) {
            matched++;
            if(begin + matched == n) {
                return matched;
            }
        }
        else {
            if(matched == 0) {
                begin++;
            }
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return 0;
}


void palindromizeTest() {
    
}