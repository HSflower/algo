//
//  Dictionary.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 5. 3..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "Dictionary.hpp"

//주어진 단어들로부터 알파벳 간의 선후관계 그래프를 생성한다
void makeGraph(const vector<string>& words){
    
    adj = vector<vector<int>>(26, vector<int>(26, 0)); //간선 초기화
    
    for(int j = 1; j <  words.size(); j++) {
        int i = j - 1, len = min(words[i].length(), words[j].length());
        
        //word[i]가 word[j]앞에 오는 이유를 찾는다. 거기에는 길이, 알파벳의 순서가 있다.
        //더 짧은 길이만큼만 돈다
        for(int k = 0 ;k < len; k++) {
            
            //만약 인접한 두 문자열의 같은 번쨰 문자가 일치하지 않는다면
            if(words[i][k] != words[j][k]) {
                int a = words[i][k] - 'a'; //a면 기본 0이 될 것이다.
                int b = words[j][k] - 'a';
                
                //a번째 글자에서 b번째 글자를 연결한다. 뒤에 와야 하니께.
                adj[a][b] = 1;
                break;
            }
        }
    }
}

void dfs(int here) {
    vector<int> vertexs = adj[here];
    seen[here] = 1;
    for(int vertex : vertexs) {
        if(seen[vertex])
        {
            dfs(here);
        }
    }
    order.push_back(here);//
}

//위상정렬. 그래프가 사이클이 있어서 DAG가 아니라면, 빈 벡터를 반환한다.
vector<int> topologicalSort() {
    //들어오는 간선이 0인 정점을 찾는다.
    int n = adj.size();
    seen = vector<int>(n,0);
    order.clear();
    
    //깊이 탐색
    for(int i = 0; i < n; i++) {
        if(!seen[i]) {
            dfs(i);
        }
    }
    
    
    reverse(order.begin(), order.end());
    //만약 그래프가 DAG가 아니라면, 정렬결과에 역방향 간선이 있따.
    //사이클이 존재하는지 검사한다.
        for(int i = 0 ; i < n ; i++) {
            for(int j = i + 1; j < n; j++) {
                if(adj[order[j]][order[i]]) {
                    return vector<int>();
                }
            }
        }
        
    return order; //정상적인 DAG인 경우, order를 반환한다.
}


