#include <iostream>
#include <string>
#include <list>
using namespace std;

//���Ḯ��Ʈ : �������� / ����/����ƮSTL
//�������� �ε��� = �������� �ε���-1 + K
//������ ù����ΰ��, -1�� (�����ܰ�����ü����=N-1)����������ε����� ������
//�ε����� +������ �ε��� ��ü���̸� �ʰ��ϸ� 1���� �ٽý����ϵ���

typedef struct node {
	int data;
	node* link;
} node;

/* Ư���� ���� ��� �ڽ��� ��ġ�� ǥ���ϱ� ���� �ڱ����� ����ü��� �����̴�. 
 �ڱ� �ڽ��� ����ü ����� ������ ���ϴ� ��� �ڱ� �ڽ� Ÿ���� �����͸� ����� �������μ�,
 �������� �ּҰ��� ǥ���ϴ� ���̴�. �� ����ü�� �ڱ� �ڽ��� ����� �� �����İ�?
 ����ü�� �׻� ���� ũ���� �޸� ������ �Ҵ�޾ƾ� �ϴµ� �ڱ� �ڽ��� ����� �����ٸ� �� '���� ũ��'�� �� �� ���� �����̴�. �׷��� �ڱ� �ڽſ� ���� �����ʹ� ũ�Ⱑ �׻� 4����Ʈ(32��Ʈ OS)�� 8����Ʈ(64��Ʈ OS)�� ����. �׷��� ����ü�� ��ü ũ�⸦ ��� �����ϴ�.
 �׷� Java������ ��� �ڱ� �ڽ��� ����� ���Խ�Ű�İ�? �ڹ��� Ŭ������ ���۷��� ������ �Ѵ�. ���۷����� ���� ��� Ÿ���� �����Ϳ� ���� �����̴�. ���۷����� ����̸鼭 ������ �Ұ����� �����Ϳ� �����ϴ�. */
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
//�����Ҵ� : list<int>* clList = new list<int>;

//http://www.hanbit.co.kr/network/view.html?bi_id=1585
//iterator�ݺ��� : begin()ù��°��ҹݺ��ڹ�ȯ end()�����������
int main() {

	return 0;
}

/*����
void josephus(int n, int k){
 //����Ʈ�� �غ��Ѵ�
 list<int> survivors;
 for(int i=1; i<=n; ++i) survivors.push_back(i);
 //�̹������������ ��Ÿ���� ������
 list<int>::iterator kill=survivors.begin();
 while(n>2){
 //ù��°����ڻ�, erase()�� ���� ������ �������Ҹ� ��ȯ�Ѵ�.
	kill = survivors.erase(ill);
	if(kill==survivors.end()) kill=survivors.begin();
	--n;
	//k-1�� ����������� �̵�
	for(int i=0; i<k-1; ++i){
		++kill;
		if(kill==survivors.end()) kill = survivors.begin();
		}
	}
	cout<<survivors.front()<<" "<<survivors.back()<<endl;
}
*/
