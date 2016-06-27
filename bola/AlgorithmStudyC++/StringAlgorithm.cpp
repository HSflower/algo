//
//  StringAlgorithm.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 4. 29..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "StringAlgorithm.hpp"

//코드 20. 1 단순한 문자열 검색 알고리즘 (almost brute-force)
//최악일 때는 모든 시작 위치가 답이 될 경우이다. 예를 들어 aaaaaaaaaa와 a를 비교. 비교 횟수가 H * N(길이)가 되어 버린다.
//입력이 크고 최악의 조건을 만족할 떄는 별로 좋지 않으나, 입력이 작을 때는 구현이 빨라 사용해도 좋다
//H는  N을 찾아낼 문자열
//해당 문자열이 있는 시작 위치들을 반환한다.
vector<int> naiveSearch(const string& H, const string& N){
    vector<int> results; //결과 반환용
    
    //모든 시작 위치를 다 시도한다.
    for(int begin = 0; begin + N.length() <= H.length(); begin++) {
        bool matched = true;
        
        //한 글자 한 글자 다 비교한다. 만약 다른 글자가 나오면 다음 시작 위치를 시돤다.
        for(int i = 0; i < N.length(); i++) {
            
            if(H[begin + i] != N[i]) {
                matched = false;
                break;
            }
            
        }
        
        if(matched){
            //만약 모두 매치되었다면, 이번 시작 위치를 반환하기 위해 저장한다.
            results.push_back(begin);
        }
        
    }
    
    return results;
}

void naiveSearchTest() {
    string H;
    string N;
    cin >> H;
    cin >> N;
    
    auto results = naiveSearch(H, N);
    
    for(int result : results) {
        cout << result << " ";
    }
    
    cout << endl;
}

/*
 KMP 알고리즘
 */

/*
시작 위치 배열 만들기.
접두사이면서 접미사인 최대 문자열의 길이를 이용한다. 이 것은 몇 개가 일치하는 문자인가를 보고 알 수 있다.
N : aabaaabac
H : aabaaabas ss..
 여기서, 불일치는 c 문자에서 발생한다.  여떄 까지 매치 된 것은 7 글자이고, 그 이전까지 매치된 문자열은 aabaaaba이다.
 여기서, 우리는 어디서 시작하면 안되는 지 매우 잘 알 수 있다. 그 걸 증명하는 과정을 책을 보시게.
 쉽게, aabbbbaa 에서, aa는 양쪽 끝에 똑같이 나타남을 알 수 있다. 여기서, 만약 이 다음 문자에서 불일치가 발생한 경우에는 마지막에 발생한 aa에서 시작하면 최대한 비교 회수를 줄일 수 있을 것이다.
 
 
 방법 1. 2 ~ 길이 -1 길이의 접두사를 일일히 만들어 일일히  비교하기.
 방법 2. 똑같이 KMP를 이용한다. 다만, 시작 위치 배열을 하나만 쓰고, 그를 계속 가장 큰 값(가장 긴 접두사가 매치되도록 -> 다음 비교 회수가 줄어듬)을 가지도록 한다.
*/

//방법 1
vector<int> getPartialMatchNaive(const string N){
    vector<int> pi(N.length(), 0);
    
    //접두사 길이를 잡아준다. 물론 0은 제외.
    for(int begin = 1; begin < N.length(); begin++) {
        //그 접두사를 가지고, 그 접두사가 대응되는, 시작 지점에서 제일 먼 위치를 찾는다; i + begin은 소스 문자열 보다 반드시 짧아야 한다.
        for(int i = 0; i + begin < N.length(); i++) {
            if(N[i] != N[begin + i]) {
                break; //더 이상 해당 접두사와 접미사가 일치 하지 않으므로 멈춘다. a a != b a
                //이 상황에서는a가 최대 접두 & 접미가 된다.
            }
            else { //이번 접두사와 접미사가 완전 대응 한 경우, 그 내용을 기록한다. 기존에 누가 기록해 놨다면, 자신과 예전의 것을 비교해 더 큰 값을 고른다.
                pi[begin + i] = pi[begin + i] > i + 1 ? pi[begin + i] : i + 1;
            }
        }
        
    }
    return pi;
}

//방법 2. KMP 를 사옹했다. 다만 이번엔  ㅅㄹ짝 다른데, 시작위치 배열을 자기가 쓴다.
//KMP이므로 O(N)이다.
vector<int> getPartialMatch(const string N) {
    vector<int> pi(N.length(), 0); //벡터 생성 및 초기화
    //KMP를 사용해 시작 위치 배열을 만든다.
    int begin = 1; //처음 시작 위치
    int match = 0; //매치된 문자열 길이 (일치된 접두사의 길이)
    
    //KMP로 자기 자신을 찾는다.
    //N을 N에서 찾는데, begin = 0이면, 정말로 자기 자신을 찾아버려서 안됨!
    while((begin + match) < N.length()) {
        //접두사를 접미사와 일치하는 지 찾기!
        if(N[begin + match] == N[match]) {
            ++match;
            pi[begin+match - 1] = match; //일치하는 접두-접미 최대 길이를 저장한다.
            //저번 같이 max 비교 연산이 없는 이유는, 이미 match가 있는 시점에서 pi[match -1]은 항상 계산된 뒤이기 때문이다.
        }else {
            //불일치 발생!
            if(match == 0) {
                //처음부터 불일치
                begin++; //다음 문자가 바로 다음 시작 위치이다
            } else {
                begin += match - pi[match -1];
                match = pi[match-1];
            }
            
        }
        
        
    }
    
    return pi;
}

//불일치가 발생하기 이전의 매칭된 길이로 알아내는 정보를 이용!
//매칭된 문자열로, 접두사이면서 접미사인 최대 문자열의 길이를 이용해, 다음 시작 위치를 정한다.
//이렇게 하면, 시작 위치 배열 구하는 데 최소 N(물론 시작 위치 배열 구하는 데도 KMP사용 ), 비교하는 데 H의 반복을 하므로 시간 복잡도O(N + H)임당

vector<int> KMPSearch(const string& H, const string& N) {
    vector<int> results;
    vector<int> startLocation = getPartialMatch(N);

    int begin = 0;
    int matched = 0; //현재까지 매치된 문자 개수
    while(begin <= H.length() - N.length()) {
        
        //만약 이번에 비교하는 문자가 찾는 문자열의 해당 글자와 같다면
        if(matched < N.length() && H[begin + matched] == N[matched]) {
            matched++;
            
            //만약 찾는 문자열을 온전히 다 찾았다면
            if(matched == N.length()) {
                results.push_back(begin);
            }
        
        }
        else { //비교하는 문자가 다르다! 불일치 발생시.
            //
            if(matched == 0){ //처음부터 불일치가 발생했다면, 그냥 다음 문자를 시작 위치로 삼는다
                begin++;
            }
            else { //앞에 몇 개는 맞다가 불일치가 발생했다면, 미리 계산해 두었던 시작 위치 배열을 이용해 다음 시작 위치를 구한당!
            begin = begin + matched - startLocation[matched-1];
            matched = startLocation[matched-1];
            }
        }
    }
    
    return results;
}

void KMPSearchTest() {
    string h, n;
    cin >> h;
    cin >> n;
    auto results = KMPSearch(h, n);
    
    for(int result : results) {
        cout << result << " ";
    }
    cout << endl;
}


/*
 KMP알고리즘의 정통 구현.
 */
vector<int> kmpSearch2(const string& H, const string& N) {
    int n = H.length();
    int m = N.length();
    vector<int> ret; //찾은 위치 반환
    vector<int> pi = getPartialMatch(N); //찾을 문자열의 접두사도 되고 접미사도 되는 문자열 길이
    
    int matched = 0; //현재까지 대응된 글자 수
    
    for(int i = 0 ; i < n; i++) {
        //matched번 글자와 짚더미의 해당 글자가 불일치할 경우, 현재 대응된 글자의 수를 pi[matched - 1]로 줄인다.
        while(matched > 0 && H[i] != N[matched]) {
            matched = pi[matched - 1];//재시작 위치를 군더더기 없이 바로 잡아 준 것
        }
        //글자가 대응될 경우
        if(H[i] == N[matched]) {
            matched++;
            //바늘 문자열을 찾았을 경우
            if(matched == m) {
                ret.push_back(i - m + 1); // i = 이번 짚더미의 글자, m = 바늘 문자열의 길이. 찾은 바늘 문자열의 짚더미 문자열 내 시작 위치를 반환해야 하므로 + 1
                matched = pi[matched- 1]; //재시작 위치를 다시 잡는다.
            }
        }
    }
    
    return ret;
}


void testAll() {
    naiveSearchTest();
    KMPSearchTest();
}