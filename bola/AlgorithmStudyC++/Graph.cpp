//
//  Graph.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 5. 3..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "Graph.hpp"

#pragma mark --그래프 탐색 알고리즘 (깊이 우선, 넓이 우선)
//재귀 호출로 구현. 완전 탐색이기 때문이다
//여기서는 인접 리스트를 사용하였다
//

namespace graphPractice {
    
    void depthFirstSearch(int here) {
        //이번 방문 지점을 출력한다
        cout << "I'm now in" << here << endl;
        visited[here] = true;
        for(int vertex : adjacentList[here]) {
            
            //아직 그 정점을 탐색하지 않았다면 이번 기회에 탐색한다
            if(!visited[vertex]) {
                depthFirstSearch(vertex);
            }
        }
    }
    
    //스택으로 구현하였다
    void depthFirstSearchByStack(int here) {
        
        //방문해야 할 정점을 담은 스택
        stack<int> s = stack<int>();
        
        s.push(here);
        
        while(!s.empty()) {
            int vertex = s.top(); //현재 방문중인 노드
            cout << "I'm in " << vertex << endl;
            s.pop();
            visited[vertex] = true;
            
            //자신의 인접리스트의 노드들을 집어넣는다.
            for (int neighborVertex : adjacentList[vertex]) {
                if(!visited[neighborVertex]) {
                    s.push(neighborVertex);
                }
            }
        }
        
        
    }
    
    
    void dfsAll() {
        visited = vector<bool>(adjacentList.size(), false); //방문 기록 초기화
        
        //모든 정점을 탐색해야 하므로, for문을 돌린다
        //굳이 왜 그러냐면, 그래프 중에서는 서로 분리된 애들이 있따. 모두 연결되어 있다고 가정한다면 그냥 한 번만 돌려줘도 모든게 끝나겠지만,
        //중간이 끊겨있는 그래프라면 모든 정점을 돌 수 없다! -- 이점을 이용해서 연결그래프인지 아닌지를 판단할 수 있다.
        //그래서 방지 차원에서 여기서 모든 정점을 시작점으로 돌아주는 것
        for(int i = 0; i < adjacentList.size(); i++) {
            if(!visited[i]){
                depthFirstSearch(i);
            }
        }
    }
    
    void dfsTest(){
        adjacentList = vector<list<int>>();
        
        
    }
    
    // 루트 방문 -> 인접 리스트 내 모든 노드 방문 -> 인접 리스트 내의 노드 중 하나로 이동해 또 인접리스트 내 모든 노드 방문(이미 방문했던 데는 제외) -> 무한 반복
    void breadthFirstSearch(int here) {
        //이번 방문 지점을 출력한다.
        if(!visited[here]) {
            cout << "Now I'm in" << here << endl;
            visited[here] = true;
        }
        
        //인접 리스트의 모든 친구들을 먼저 방문한다.
        //위의 깊이 탐색과 다른 것은, 바로 다음 노드로 넘어가서 그 노드의 인접리스트를 체크하는 것이 아닌
        //우선 자신의 인접리스트의 모든 노드들을 확인하고 간다는 것이다.
        for(int vertex : adjacentList[here]) {
            if(!visited[vertex]) {
                cout << "Now I'm in" << vertex << endl;
                visited[vertex] = true;
            }
        }
        
        //인접 리스트 내의 모든 노드를 확인했으면, 그제서야 다음 노드로 넘어간다.
        //이번에 방문했던 노드들을
        for(int vertex : adjacentList[here]) {
            breadthFirstSearch(vertex);
        }
    }
    
    void breadthFirstSearchByQueue(int here) {
        //큐를 사용해서 재귀 호출을 없애 버렸다.
        queue<int> q = queue<int>(); // 방문할 정점을 담을 큐다.
        
        q.push(here);
        
        while(!q.empty()) {
            int vertex = q.front();
            q.pop();
            visited[vertex] = true;
            cout << "I'm in " << vertex << endl;
            
            //그 노드의 방문하지 않은 인접리스트의 노드를 모두 큐에 넣는다.
            for(int neighborVertex : adjacentList[vertex]) {
                if(!visited[neighborVertex]) {
                    q.push(neighborVertex);
                }
            }
        }
        
        
    }
    void btsAll() {
        visited = vector<bool>(adjacentList.size(), false); //방문 기록 초기화
        
        //모든 정점을 탐색해야 하므로, for문을 돌린다
        //굳이 왜 그러냐면, 그래프 중에서는 서로 분리된 애들이 있따. 모두 연결되어 있다고 가정한다면 그냥 한 번만 돌려줘도 모든게 끝나겠지만,
        //중간이 끊겨있는 그래프라면 모든 정점을 돌 수 없다! -- 이점을 이용해서 연결그래프인지 아닌지를 판단할 수 있다.
        //그래서 방지 차원에서 여기서 모든 정점을 시작점으로 돌아주는 것
        
        //재귀호출
        for(int i = 0; i < adjacentList.size(); i++) {
            if(!visited[i]){
                breadthFirstSearch(i);
            }
        }
        
        //큐 이용
        for(int i = 0; i < adjacentList.size(); i++) {
            if(!visited[i]){
                breadthFirstSearchByQueue(i);
            }
        }
    }
    
    
    void btsTest() {
        
    }
    
#pragma mark --최소 신장 트리 알고리즘
    //최소 신장 트리를 만드는 그래프는 무방향 가중치 그래프이다. 음의 사이클은 존재하지 않는다.
    
    //간선 순 정렬을 위한 함수
    bool cmp(Edge e1, Edge e2) {
        return e1.weight < e2.weight;
    }
    
    
    //그래프는 인접 리스트로 구현하였다
    void kruskalSpanningTree() {
        //간선을 가중치 오름차순으로 정렬.
        int N = sqrt(sizeof(adjacentMatrix) / (sizeof(int))); //정점 개수
        
        vector<Edge> sortedEdges;
        vector<Edge>  tree; //트리
        vector<list<int>> vertexs; //정점 집합
        
        for (int i = 0; i < N; i++) {
            list<int> vertexGroup = list<int>();
            vertexGroup.push_back(i);
            vertexs.push_back(vertexGroup);
        }
        
        
        //간선을 가져온다.
        for(int i = 0; i < 4; i++) {
            for(int j = i; j < 4; j++) {
                Edge e = {{i, j}, adjacentMatrix[i][j]};
                sortedEdges.push_back(e);
            }
        }
        
        //가중치에 따라 정렬
        sort(sortedEdges.begin(), sortedEdges.end(), cmp);
        
        //트리를 이루는 간선의 수가 N-1이 될 때까지 반복한다
        while(vertexs.size() < N && sortedEdges.size() > 0) {
            //가장 작은 간선을 꺼낸다
            Edge e = sortedEdges.front();
            sortedEdges.erase(sortedEdges.begin());
            
            //사이클을 만드는지 검사한다.
            int indexOfFirstVertex = 0;
            int indexOfDestVertex = 0;
            
            for(int i = 0 ; i < vertexs.size(); i++) {
                //한 정점 그룹 내에 간선의 시작, 끝 정점이 같이 들어가 있으면 싸이클이다. 그렇다면, 둘 중 하나만 여기에 들어가 있지 않으면 싸이클을 생성하지 않으므로, 그런 경우에는
                list<int> vertexGroup = vertexs[i];
                if (find(vertexGroup.begin(), vertexGroup.end(), e.vertex[0]) == vertexGroup.end()) {
                    indexOfFirstVertex = i;
                }
                if (find(vertexGroup.begin(), vertexGroup.end(), e.vertex[1]) == vertexGroup.end()) {
                    indexOfDestVertex = i;
                }
            }
            
            //사이클을 이루지 않을 때
            if (indexOfFirstVertex != indexOfDestVertex) {
                tree.push_back(e); //트리에 간선 추가
                
                //정점 집합 병합
                vertexs[indexOfFirstVertex].merge(vertexs[indexOfDestVertex]);
                vertexs.erase(vertexs.begin() +  indexOfDestVertex);
            }else {
                printf("There is a cycle!");
            }
        }
        
        if(tree.size() < N - 1) {
            printf("couldn't create a spanning tree!");
        } else {
            for(Edge e : tree) {
                printf("%d - %d \n", e.vertex[0], e.vertex[1]);
            }
        }
        
    }
    
    //Prim 알고리즘 확장
    void primSpanningTree() {
        //간선을 가중치 오름차순으로 정렬.
        int N = sqrt(sizeof(adjacentMatrix) / (sizeof(int)));
        vector<Edge> tree; //트리
        vector<int> vertexs; //정점 집합.
        vector<Edge> possibleEdges; //선택 가능한 간선 집합
        
        //0번 정점을 초깃값으로 넣어준다
        vertexs.push_back(0);
        
        while(tree.size() < N - 1)
            for(int vertex : vertexs) {
                
                //가장 작은 가중치를 가지는 간선을 찾아낸다
                //간선의 양끝의 정점의 둘 중 하나만 속하도록 한다
                for(int i = 0 ; i < N; i++) {
                    Edge e = {vertex, i,adjacentMatrix[vertex][i]};
                    
                    //트리 내의 정점에 연결되지 않는 새로운 정점이 있는 간선이라면, 가능한 간선 목록에 넣는다.
//                    if(find(vertexs.begin(), vertexs.end(), i) == vertexs.end()) {
//                        possibleEdges.push_back(e);
//                    }
                }
                
                //만약 추가가 가능한 간선이 없다면 스패닝 트리를 만들 수 없다.
                if(possibleEdges.size() <= 0) {
                    printf(" NO Spanning Tree! ");
                    return;
                }
                
                //가능한 간선 중 가장 가중치가 작은 간선을 선택한다.
                sort(possibleEdges.begin(), possibleEdges.end(), cmp);
                tree.push_back(possibleEdges.front());
                
                //가능한 간선 집합을 리셋한다.
                possibleEdges.clear();
            }
        
        
    }
    
    //
    void sollinSpanningTree() {
        
        vector<Edge> mstree; //최소 신장 트리
        vector<list<int>> forest; //트리의 집합
        vector<Edge> edges; //해당 트리에서 선택 가능한 간선 집합
        
        
        int N = sqrt(sizeof(adjacentMatrix) / (sizeof(int)));
        //정점을 한 개 씩 소유하는 트리들을 만들어준다.
        for(int i = 0; i < N; i++) {
            list<int> tree = list<int>();
            tree.push_back(i);
            forest.push_back(tree);
        }
        
        //간선을 가져온다.
        for(int i = 0; i < 4; i++) {
            for(int j = i; j < 4; j++) {
                Edge e = {{i, j}, adjacentMatrix[i][j]};
                edges.push_back(e);
            }
        }
        
        //모든 트리를 한 번씩 순회하며, 간선을 선택한다.
        //트리가 딱 한 개 남을 때 까지 반복한다.
        while(forest.size() != 1 && edges.size() != 0) {
            for (list<int> tree : forest ) {
                
                for(int vertex : tree) {
                    vector<Edge> possibleEdges;
                    //가장 작은 가중치를 가지는 간선을 찾아낸다
                    //간선의 양끝의 정점의 둘 중 하나만 속하도록 한다
                    for(int i = 0 ; i < N; i++) {
                        Edge e = {vertex, i,adjacentMatrix[vertex][i]};
                        
                        //트리 내의 정점에 연결되지 않는 새로운 정점이 있는 간선이라면, 가능한 간선 목록에 넣는다.
//                        if(find(tree.begin(), tree.end(), e) == tree.end()) {
//                            possibleEdges.push_back(e);
//                        }
                    }
                    
                    //후보 들 중 가장 작은 간선을 찾아낸다.
                    sort(possibleEdges.begin(), possibleEdges.end(), cmp);
                    Edge newEdge = possibleEdges.front();
                    //사용 가능한 간선 목록에서 이번에 선택한 간선을 지운다
                    edges.erase(find(edges.begin(), edges.end(), newEdge));
                    
                    //최소 신장 트리의 간선에 추가한다.
                    mstree.push_back(newEdge);
                    
                    
                    //이번 선택으로 연결된 두 트리를 합친다.
                    
                    //간선의 다른 쪽에 연결된 정점이 들어있는 트리를 찾는다
                    for(list<int> other : forest) {
                        //자신인 경우는 찾지 않는다
                        if(other == tree) {
                            break;
                        }
                        
                        if(find(other.begin(), other.end(), newEdge.vertex[1]) != other.end()){
                            tree.merge(other);
                            forest.erase(find(forest.begin(), forest.end(), other));
                        }
                    }
                    
                }
                
                
            }
            
            
        }
    }
    
    
    
#pragma mark --최단 경로 알고리즘
    //참고 -- http://kaspyx.kr/64
    void dijkstra(int v) {
        int N = sqrt(sizeof(adjacentMatrix) / (sizeof(int))); //정점 개수
        int dist[N]; //최단 경로 저장
        bool s[N]; //방문 여부
        const int MAX = INT_MAX; //실제로 이러면 안되지만, 무한대를 INT_MAX로 두었다. 이 값이면 경로가 없다고 보도록 한다.
        
        //s, dist초기화
        for(int i = 0 ; i < N ; i++) {
            s[i] = false;
            dist[i] = adjacentMatrix[v][i] < MAX ? adjacentMatrix[v][i] : MAX;
        }
        
        //이제 최단 경로를 구하기 시작한다.
        s[v] = true; //시작 점은 방문 처리를 한다.
        dist[v] = 0; //자기 자신은 항상 거리가 0이다.
        
        
        //인덱스와 자기 자신을 구하는 것을 제외하면 N - 2번이 맞다.
        for(int i = 0; i < N- 2; i++) {
            
            int u = 0;
            int min = INT_MAX;
            //갈 수 있는 가장 가까운 정점 u 구하기
            for(int i = 0; i < N; i++) {
                if(visited[i] != true && min> dist[i]) {
                    min = dist[i];
                    u = i;
                }
            }
            
            //경로를 다시 계산한다.
            s[u] = true;
            for(int w = 0 ; w < N; w++) {
                if(!s[w]) {
                    int newDist =  (dist[u] + adjacentMatrix[v][w]);
                    dist[w] = dist[w] > newDist ? dist[w] : newDist;
                }
            }
        }
    }
    
#pragma mark --위상 정렬, 임계 경로
    vector<TopologicalSortVertex> topologicalSort(vector<TopologicalSortVertex> *graph){
        //진입 차수가 0인 정점을 찾는다.
        //만약 그런 정점이 없다면 그는 사이클이 있는 그래프이므로 위상 정렬을 할수 없다!
        
        queue<TopologicalSortVertex> zeroQ; //진입차수가 0인 정점이 모여 있는 큐
        vector<TopologicalSortVertex> topologicalSort; //위상 정렬된 결과
        
        for(TopologicalSortVertex vertex : *graph) {
            if(vertex.indegree == 0) {
                zeroQ.push(vertex);
                break;
            }
        }
        
        if(zeroQ.empty()) {
            printf("cannot topological sort becasue there is a cycle");
            return topologicalSort; //빈 벡터 반환
        }
        
        while(!zeroQ.empty()) {
            //진입 차수가 0인 것 하나를 꺼낸다.
            TopologicalSortVertex vertex = zeroQ.front();
            zeroQ.pop();
            
            //꺼낸 정점을 위상 정렬 결과에 집어 넣는다.
            topologicalSort.push_back(vertex);
            
            //꺼낸 정점에 간선으로 연결된 모든 정점에서 진입 차수를 1씩 뺀다.
            for(TopologicalSortVertex *successor : vertex.link) {
                successor->indegree = successor->indegree - 1;
                //진입 차수가 0이 되면 zeroQ에 넣는다.

                if(successor->indegree == 0) {
                    zeroQ.push(*successor);
                }
            }
            
        }
        
        
        //결과를 출력한다.
        for(TopologicalSortVertex vertex : topologicalSort) {
            printf("%d ", vertex.value);
        }
        
        
        return topologicalSort;
    }
    
    void topologicalSortTest(){
        vector<TopologicalSortVertex> graph;
        
        TopologicalSortVertex five = {5, 2};
        
        
        TopologicalSortVertex four = {4, 2};
        four.link.push_back(&five);
        TopologicalSortVertex three = {3, 2};
        three.link.push_back(&five);
        
        TopologicalSortVertex two = {2, 1};
        two.link.push_back(&four);
        two.link.push_back(&three);
        
        TopologicalSortVertex one = {1,1};
        one.link.push_back(&four);
        one.link.push_back(&three);
        
        TopologicalSortVertex zero = {0,0};
        zero.link.push_back(&one);
        zero.link.push_back(&two);
        
        graph.push_back(zero);
         graph.push_back(one);
         graph.push_back(two);
         graph.push_back(three);
         graph.push_back(four);
         graph.push_back(five);
        
        topologicalSort(&graph);
    }
    
    void criticalPath(vector<cpState *> g) {
        vector<int> ecs;
        vector<int> lcs;
        
        
        //0 그래프의 위상 순서를 구한다.
        queue<cpState> zeroQ; //진입차수가 0인 정점이 모여 있는 큐
        vector<cpState> topologicalSort; //위상 정렬된 결과
        
        for(cpState *vertex : g) {
            if(vertex->indegree == 0) {
                zeroQ.push(*vertex);
                break;
            }
        }
        
        if(zeroQ.empty()) {
            printf("cannot find ciritical pathbecasue there is a cycle");
            return; //빈 벡터 반환
        }
        
        while(!zeroQ.empty()) {
            //진입 차수가 0인 것 하나를 꺼낸다.
            cpState vertex = zeroQ.front();
            zeroQ.pop();
            
            //꺼낸 정점을 위상 정렬 결과에 집어 넣는다.
            topologicalSort.push_back(vertex);
            
            //꺼낸 정점에 간선으로 연결된 모든 정점에서 진입 차수를 1씩 뺀다.
            for(cpActivity *edge : vertex.link) {
                edge->end->indegree = edge->end->indegree - 1;
                //진입 차수가 0이 되면 zeroQ에 넣는다.
                
                if( edge->end->indegree == 0) {
                    zeroQ.push(*edge->end);
                }
            }
            
        }

        
        //1 위상 순서대로 EC를 계산한다.
        ecs.push_back(0); //EC(0) 0
        //다음 단계에서 쓸 역참조 리스트를 만들어준다.
        vector<list<cpActivity *>> whosinmyback;
  //      whosinmyback.resize(g.size()); //벡터의 크기를 직접 정해주는 것이다. 이렇게 하면 마치 같은 크기의 배열을 미리 할당해놓고 쓰는 것 처럼 할 수 있다.
        //http://www.cplusplus.com/reference/vector/vector/resize/
        //역참조리스트를 초기화 한다.
        for(int i = 0; i < g.size(); i++) {
            whosinmyback.push_back(list<cpActivity*>());
        }
        
        
        for(int i = 0; i < topologicalSort.size(); i++) {
            
            
           //최단 아니 최장 경로 알고리즘을 여기서 써야 한다. 왜냐면, 가장 큰 값을 찾는 경로를 여기서 찾고 있기 때문이다.
            for(cpActivity *e : topologicalSort[i].link) {
                //EC(j) = max{ec(i) + weight(i,j), 모든 j}
                int newEc = ecs[e->start->value] + e->weight;
                
                //해당 정점을 목적지로 하는 모든 간선의 리스트를 만든다.
                whosinmyback[e->end->value].push_back(e);
                
//                if(newEc > ec) {
//                    ec = newEc;
//                }
//            }
//            
//            ecs.push_back(ec);
                
            }
            
        }
        
        
        //2 위상 순서의 반대로 LC를 계산한다.
        lcs.resize(ecs.size());
        lcs[ecs.size() - 1] = ecs[ecs.size() -1]; //LC(n-1) = EC(n-1)
        
        //자신을 목적지로 갖는 정점의 목록이 필요하다. 진입 차수로는 알 수 없는 것인가...
        //간선에서 출발지를 갖고 있긴 하지만, 도착지 정점은 정작 누가 자신을 참조하는 지 모른다.
        //위에서 EC를 만들려고 순회 할 때 미리 저장해놔야겠다.
        for(int i = topologicalSort.size() - 1; i >= 0; i--) {
            int lc = 0;
            
                for(cpActivity *edge : whosinmyback[i]) {
                    int newLc = lcs[edge->end->value] + edge->weight;
                    if(newLc < lc) {
                        lc = newLc;
                    }
                
            }
            
            lcs[i] = lc;
        }
        
        list<cpActivity *> criticalPath; //임계 경로
        
        //3 임계도를 계산한다.
        for(int i = 0; i < topologicalSort.size(); i++) {
            cpState state = topologicalSort[i];
            
            for(cpActivity* edge : state.link) {
                edge->ciriticality = lcs[edge->end->value] - (ecs[i] + edge->weight);
                //임계도가 0인 간선은 임계 경로로 가져간다.
                if(edge->ciriticality == 0) {
                    criticalPath.push_back(edge);
                }
            }
        }
        
        
        //4 임계경로를 구했으니, 출력한다.
        for(cpActivity *edge : criticalPath) {
            printf("%d -> %d", edge->start->value, edge->end->value);
        }
    }
    
    
    void criticalPathTest() {
        vector<cpState *> g;
        
        cpState zero = {0,0};
        cpState one = {1, 1};
        cpState two = {2,1};
        cpState three = {3,1};
        cpState four = {4,1};
        cpState five = {5,3};
        cpState six = {6,2};
        
        cpActivity a0 = {4, 0, &zero, &one};
        cpActivity a1 = {2, 0, &zero, &two};
        cpActivity a2 = {3, 0, &zero, &three};
        cpActivity a3 = {5, 0, &one, &six};
        cpActivity a4 = {3, 0, &one, &five};
        cpActivity a5 = {1, 0, &two, &four};
        cpActivity a6 = {4, 0, &three, &five};
        cpActivity a7 = {2, 0, &four, &five};
        cpActivity a8 = {5, 0, &five, &six};
        
        
        zero.link = {&a0,&a1,&a2};
        one.link = {&a3, &a4};
        two.link = {&a5};
        three.link = {&a6};
        four.link = {&a7};
        five.link = {&a8};
        
        g.push_back(&zero);
        g.push_back(&one);
        g.push_back(&two);
        g.push_back(&three);
        g.push_back(&four);
        g.push_back(&five);
        g.push_back(&six);
        
        criticalPath(g);
        
    }

}