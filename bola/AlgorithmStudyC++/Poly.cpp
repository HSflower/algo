//
//  Poly.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 3. 31..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "Poly.hpp"
//  알고리즘 해결 전략을 보고 작성한 답안입니다. 스위프트로도 작성 한 게 있으니 위를 참조.
//  동적계획법을 사용해 작성한 것입니다.


//n개의 정사각형으로 이루어진, 맨 위 가로줄에 first(원노트의 r)개의 정사각형을 포함하는 폴리오미노의 수를 반환한다.
int poly(int n, int first) {
    
    //기저 사례 : n == first . 한 줄로만 이루어져 한 가지 말곤 없다.
    if(n == first) {
    return 1;
    }
    
    //메모이제이션. 중복 부분 문제가 나오면 캐시에서 찾아준다.
    int& ret = cachePoly[n][first];
    if(ret != -1)  {
        return ret;
    }
    
    ret = 0; //계산 값이 없으면 지금 새로 계산한다.
    
    //Poly(n, r) = 시그마(n-r, second = 1) * poly(n-r, second)
    for(int second = 1; second <= n - first; ++second) {
        int add = second + first - 1;
        add *= poly(n- first, second);
        add %= MOD; //폴리오미노의 수가 10,000,000 이상일 경우 10,000,000으로 나눈 나머지를 출력합니다.
        
        //계산한 부분문제 값을 저장한다.
        ret += add;
        ret %= MOD;
    }
    
    return ret; //저장된 계산값이 없어서 새로 계산한 값을 돌려준다.
}

int polyTest(int n) {
    //cache초기화. -1로 모든 배열을 초기화한다. 단, 이 초기화의 기준은 바이트 단위로 하므로, 32,64bit 정수라던가에서는 통하지 않는다!
    memset(cachePoly, -1, sizeof(cachePoly));
    int result = 0;
    
    for (int size = n; size > 0 ; size--) {
        result += poly(n, size);
    }
    return result;
}

void test() {
    std::cout << polyTest(2) << std::endl;
}
