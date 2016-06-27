//
//  JumpingFroggi.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 6. 22..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "JumpingFroggi.hpp"

// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.

using namespace std;

int jumpingFroggi() {
    /* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
     앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
     만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
     그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
     또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
     단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
    //freopen("input.txt", "r", stdin);
    
    setbuf(stdout, NULL);
    
    int TC;
    int test_case;
    
    scanf("%d", &TC);	// cin 사용 가능
    
    for(test_case = 1; test_case <= TC; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오.
        int N; //돌 갯수
        int K; //최대 점프 거리
        int*  stones;//돌의 좌표가 저장되어 있음
        int currentPoint = 0; //현재 위치
        int jumpCount = 0;//점프 회수
        
        
        scanf("%d", &K);
        scanf("%d", &N);
        
        
        stones = new int[N];
        
        for(int i = 0; i < N; i++) {
            int point = 0;
            scanf("%d", &point);
            stones[i] = point;
        }
        
        
        for(int i = 0; i < N; i ++) {
            
            int maximum = currentPoint + K; //현재 위치에서 최대한 멀리 갈 수 있는 거리
            
            //만약 좌표가 점프 가능한 범위 안으로 들어오는 경우
            if(maximum>= stones[i]) {
               
                //마지막 좌표가 점프가 가능한 경우, 점프 후 종료
                if (i == N - 1) {
                    currentPoint =
                    jumpCount = jumpCount +1;
                    break;
                }
                
                
                //마지막 좌표가 아닌 경우, 그 다음 좌표가 점프가 되지 않으면 현재 좌표로 점프한다.
                if(maximum< stones[i+1]) {
                    currentPoint = stones[i];
                    jumpCount = jumpCount + 1;
                }
                //만약 그 다음 좌표가 점프가 된다면 아무 처리 하지 않고 다음 좌표로 간다. 한 번 점프 할 떄 최대한 멀리 가는 것이 목표니까
                
            }
            else {
                //만약 현재 좌표에서 점프가 더 이상 불가능하다면 포기하고 -1을 반환한다.
                jumpCount = -1;
                break;
            }
            
            
            
        }

        
        
        
        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);	// cout 사용 가능
        
        printf("%d\n", jumpCount);
        
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}