//
//  StringAlgorithm.hpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 4. 29..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#ifndef StringAlgorithm_hpp
#define StringAlgorithm_hpp

#include <stdio.h>
#import <vector>
#import <iostream>
using namespace std;

//문자열 검색
//H : N을 찾아야 하는 문자열 (HayStack이라고 부른다고 함)
//N : 검색할 문자열 (Needle) -- 짚더미에서 바늘 찾기!

//코드 20. 1 단순한 문자열 검색 알고리즘 (almost brute-force)
vector<int> naiveSearch(const string& H, const string& N);
void naiveSearchTest();


//코드 20.2 KMP 알고리즘 (어려워! :( )
//핵심은 매치된 문자열의 길이를 사용하여 다음 시작 위치를 구한다는 것.
//그리고 그 과정에서  접두사 - 접미사 최대 일치 문자열 길이가 쓰인다는 것!
vector<int> getPartialMatchNaive(const string N);
vector<int> getPartialMatch(const string N); //다음 시작 위치 계산한 배열 반환. KMP 사용
vector<int> KMPSearch(const string& H, const string& N);
void KMPSearchTest();

//코드 20.7 KMP의 다른 구현
vector<int> kmpSearch2(const string& H, const string& N);

void testAll();
#endif /* StringAlgorithm_hpp */
