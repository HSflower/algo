//
//  Rectangles.cpp
//  AlgorithmStudyC++
//
//  Created by 김윤철 on 2016. 7. 14..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "Rectangles.hpp"

void rectangles() {
    /* 아래 freopen 함수는 sample_input.txt 를 read only 형식으로 연 후,
     앞으로 표준 입력(키보드) 대신 sample_input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
     만약 본인의 PC 에서 테스트 할 때는, 입력값을 sample_input.txt에 저장한 후 freopen 함수를 사용하면,
     그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 sample_input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
     또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
     단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
    /* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
     C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
     따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
    setbuf(stdout, NULL);
    
    int T;
    int test_case;
    
    scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
    for(test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
    
        int N, M, K;
        
        scanf("%d", &N);
        scanf("%d", &M);
        scanf("%d", &K);
    
        vector<int> isIncdluing = vector<int>(K, 0); //[i][j] i가 j를 include 하는가. -1 자기 자신 혹은 i 에게 포함 당함 0은 초기값 1은 포함하고 있음
        vector<vector<int>> rectangles = vector<vector<int>>(K); //사각형들을 담을 벡터
        
        for(int i = 0 ; i < K; i++) {
            rectangles[i] = vector<int>(4, 0);
            
            int x1,x2;
            int y1,y2;
            scanf("%d", &x1);
            scanf("%d", &y1);
            scanf("%d", &x2);
            scanf("%d", &y2);
            
            
            
            rectangles[i][0] = x1;
            rectangles[i][1] = y1;
            rectangles[i][2] = x2;
            rectangles[i][3] = y2;
            
        }
        
        
        int maxIncluding = 0;
        
        for (int i = 0; i < K; i++ ) {
            
            int numOfIncluding = 0;
            
            int x1 = rectangles[i][0];
            int y1 = rectangles[i][1];
            int x2 = rectangles[i][2];
            int y2 = rectangles[i][3];
            
            
            //자신이 이미 포함당하고 있다면,자신이 포함하고 있는 모든 사각형은 자신이 포함당한 사각형도 포함하기 때문에 더이상 계산할 이유가 없다
            if(isIncdluing[i] == -1)  {
                continue;
            }
            
        
            //나머지 사각형들에 대해서
            for(int j = 0; j < K ;j++) {
    
                
               // 자기 자신이면 계산하지 말고 바로 다음 사각형을 찾아 떠난다.
                if(i == j) {
                    continue;
                }
                
                int ax1 = rectangles[j][0];
                int ay1 = rectangles[j][1];
                int ax2 = rectangles[j][2];
                int ay2 = rectangles[j][3];
                
                //포함하고 있는지 검사한다.
                if( ((x1 <= ax1) && (x2 >= ax2) ) && ((y1 <= ay1) && (y2 >= ay2))) {
                    //그렇다면, 포함하는 사각형에 대해 처리를 해준다.
                    numOfIncluding = numOfIncluding + 1;
                    isIncdluing[i] = 1;
                    isIncdluing[j] = -1;
                }
                
            }
            
            if(maxIncluding < numOfIncluding) {
                maxIncluding = numOfIncluding;
            }
            
        }
        
        
        if(maxIncluding < 1) {
            maxIncluding = 1;
        }
        
        // 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
        printf("Case #%d\n", test_case);
        printf("%d\n", maxIncluding);
    }
    // 정상종료 시 반드시 0을 리턴해야 합니다.
}