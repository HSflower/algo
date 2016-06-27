//
//  Day19.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 6. 4..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "Day19.hpp"


void day19() {
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator();
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;
}