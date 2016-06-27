//
//  Day19.hpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 6. 4..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

/*
 Day 19 - about Interface!
 Interface -- it like a blueprint but have not yet implemented! where you should do some work for this :)
 Recall that abstraction is the separation between what something does and how it's accomplished.
 
 An interface is a collection of abstract methods and constants that form a common set of base rules/specifications for those classes that implement it.
 Much like an abstract class, an interface cannot be instantiated and must be implemented by a class.
 */


#ifndef Day19_hpp
#define Day19_hpp

#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class AdvancedArithmetic{
public:
    virtual int divisorSum(int n)=0;
};


class Calculator : public AdvancedArithmetic {
    public :
        //모든 약수를 더해 반환한다.
    int divisorSum(int n) {
        //약수를 구한다.
        int result = 0;
        //가장 쉬운 방법은 1부터 자기 자신까지 나눠가면서 나눠지는 수를 결과에 더하는 것이다.
        //그렇게 효율적이라고 하기는 힘들다.
        
        //n = 1이면 1을 반환한다
        if(n == 1) {
            return 1;
        }
        
        for (int i = 1; i <= n ; i++) {
            
            if(n % i == 0)
                result += i;
                
            
        }
        
        return result;
    }
};

void day19();
#endif /* Day19_hpp */
