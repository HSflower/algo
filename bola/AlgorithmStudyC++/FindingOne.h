//
//  FindingOne.h
//  AlgorithmStudyC++
//
//  Created by 김윤철 on 2016. 6. 28..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#ifndef FindingOne_h
#define FindingOne_h

#include <stdio.h>
#include <iostream>
using namespace std;


//const로 선언하면 변경할 수 없다! 주의!
static int* memoFindingOne;

int findingOne(int n);
int min(int x, int y, int z);
void findingOneTest();
#endif /* FindingOne_h */
