//
//  TheLabyrinth.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 6. 22..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "TheLabyrinth.hpp"

void theLabyrinth() {
    
    /* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
     만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
     그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
     또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
     단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
    // freopen("input.txt", "r", stdin);
    
    setbuf(stdout, NULL);
    
    int TC;
    int test_case;
    
    scanf("%d", &TC);
    for(test_case = 1; test_case <= TC; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        
        int N;
        int K;
        char* s; //경근이의 이동 문자열
        
        long long result = 0ll;//방 번호의 합. 정수 범위를 초과할 수 있으니 충분히 큰 타입으로 준다.
        int **a; //격자
        
        scanf("%d %d\n", &N, &K);
        
                //이동 문자열 받기
        
                s = new char[K+1];//
        
        
        
                for(int i = 0; i < K; i++) {
                    scanf("%c", &s[i]);
                }
        
        //격자 만들기
        a = new int*[N];
        
        for(int i = 0; i < N + 1; i ++) {
            a[i] = new int[N];
        }
        
        
        //미궁의 방번호를 채운다.
        //위 삼각
        a[0][0] = 1;
        int count = 2;
        int row = 0; //대각선의 시작 원소 행
        int col = 1; //대각선의 시작 원소 열
        
        
        //여기서 j는 대각선 원소의 행과 열의 합
        for(int j = 1; j < N * 2; j++) {
            
            //아래로 내려가는 대각선. row 증가, col은 감소
            
            if(j <= N) {
                for(;row <= j;) {
                    a[row][col] = count;
                    count = count + 1;
                    row = row + 1;
                    col = col - 1;
                    
                }
                
                col = 0;
                row = row >= N-1 ? N-1 : row ;
                j++;//다음 대각선으로 넘어갈 때, 대각선의 row와 col의 합도 증가한다.
                
            }
            else { //아래 삼각으로 내려가는 대각선
             
                
                for(; row <= N - 1;) {
                    a[row][col] = count;
                    count = count + 1;
                    col = col - 1;
                    row = row + 1;
                }
                count  = count -1;
                row = row >= N-1 ? N-1 : row;
                col = N - 1;
            }
            
            //중간에 j가 범위를 벗어난다면, 위 삼각이 다 채워 진 것이므로 반복을 종료한다.
            if(j <= N) {
                //위로 올라가는 대각선. row가 감소, col은 증가
                for(; col <= j;) {
                    a[row][col] = count;
                    count = count + 1;
                    row = row - 1;
                    col = col + 1;
                }
                
                col = col >= N-1 ? N-1 : col ;
                row = 0;
            }
            
            else { //아래 삼각에서 올라오는 대각선
                
                for(; col <= N-1;) {
                    a[row][col] = count;
                    count = count + 1;
                    col = col + 1;
                    row = row - 1;
                }
                count = count - 1;
                col = col + 1;
                row = row >= 0 ? N-1 : row + 1;
                
            }
        }
        
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N ; j++) {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        
                //이동문자열에서 하나씩 문자를 꺼내 이동하며, 방문하는 방의 번호를 더한다.
                result = a[0][0] ;//맨 처음 방문한 방의 번호 1을 미리 더한다.
                int visitedR = 0; //현재 방문 중인 방의 행
                int visitedC = 0; //현재 방문 중이 방의 열
        
                for(int i = 0; i < K; i++) {
                    switch(s[i]) {
                        case 'U' ://위로 올라가기
                            visitedR = visitedR - 1;
                            break;
        
                        case 'D' ://내려가기
                            visitedR = visitedR + 1;
                            break;
        
                        case 'L' ://왼쪽
                            visitedC = visitedC - 1;
                            break;
        
                        case 'R' ://오른쪽
                            visitedC = visitedC + 1;
                            break;
                    };
                    
                       result = result + a[visitedR][visitedC];
                }
               
                delete a;
                delete s;
        
        
        
        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);
        printf("%lld\n", result);
        
    }
    
    
}