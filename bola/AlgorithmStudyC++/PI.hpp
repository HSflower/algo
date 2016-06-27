//
//  PI.hpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 3. 31..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#ifndef PI_hpp
#define PI_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

int memorize(int begin);
int classify(int a, int b);

const int INF = 987654321;
string N;

//메모이제이션을 위한 버퍼
int cache[10002];
#endif /* PI_hpp */
