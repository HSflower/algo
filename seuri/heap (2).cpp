#include<stdio.h> 
 /*
typedef struct {
// 큐의 원소 타입 
int key;// 우선순위 키 값을 표현 
char name[10]; 
char grade;
} element; 

typedef struct { 
	int length;// 실제로 우선순위 큐에 저장되어 있는 원소 수 
	int qSize;// 배열의 크기: 실제 최대 원소 수는 qSize-1 
	int increment;// 배열 확장 단위 
	int *data;// 우선순위 큐의 원소를 저장하는 배열 
	// 실제 원소는 data[1], data[2], . . . data[qSize]에 저장 
} priorityQ; 

int currentLength(priorityQ* pQ) {// 우선순위 큐의 현재 원소 수 
	return pQ->length; 
}

void queueFull(priorityQ* pQ) {   
//data[]가 만원이면 increment만큼 더 확장 
	int i; 
    int* temp; 
	pQ->qSize += pQ->increment; 
	temp = (int*)malloc((pQ->qSize)*sizeof(int)); 
	for (i=1; i < pQ->length; i++) { 
		temp[i] = pQ->data[i]; 
	} 
	free(pQ->data); 
	pQ->data = temp; 
} 

int delete(priorityQ* pQ) {
// 우선순위가 제일 높은 원소를 삭제 
	int currentLoc; 
	int childLoc; 
	int itemToMove;// 이동시킬 원소 
	int deletedItem; // 삭제한 원소 
	if (pQ->length == 0) {// 우선순위 큐가 공백인 경우 
		printf("Queue is empty\n"); 
		exit(1); 
}
	       else { 
              deletedItem = pQ->data[1];       // 삭제하여 반환할 원소 
              itemToMove = pQ->data[(pQ->length)--];   // 이동시킬 원소 
              currentLoc = 1; 
              childLoc = 2*currentLoc; 
              while (childLoc <= pQ->length) {   // 이동시킬 원소의 탐색 
                    if (childLoc < pQ->length) { 
                          if (pQ->data[childLoc+1] > pQ->data[childLoc])
                                  childLoc++; 
                         }
                    if (pQ->data[childLoc] > itemToMove) {   // 원소를 한 레벨 위로 이동
                           pQ->data[currentLoc] = pQ->data[childLoc]; 
                           currentLoc = childLoc; 
                           childLoc = 2*currentLoc; 
                    } 
                    else {   // 이동시킬 원소 저장 
                           pQ->data[currentLoc] = itemToMove;  
                           return deletedItem; 
                    } 
              } 
              pQ->data[currentLoc] = itemToMove;    // 최종 위치에 원소 저장
              return deletedItem; 
        } 
   } 
  void insert(priorityQ* pQ, int item) {    // 히프로 구현된 우선순위 큐에 원소 삽입 
        if (pQ->length == pQ->qSize - 1) queueFull(pQ); 
	// 큐가 만원이면 먼저 큐를 확장 
        pQ->length++;   
	// 삽입공간을 확보하고 원소의 삽입위치를 밑에서부터 찾아 올라감 
        int childLoc = pQ->length; 
       int parentLoc = childLoc/2; 
        while (parentLoc != 0) { 
               if (item <= pQ->data[parentLoc]) {  // 위치가 올바른 경우에 원소 삽입 
                     pQ->data[childLoc] = item;      
                     return; 
               } 
               else {     // 한 레벨 위로 이동 
                     pQ->data[childLoc] = pQ->data[parentLoc]; 
                     childLoc = parentLoc; 
                     parentLoc = childLoc/2; 
               } 
        } 
        pQ->data[childLoc] = item;   // 최종 위치에 원소 삽입 
  }

     void priorityQsort(priorityQ* pQ, int* a, int n) {
	// 배열 a[]의 원소를 우선순위 크기의 역순으로 정렬 
       int i;
       for (i = 1; i < n; i++) {
	// 배열 a[]의 원소를 우선순위 큐 pQ에 전부 삽입 
            insert(pQ, a[i]); 
       }
       for (i = n-1; i > 0; i--) {
	// 우선순위가 큰 원소가 인덱스가 크게 저장 
            a[i] = delete(pQ);
       } 
   } 
   priorityQ* createPriorityQ(void) {   // 공백 우선순위 큐의 생성 
       priorityQ*  pQ; 
       pQ = (priorityQ*)malloc(sizeof(priorityQ)); 
       pQ->length = 0; 
       pQ->qSize = 16;   // 실제 최대 원소 수는 qSize-1 
       pQ->increment = 8; 
       pQ->data = (int*)malloc(pQ->qSize*sizeof(int));  
 	// 우선순위 큐를 배열로 표현하는 히프로 구현하기 때문에 
 	//  data[0]는 인덱스가 0이 되어 실제로 사용하지 않음 
       return pQ;
	}
	   void freeQueue(priorityQ* pQ) {   // 우선순위 큐에 할당된 메모리를 반환
       free(pQ->data); 
       free(pQ);
   } 
   int main() {// 예제 실행을 위한 main() 함수 
       int input[] = {100, 30, 50, 120, 340, 200, 10};
       int n = 8;  // 정렬할 원소 수 +1 
       int i;
       int* a = (int*)malloc(8*sizeof(int));
       priorityQ* pQ;
       pQ = createPriorityQ();
       printf("Initial Input Values : ");
       for (i = 1; i < n; i++) {// 원소를 배열 a[]에 저장하고 프린트
            a[i] = input[i-1];     // a[0]는 인덱스가 0이기 때문에 원소를 저장하지 않음
            printf("%5d", a[i]);
       }
       printf("\n");
       priorityQsort(pQ, a, n);  // 배열 a[]의 원소를 우선순위 큐 pQ를 이용하여 정렬 
       for (i = 1; i < n; i++) {   // 정렬된 배열 a[]의 원소를 오름차순으로 프린트
            printf("%5d", a[i]);
       }
       printf("\n");
       free(a);// 배열 a[]에 할당된 메모리를 반환
       freeQueue(pQ);  // 우선순위 큐에 할당된 메모리를 반환
       return 0;
   } 


	*/