#include <iostream>
#include <queue>
using namespace std;

/*
연산 내용 : g∈Graph,  u,v ∈V;
    createG() ::= create an empty graph;
    insertVertex(g, v) ::= insert vertex v into g;
    insertEdge(g, u, v) ::= insert edge (u, v) into g;
    deleteVertex(g, v) ::= delete vertex v and all edges incident on v from g;
    deleteEdge(g, u, v) ::= delete edge (u, v) from g;
    isEmpty(g) ::= if (g has no vertex) then return true, else return false;
    adjacent(g, v) ::= return set of all vertices adjacent to v;
End Graph
연결리스트, 순차표현으로 구현 가능
*/

class Node {
private:
	int vertex;
	Node* link;
public :
	Node(int _vertex, Node* _link = NULL) {
		vertex = _vertex, link = _link; };
		void setVertex(int _vertex) { vertex = _vertex; }
		void setLink(Node* _link) { link = _link; }
		int getVertex() { return vertex; }
		Node* getLink() {return link; }
};

class Graph {
private :
	Node** adjList;
	int numberOfVertex;
	bool isDirected;
public:
	Graph(int _numberOfVertex, bool _isDirected);
	void printGraph();
	void doDfs();
	void doBfs();
	void connectedComp();
private :
	void insertEdge(int x, int y, bool _isDirected);
	void dfs(int v, bool* visited);
	void bfs(int v, bool* visited);
};
Graph::Graph(int _numberOfVertex, bool _isDirected) {
	if(_numberOfVertex >0) numberOfVertex = _numberOfVertex;
	else { 
		cerr<<"정점의 수가 너무 적다"<<endl; 
		return;
	}
	isDirected = _isDirected;
	adjList = new Node*[numberOfVertex];

	for(int i=0; i<numberOfVertex; i++){
		adjList[i]=NULL;
	}

	for(int i=0; i<numberOfVertex; i++) {
		for(int j=0; j<numberOfVertex; j++) {
			int end; //간선의 머리가 되는 정점
			cout<<"정점" << i << "와 연결된 정점을 입력하세요. 입력종료시 -1: ";
			cin >> end;
			if(end <0 || end==i || end>=numberOfVertex)
				break;
			insertEdge(i, end, isDirected);
		}
	}
	cout << "그래프 생성이 완료되었습니다."<<endl;
}
void Graph::insertEdge(int x, int y, bool _isDirected) {
	if(adjList[x] == NULL) {//정점 x가 그 어떤 정점과도 연결되어있지 않을 때 {
		adjList[x] = new Node(y);
	}
	else if(adjList[x]->getLink() == NULL) { //정점x가 하나의 점과 연결되어있을때
		if(adjList[x]->getVertex() ==y) return;
		adjList[x]->setLink(new Node(y));
	}
	else {
		Node* w;
		for(w=adjList[x]; w->getLink(); w=w->getLink()) {
			if(w->getVertex() == y) return;
			w->setLink(new Node(y));
		}
	}
	
	if(_isDirected == false){
		insertEdge(y, x, true);
	}
}

void Graph::printGraph() {
	for(int i=0 ; i<numberOfVertex; i++) {
		cout<<i<<": ";
		for(Node* w=adjList[i]; w; w=w->getLink()){
			cout<<" "<<w->getVertex();
		}
		cout<<endl;
	}
}

void Graph::doDfs() {
	bool* visited = new bool[numberOfVertex];
	for(int i=0; i<numberOfVertex; i++) {
		visited[i] = false;
	}
	dfs(0, visited);
	cout<<endl;
	delete []visited;
}

void Graph::dfs(int v, bool *visited) {
	visited[v]=true;
	cout<<v<<' ';
	for(Node* w=adjList[v]; w; w=w->getLink()){
		if(visited[w->getVertex()] == false) {
			dfs(w->getVertex(), visited);
		}
	}
}

void Graph::doBfs() {
	bool* visited = new bool[numberOfVertex];
	for(int i=0; i<numberOfVertex; i++) {
		visited[i] = false;
	}
	bfs(0, visited);
	cout<<endl;
	delete []visited;
}

void Graph::bfs(int v, bool *visited) {
	queue<int> q;
	cout<<v<<' ';
	visited[v] = true;
	q.push(v);

	while(!q.empty()){
		v = q.front();
		q.pop();
		for(Node* w=adjList[v]; w; w=w->getLink()) {
			if(visited[w->getVertex()] == false) {
				cout<<w->getVertex() << ' ';
				q.push(w->getVertex());
				visited[w->getVertex()]=true;
			}
		}
	}
}

void Graph::connectedComp() {
	bool* visited = new bool[numberOfVertex];
	for(int i=0; i<numberOfVertex; i++) {
		visited[i] = false;
	}
	for(int i=0 ; i<numberOfVertex; i++) {
		if(visited[i] == false) {
			dfs(i, visited);
			cout<<endl;
		}
	}
	delete []visited;
}




int main() {
	Graph g(3,false);
	g.printGraph();
	g.printGraph();
	g.doDfs();
	g.doBfs();
	g.connectedComp();
	return 0;
}