//
//  Day13.hpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 5. 31..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#ifndef Day13_hpp
#define Day13_hpp

#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Book{

protected:
    string title;
    string author;
public:
    Book(string t,string a){
        title=t;
        author=a;
    }
    virtual void display()=0; //함수 명 = 0은 가상 함수를 만드는 법이당! 이게 있는 클래스는 모두 자동으로 추상클래스가 된다
    
};

//inherited from book
class MyBook : Book {
    //Has a parameterized constructor taking these 3 parameters:
    protected :
    int price;
    
    public :
    //추상클래스를 상속 하고, 만약 그 클래스가 아무 패러미터가 없는 그냥 생성자가 없다면 생성자를 반드시 사용해 줘야 한다. 사용하는 방법은 다음과 같다.
    //현재 클래스의 생성자(수퍼에서 쓸 모든 패러미터까지 포함) : 수퍼생성자(수퍼 생성자에서 요구하는 파라미터 명. 옆에서 선언한 패러미터 명을 적어주면 된다.(타입 제외))
    MyBook(string t, string a ,int p) : Book(t, a){
        price = p;
    }
    
    //오버라이드!
    void display() {
        cout << "Title: " + title << endl;
        cout << "Author: " + author << endl;
        cout << "Price: " + to_string(price) << endl;
    }
    
};


#endif /* Day13_hpp */
