//
//  Day17.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 6. 2..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "Day17.hpp"



int Calculator::power(int n , int p){
    
    if(n < 0 || p < 0) {
        throw MyException(); //new를 사용하지 않으면 도대체 뭐가 던져진 거야?
    }
    else {
        return pow(n, p);
    }
}

void day17() {
    
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
        if(scanf("%d %d",&n,&p)==2){
            try{
                int ans=myCalculator.power(n,p);
                cout<<ans<<endl;
            }
            catch(exception& e){
                cout<<e.what()<<endl;
            }
        }
    }
}