//
//  FESTIVAL.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 4. 13..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "FESTIVAL.hpp"


int n[10001]; //날짜가 저장될 전역 배열

float festival(int sizeOfInput, int l) {
    
    float result = INT_MAX; //소수점 10^(-7)까지의 오차는 봐준다고 했으니 float으로도 충분할 듯. 그리고 비교 값 크기를 위해서 처음엔 큰 값을 넣어주었다
    int sizeOfWindow = l;
    
    
    while(sizeOfWindow <= sizeOfInput) {
        
        for(int i = 0 ; i <= sizeOfInput - sizeOfWindow; i++) {
            
            float newResult = 0;
            
            //n[i]부터 n[last]까지, window크기 개수의 연속된 원소를 더하고 window의 크기로 나눈다.
            for(int k = i; k < i + sizeOfWindow; k++) {
                newResult += n[k];
            }
            
            //더한 비용의 평균을 낸다.
            newResult = newResult / (float)sizeOfWindow;
            
            if(newResult < result) {
                result = newResult;
            }
        }
        
        sizeOfWindow++;
    }
    
    return result;
}

void festivalTest() {
    
    int c, l, num, count = 0;
    
    cin >> c;
    
    while(c > 0) {
        
        cin >> num >> l;
        
        for(int i = 0; i < num; i++) {
            int input;
            cin >> input;
            n[i] = input;
            
        }
        
        cout << festival(num, l) << endl;
        
        count = 0;
        c--;
    }

    
}