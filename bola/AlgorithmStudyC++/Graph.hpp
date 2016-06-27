//
//  Graph.hpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 5. 3..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <math.h>
#import <vector>
#import <queue>
#import <stack>
#import <list>
#import <iostream>
using namespace std;
//그래프는 두 가지 방식으로 표현 할 수 있다.
//인접 행렬과 인접 리스트
//표현 방식에 따라, 연산의 속도와 특성이 달라진다


namespace graphPractice {
    
    typedef struct Edge {
        int vertex[2]; //연결된 정점 (시작, 끝)
        int weight; //간선의 가중치
        friend bool operator== (const Edge e1, const Edge e2) {
            ///정점 일치 확인
            for(int i = 0 ; i < 2; i ++) {
                if(e1.vertex[i] != e2.vertex[i]) {
                    return false;
                }
            }
            
            //가중치 일치 확인
            if(e1.weight != e2.weight) {
                return false;
            }
            
            return true;
        }
    } Edge;
    
    //1. 인접 행렬 -> 걍 2차원 행렬. 각 간선의 가중치(가중치 그래프가 아닌 경우는 연결되면 bool혹은 1로 해주면 된다. 혹은 연결되지 않은 데에는 -1이나 이상한 값을 넣으면 된다)
    //각 정점이 어떤 간선으로 연결되었는지 확인하는 것이 빠르다/ 단 번에 인덱스로 검색하면 된다. 예 ) 1번과 5번 간선이 있나? adjacent[0][4] 값 확인!
    //간선의 수가 적은 희소 그래프의 경우, 희소 행렬로 표현되게 되므로 공간이 많이 낭비된다.
    //간선의 수가 많은 밀집 그래프를 사용하는 경우에 좋다
    
    static const int** adjacentMatrix;
    //2. 인접 리스트
    //위에 비해서 자리가 많이 절약 된다.
    //다만, 정점이 이어지는지 확인하기 위해서는 각 정점의 간선이 저장된 연결리스트를 탐색해야 한다는 단점이 있따.
    //list가 가지고 있는 원소들이 각 간선들이다. 지금은 가중치가 없는 그래프를 표현하느라 int형으로 정점의 번호만 표시하고 있지만, 가중치 등 간선이 다른 정보를 가지는 경우에는 간선을 따로
    //구조체로 만들어주는 게 낫다
    
    static vector<list<int>> adjacentList;
    
    //깊이 우선 탐색 (Depth - First Search )
    //그래프의 모든 정점을 특정한 순서에 따라 방문하는 알고맂므을 Search알고리즘이라고 한다.
    //그래프의 모든 정점을 발견하는 알고리즘 중 하나는 깊이 우선 탐색.
    //현재 정점고 ㅏ인접한 간선들을 하나씨 검사하다가, 아직 방문하지 않은 정점으로 향하는 간선이 있다면 그 간선을 무조건 따라간다.
    //만약 더 이상 갈 곳이 없는 곳으로 간다면, 마지막에 따라왔던 간선을 따라 뒤로 돌아간다 -> 뒤로 돌아가는 부분이 쉬운 재귀 호출을 사용한다.
    
    static  vector<bool> visited; //각 정점을 이미 방문했는지 확인한다.
    
    void depthFirstSearch(int here); //재귀 호출로 구현. 완전 탐색이기 때문이다
    void depthFirstSearchByStack(int here);
    void dfsAll();
    
    void dfsTest();
    
    
    void breadthFirstSearch(int here);
    void breadthFirstSearchByQueue(int here);
    void btsAll();
    
    void btsTest();
    
    /*
     최소 신장 트리
     minimum cost spanning tree
     */
    
    void kruskalSpanningTree();
    void primSpanningTree();
    void sollinSpanningTree();
    
    
    /*
     최단 경로
     */
    
    void dijkstra(int v); //하나의 정점 v에서 다른 모든 정점까지의 최단 경로
    void bellmanford(); //위에서 음의 가중치를 허용
    void allTheShortestPath(); //모든 정점에서 자신을 제외한 모든 다른 정점까지의 최단 경로
    void transiveClosure(); //바로 위의 모든 경로 찾기 알고리즘을 활용, 어느 한 정점에서 어느 다른 정점까지 가는 경로가 있는지만 체크!
    //반사적 이행적 폐쇄라면 자기 자신만 추가해주면 된다.
    //사실, 위의 최단 경로 알고리즘에서 무한대가 아니라면 1로 바꿔주면 되고, 경로가 없어서 무한대면 0으로 바꿔주면 된다.ㅋㅋㅋㅋ
    
    /*
     위상 정렬
     
     서로에게 의존성이 있는 작업을 수행해야 할 때, 어떤 순서로 수행해야 하는 지 알려준다
     각 작업을 정점으로, 작업 간의 의존 관계(예를 들어, a를 수행해야만 b를 할 수 있다면 b는 a에게 의존 관계가 있다.)
     를 간선으로 만들면, 의존성 그래프가 된다. (사이클이 없는 방향그래프(DAG)가 되는 것이 특징) (애초에 사이클이 있으면 아무것도 하지 못한다. 이에 대한 처리가 먼저 필요)
     
     의존성 그래프의 정점들을 일려로 늘어놓고, 왼쪽에서부터 하나씩 수행할 때 모든 의존성이 만족되려면 모든 간선이 왼쪽에서 오른쪽으로 가야한다.
     이렇게, DAG의 모든 정점을 배열하는 문제를 위상 정렬이라고 한다.
     
     들어오는 간선이 하나도 없는 정점을 하나씩 찾아서 정렬결과의 뒤에 붙이고, 그래프에서 이 정점을 지우는 과정을 반복.
     깊이 우선 탐색을 쓰면 쉽다고 합니당. 네 매우 그렇습니다.
     */

    //위상 순서를 위한 그래프 구현
    typedef struct TopologicalSortVertex {
        int value; //정점에 저장된 값. 여기서는 작업 번호
        int indegree; //진입 차수. 위상 정렬을 위해서 필요함.
        vector<TopologicalSortVertex*> link; //간선들로 연결된 정점들. 포인터로 넘겨줘야 같은 정점을 방문할 수 있음! 포인터가 아닐 시, 복사해서 저장하기 때문에 문제가 생김
    } TopologicalSortVertex;
    
    //그래프의 정의는 이쯤 될 것이다.
  //  vector<TopologicalSortVertex> topologicalSortGraph;
    
    void topologicalSort(); //위상 정렬
    void topologicalSortTest();
    
    //임계 경로
    //임계 경로 간선(작업). 가중치와 임계도를 저장하는 것이 있다.
    typedef struct cpState cpState;
    
    typedef struct cpActivity {
        int weight; //가중치
        int ciriticality; //임계도
        cpState *start;
        cpState *end;
    }cpActivity;
    
    //임계 경로 정점(공정)
    typedef struct cpState {
        int value;
        int indegree;
        vector<cpActivity *> link;
    }cpState;
    
    
    void criticalPath(vector<cpState *> g);//임계 경로 구하기
    void criticalPathTest();
    
    void getEulerCircuit();
}
#endif /* Graph_hpp */
