//
//  3N+1.cpp
//  AlgorithmStudyC++
//
//  Created by 김윤철 on 2016. 6. 29..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "3N+1.hpp"

double getMinumum(int K, double max) {
    
    for(long long i = 2; i < max; i++) {
            long long n = i;
        
            while(n > 1) {
                if(memo[n] > 0) {
                    //전에 계산했던 값이 있다면, 가져다 쓴다.
                    memo[i] = memo[i] + memo[n];
                    break;
                }
                
                if(n % 2 == 0) {
                    n = n / 2;
                }
                else {
                    n = 3*n + 1;
                }
                memo[i] = memo[i] + 1;
        }
        
        if(memo[i] == K) {
            return i;
        }
    }
    
    return max;

}


void N_1Test() {
    setbuf(stdout, NULL);
    
    int T;
    int test_case;
    

    scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
    for(test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        int K;
        scanf("%d", &K); //숫자 입력 받기
        //배열 초기화
        
        double maximum = pow(2, K);
        memo = new double[1000000];
        
        
        for(int i = 0; i < 1000000 ; i++) {
            memo[i] = 0;
        }
        
        double minimum = getMinumum(K, maximum);
        
        // 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
        printf("Case #%d\n", test_case);
        
        printf("%0.lf %0.lf\n", minimum, maximum);
        
        delete memo;
    }
}