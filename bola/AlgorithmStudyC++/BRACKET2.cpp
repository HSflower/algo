//
//  BRACKET2.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 4. 4..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "BRACKET2.hpp"

//Algospot
bool wellMatched(const string& formula) {
    
    //여는 괄호, 닫는 괄호를 표시.
    const string opening("({["), closing(")}]");
    
    //이미 열린 괄호를 순서대로 담는 스택
    stack<char> openStack;
    
    for(int i = 0 ; i < formula.size(); ++i) {
        
        //opening안에 포함된 글자, 즉 열린 괄호면 스택 안에 넣는다.
        if(opening.find(formula[i]) != -1) {
            openStack.push(formula[i]);
        }
        else {
            //이외의 경우에는 스택의 맨 위 문자와 맞추어 본다.
            
            //스택이 비었으면 실패 처리
            if(openStack.empty()) return false;
            //서로 짝이 안 맞아도 실패.
            if(opening.find(openStack.top()) != closing.find(formula[i])) return false;
            
            //짝을 맞춘 괄호는 스택에서 뺀다.
            openStack.pop();
        }
    }
    
    //닫히지 않은 괄호가 없어야 성공
    return openStack.empty();
}


void bracket2(string input) {
    
    stack<char> stack;
    
    //문자열을 순회하며, 스택에 원소를 하나 하나 집어 넣는다.
    for(char a : input) {
        
        if(a == '{' || a == '[' || a == '(') {
            //여는 괄호면 스택에 넣는다.
            stack.push(a);
        }
        else if (a == '}' || a == ']' || a == ')'){
            //닫는 괄호면 스택에서 맨 위의 원소를 꺼내, 짝이 맞는지 확인한다.
            
            //만약 스택이 비어 있다면, 닫는 괄호와 매치될 여는 괄호가 없다는 의미 이므로 NO를 출력하고 종료.
            if(stack.empty()) {
                cout << "NO" << endl;
                return;
            }
            
            char openBracket = stack.top();
            
            //괜히 스위치로 했나??
            switch(a) {
                    
                case '}' :
                    if(openBracket == '{') {
                        stack.pop(); //짝을 찾은 괄호는 팝한다.
                        break;
                    }
                    else {
                        cout << "NO" << endl;
                        return;
                    }
                    
                    
                case ']' :
                    if(openBracket == '[') {
                        stack.pop(); //짝을 찾은 괄호는 팝한다.
                        break;
                    }
                    else {
                        cout << "NO" << endl;
                        return;
                    }
                case ')' :
                    if(openBracket == '(') {
                        stack.pop(); //짝을 찾은 괄호는 팝한다.
                        break;
                    }
                    else {
                        cout << "NO" << endl;
                        return;
                    }
                    
                default :
                    //괄호가 아닌 문자들이 들어온 경우는 무조건 아니다.
                    cout << "NO" << endl;
                    return;
            };
        }
        else { //괄호들이 아닌, 입력에 포함되어서는 안될 문자열들이 들어온 경우
            cout << "NO" << endl;
            return;
        }
        
    }
    
    //순회가 끝난 뒤, 스택이 비어 있으면 모든 괄호가 올바른 짝을 찾아 나간 것이므로 YES, 아니면 닫힌 괄호가 모자른 것이므로 NO를 출력
    if(stack.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    
}

void bracket2Test() {
    
    //cin을 쓸 때는 미리 초기화를 하면 안된다... 왜 또 까묵
    int numOfTestCase;
    string input;
    
    cin >> numOfTestCase;
    
    while(numOfTestCase > 0) {
        cin >> input;
        bracket2(input);
        input.clear();
        numOfTestCase--;
    }
    
}