#include <iostream>
#include <list>
#include <stdlib.h>
using namespace std;
#define MAX_VERTEX 1000
/*
template <typename L>
class Node{
public:
	Node(){}
	Node(int a,int b, int c){
		n[0] = a, n[1]=b, n[2]=c;
		child = NULL;
		parent = NULL;
	}
	int n[3];
	Node *child;
	Node *parent;
};
*/


typedef struct {
	int n;
	int adj[MAX_VERTEX][MAX_VERTEX];
} GraphType;

void initGraph(GraphType *g){
	g->n=0;
	for(int i = 0 ; i<MAX_VERTEX; i++){
		for(int j=0 ; j<MAX_VERTEX ; j++) {
			g->adj[i][j] = 0;
		}
	}
}

void InsertVertex(GraphType *g,int v) { 
    if((g->n)+1 > MAX_VERTEX) { 
        printf("정점 갯수 초과\n"); 
        exit(-1); 
    } 
    g->n++; 
} 

void InsertEdge(GraphType *g,int start,int end) { 
    if(start >= g->n || end >= g->n) { 
        printf("잘못된 정점 입력\n"); 
        exit(-1); 
    } 
    g->adj[start][end]=1;  
    g->adj[end][start]=1; 
} 
/*8
int another(int arr2[], int j, int dead){
	for(int i=0 ; i<MAX_VERTEX ; i++) {
		if ( arr2[i] > 2 ){
			another(arr2, i, dead);
		} else {
			dead++;
		}
	}
	return dead;
}
*/

//list<Node*> input, graph;
/*
int main() {
	int n=0;
	cin >> n;
	int arr[1000][4];
	//list<int> ;
	int dead=0;

	GraphType graph;
	initGraph(&graph);
	//n = MAX_VERTEX
	
	for( int i=0 ; i<n ; i++ ) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		InsertVertex(&graph, i);
		// int a,b,c;
		// cin>>a>>b>>c;
		// input.push_back(new Node(a,b,c));
	}

	for( int i=0 ; i<n; i++) {
		for( int j=0 ; j<n ; j++) {
			if( arr[i][0] >= arr[j][0] && arr[i][1] >= arr[j][1] && arr[i][2] >= arr[j][2] ) {
				InsertEdge(&graph, i, j);
				arr[i][3]++;
				//이미 간선이 있는 경우, continue; //그냥 덮어씀
			}			
			if( arr[i][3] > 2 ) {
				//다른 간선의 부모 노드로 가서 재귀
				//연결된 간선들을 구하기 -> 재귀
				int arr2[MAX_VERTEX];
				for( int k=0 ; k<n ; k++ ) {
					arr2[k]=arr[k][3];
				}
				//dead = another(arr2, j, dead);
			} else {
				//간선제거, 잡아먹음
				dead++;
			}
		}
	}

	cout << n-dead << endl;
	
	return 0;
}
*/