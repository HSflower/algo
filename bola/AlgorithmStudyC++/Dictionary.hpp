//
//  Dictionary.hpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 5. 3..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>
#import <vector>
#import <string>
using namespace std;

//그래프
vector<vector<int>> adj;
//주어진 단어들로부터 알파벳 간의 선후관계 그래프를 생성한다
void makeGraph(const vector<string>& words);

//만든 그래프로 위상 정렬을 구현한다.

//위상정렬 구현용 깊이우선탐색
vector<int> seen, order;
void dfs(int here);

//위상정렬
vector<int> topologicalSort();

#endif /* Dictionary_hpp */
