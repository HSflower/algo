#include <iostream>
#include <string>
#include <list>
using namespace std;

//연결리스트 : 직접구현 / 벡터/리스트STL
//다음죽을 인덱스 = 죽은거의 인덱스-1 + K
//죽은게 첫노드인경우, -1이 (다음단계의전체길이=N-1)마지막노드인덱스로 가도록
//인덱스에 +했을때 인덱스 전체길이를 초과하면 1부터 다시시작하도록

typedef struct node {
	int data;
	node* link;
} node;

/* 특이할 점은 노드 자신의 위치를 표시하기 위한 자기참조 구조체라는 개념이다. 
 자기 자신을 구조체 멤버로 가지지 못하는 대신 자기 자신 타입의 포인터를 멤버로 가짐으로서,
 스스로의 주소값을 표현하는 것이다. 왜 구조체가 자기 자신을 멤버로 못 가지냐고?
 구조체는 항상 고정 크기의 메모리 공간을 할당받아야 하는데 자기 자신을 멤버로 가진다면 그 '고정 크기'를 알 수 없기 때문이다. 그러나 자기 자신에 대한 포인터는 크기가 항상 4바이트(32비트 OS)나 8바이트(64비트 OS)로 같다. 그래서 구조체의 전체 크기를 계산 가능하다.
 그럼 Java에서는 어떻게 자기 자신을 멤버로 포함시키냐고? 자바의 클래스는 레퍼런스 참조를 한다. 레퍼런스라 함은 상수 타입의 포인터와 같은 개념이다. 레퍼런스는 상수이면서 연산이 불가능한 포인터와 동일하다. */
typedef struct LinkedList{
	int number;
	struct Linked_List* next;
};

class linklist{
private:
	node* head;
public:
	linklist();
	~linklist();
	void insert(int data);
	void remove(int data);
	void print();
};

list<int> clList;
//동적할당 : list<int>* clList = new list<int>;

//http://www.hanbit.co.kr/network/view.html?bi_id=1585
//iterator반복자 : begin()첫번째요소반복자반환 end()마지막욧다음
int main() {

	return 0;
}

/*정답
void josephus(int n, int k){
 //리스트를 준비한다
 list<int> survivors;
 for(int i=1; i<=n; ++i) survivors.push_back(i);
 //이번에죽을사람을 나타내는 포인터
 list<int>::iterator kill=survivors.begin();
 while(n>2){
 //첫번째사람자살, erase()는 지운 원소의 다음원소를 반환한다.
	kill = survivors.erase(ill);
	if(kill==survivors.end()) kill=survivors.begin();
	--n;
	//k-1번 다음사람으로 이동
	for(int i=0; i<k-1; ++i){
		++kill;
		if(kill==survivors.end()) kill = survivors.begin();
		}
	}
	cout<<survivors.front()<<" "<<survivors.back()<<endl;
}
*/
