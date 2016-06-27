//
//  Day17.hpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 6. 2..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#ifndef Day17_hpp
#define Day17_hpp

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;



//나만의 Exception 만드는 법! Obj-C Swift 모두 비슷한 방법을 사용한다.
//it ruturns n ^ p and throw a exception when input contains negative
class MyException : public exception {
    virtual  const char* what() const throw() {
        return "n and p should be non-negative";
    }
};

class Calculator {
    public :
    int power(int n,int p);
};



void day17();

#endif /* Day17_hpp */
