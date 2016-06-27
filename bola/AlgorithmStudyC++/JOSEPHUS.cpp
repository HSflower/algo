//
//  JOSEPHUS.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 4. 4..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "JOSEPHUS.hpp"

using namespace std;

void josephus(int n, int k) {
    
    list<int> survivors;
    
    for(int i = 1; i <= n; ++i) {
        survivors.push_back(i);
    }
    
    list<int>::iterator kill = survivors.begin();
    
    while(n > 2) {
        
        //첫 사람이 죽는다. erase는 지운 원소의 다음 원소를 반환한다.
        kill = survivors.erase(kill);
        
        if(kill == survivors.end()) {
            kill = survivors.begin();
        }
            --n;
        
        
        //k - 1번 다음 사람으로 포인터를 옮긴다.
        for(int i = 0; i < k-1; ++i) {
            ++kill;
            //만약 리스트의 끝까지 왔다면, 다시 처음부터 순회를 시작한다.
            if(kill == survivors.end()) {
                kill = survivors.begin();
            }
        }
        
    }
    
    cout << survivors.front() << " " << survivors.back() << endl;
}

void josephusTest() {
    josephus(10, 3);
}
