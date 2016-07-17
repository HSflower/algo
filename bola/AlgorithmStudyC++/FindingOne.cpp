//
//  FindingOne.cpp
//  AlgorithmStudyC++
//
//  Created by 김윤철 on 2016. 6. 28..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "FindingOne.h"

int min(int x, int y, int z) {
    return x <= y ? (x <= z ? x : z) : (y <= z ? y : z);
}


//TOP - DOWN
//재귀 호출의 한계가 여실히 드러난다.
//xcode에서는 10^6의 경우를 돌리지를 못한다.
int findingOne(int n) {
    
    if(n < 1) {
        return 0; //정답 중 0이 있을 수 있으니, -1로 초기화
    }
    
    if(memoFindingOne[n] > -1) {
        return memoFindingOne[n];
    }
    else {
        //memo[N] = min{min[N]}
        memoFindingOne[n] = min(
                                n % 3 == 0 ? findingOne(n/3): INT_MAX,
                                n % 2 == 0 ? findingOne(n/2): INT_MAX,
                                findingOne(n-1)
                                ) + 1;
    }
    
    return memoFindingOne[n];
}


//Bottom UP
int findingOneBU(int n) {
    
    memoFindingOne[1] = 0;
   
    
    for(int i = 2; i <= n; i++) {
        
        memoFindingOne[i] = min(
                               i % 3 == 0 ? memoFindingOne[i / 3] : INT_MAX,
                               i % 2 == 0 ? memoFindingOne[i / 2] : INT_MAX,
                               memoFindingOne[i-1]
                               ) + 1;

    }
    
    return memoFindingOne[n];
}

void findingOneTest() {
    int n;
    cin >> n;
    memoFindingOne = new int[n + 1];
    //초기화
    
    for(int i = 0; i < n + 1; i++) {
        memoFindingOne[i] = -1;
    }
    
   // cout << "Top-Down 방식 : " << findingOne(n) << endl;
    cout << "Bottom-UP 방식 : " << findingOneBU(n) << endl;
    delete memoFindingOne;
}