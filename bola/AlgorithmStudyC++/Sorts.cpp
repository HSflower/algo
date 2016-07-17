//
//  Sorts.cpp
//  AlgorithmC++
//
//  Created by 김윤철 on 2016. 6. 26..
//  Copyright © 2016년 bolastudy. All rights reserved.
//

#include "Sorts.hpp"

//선택 정렬
/*
 5 3 4 1 2
 1 3 4 5 2
 1 2 4 5 3
 1 2 3 5 4
 1 2 3 4 5
 1 2 3 4 5
 */


int* selectionSort(int* array, int length) {
    
    for(int i = 0; i < length ; i++) {
        int indexOfMin = i;
        int min = array[i];
        
        //i번째 인덱스 이상에서 가장 작은 값 찿기
        for(int j = i + 1; j < length; j++) {
            
            if(min > array[j]) {
                min = array[j];
                indexOfMin = j;
            }
        }
        
        //자리 바꾸기
        int temp = array[i];
        array[i] = min;
        array[indexOfMin] = temp;
    }
    
    
    return array;
}

//버블 정렬
/*
 5 3 4 1 2
 3 5 4 1 2
 3 4 5 1 2
 3 4 1 5 2
 3 4 1 2 5
 3 4 1 2 5
 3 1 4 2 5
 3 1 2 4 5
 1 3 2 4 5
 1 2 3 4 5
 */
int* bubbleSort(int* array, int length) {
    
    
    //뒤부터 정렬되기 시작하는 녀석이라 매번 정렬해야 할 길이가 1씩 줄어든다
    for(int i = length - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(array[j] > array[j + 1]) {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
    
    return array;
}

//삽입 정렬
/*
 5 3 4 1 2
 3 5 4 1 2
 3 4 5 1 2
 1 3 4 5 2
 1 2 3 4 5
 */
int* insertionSort(int* array, int length){
    
    //key의 원소보다 크다면 다 오른쪽으로 밀어버린다
    for(int i = 1; i < length; i++) {
        
        int key = array[i];
        int j = i;
        
        //조심! 메모리가 정리가 안 되어 있다면, j가 0보다 작을 때 돌아갈 수 도 잇다!
        while(array[j - 1] > key && j > 0) {
            array[j] = array[j - 1];
            j = j - 1;
        }
        
        array[j] = key;
    }
    
    return array;
}
//쉘 정렬
/*
 h-4
 5 3 4 1 2 [5 1] -> [1 5]
 1 3 4 5 2
 h-1 일반 삽입정렬이랑 똑같음
 1 2 3 4 5
 
 멀리 떨어진 원소와의 교환이 가능하기 때문에 일반 삽입 정렬보다 빠르다고 함.
 */

int* shellSort(int* array, int length){
    
    // h(i) = h(i -1) * 3 + 1
    // h값을 감소시키면서 진행된다. h = h / 3
    //초기 h값을 계산
    int h = 1;
    while(h < length) {
        h = h * 3 + 1;
    }
    
    //각각의 h번째 배열 원소에 대해 삽입정렬 시도
    //h가 0보다 클 동안 h를 감소시켜 가며 반복
    for(; h > 0; h = h/3) {
        
        //h번째 앞에 있는 애들도 다 옮기긴 해야 하니까.
        for(int i = h; i < length; i++) {
            
            int key = array[i];
            int j = i;
            
            //j는 0 부터 length - 1까지 가능하기 때문이다. 난 인덱스가 0부터 시작하기 때문에, 피피티와는 많이 다를 수도 있다.
            while(j >= h && (array[j - h] > key) ) {
                array[j] = array[j-h];
                j = j - h;
            }
            
            array[j] = key;
        }
        
    }
    
    return array;
}

//일반적인 퀵정렬
/*
 6 2 8 1 3 9 4 5 10 7 <- pivot
 6 2 5 1 3 9 4 8 10 7
 6 2 5 1 3 4(p) 7 8 10 9 -- 4 become a new pivot (그전에, 맨 앞의 큰 값)
 3 2 5 1 6 4 7 8 10 9
 3 2 1 5 6 4 7 8 10 9
 3 2 1(p) 4 6 5 7 8 10 9
 1 2 3(p) 4 6 5 7 8 10 9
 1 2 3 4 6 5(p) 7 8 10 9
 1 2 3 4 5 6 7 8 10 9(p)
 1 2 3 4 5 6 7 8 9 10
 */

//재귀 호출 사용
int* quickSortRecursive(int* array, int l, int r) {
    
    if(r > l) {
        int pivot = partition(array, l, r); //이전에 사용된 피봇 위치
        quickSortRecursive(array, l, pivot - 1);
        quickSortRecursive(array, pivot + 1 , r);
    }
    
    return array;
}

int partition(int* array ,int l, int r){ //파티션 함수. 이번 피봇의 인덱스를 반환
    int pivot = array[r]; ///가장 오른쪽의 원소가 피봇
    int i = l - 1; //왼쪽에서 오른쪽으로 움직이며, pivot보다 큰 값을 찾는 인덱스
    int j = r; //오른쪽에서 왼쪽으로 움직이며, pivot 보다 작은 값을 찾는 인덱스
    
    while(true) {
        
        //do while은 무조건 한 번은 실행한다. 이 것이 큰 차이를 불러일으키니 함부로 바꾸지 말것!
        do {
            i = i + 1; //오른쪽으로
        }while(array[i] < pivot);
        
        do {
            j = j - 1; //왼쪽으로
        }while(array[j] > pivot);
        
        
        if(i >= j) {
            break;
        }
        //자리 교환
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    
    //pivot을 가장 왼쪽의 pivot보다 큰 값고 ㅏ자리를 바꾼다
    int temp = array[r];
    array[r] = array[i];
    array[i] = temp;
    
    return i;
}

//퀵 정렬 스택 사용
int* quickSortStack(int* a, int l, int r) {
    //스택에 l, r을 저장해 두면, 다음에 정렬을 해야할 부분을 찾아갈 수 있다.
    stack<int> pivots;
    int pivot;
    
    int left = l;
    int right = r;
    
    for(;;) {
        while(right > left) {
            pivot = partition(a, left, right);
            
            //왼쪽 부분 배열을 돌 때
            if(pivot - l > r - pivot) {
                pivots.push(left);
                pivots.push(pivot-1);
                left = pivot + 1;

            }
            else {
                pivots.push(pivot+1);
                pivots.push(right);
                right = pivot - 1;

            }
            
            
            if(pivots.empty()) {
                break;
            }
            
            
            right = pivots.top();
            pivots.pop();
            
            left = pivots.top();
            pivots.pop();
        }
        
        
        if(pivots.empty()) {
            break;
        }
    }
    
    
    
    return a;
}


/*
 1 2 3 6 8 4 5 7 9 10
 1 2 3 4 5 6 7 8 9 10
 */


//합병 정렬 -- 재귀
int* mergeSort(int* array, int l, int r) {
    //반으로 분할한다.
    if(r > l) {
        int m = (r + l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
    
    return array;
}

//자연 합병 정렬
int* naturalMergeSort(int* array, int l, int r){
    
    //반이 아니라, 순서가 끊기는 부분부터 나눈다.
    if(r > l) {
        int m = (r + l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
    return array;
}

void merge(int* array, int l, int m, int r) {
    
    //합병할 결과를 원래 배열로 옮기기 전에 사용할 임시 배열. 크기는 합병할 두 배열 만큼의 크기
    int tempArray[(r+l+1)/2];
    int i = l;
    int j = m + 1;
    int k = l;
    //l -> m, m+1 -> r까지의 분리된 두 배열의 원소를 앞에서 하나씩 꺼내 비교하고 큰 값을 집어 넣는다
    while(i <= m && j <= r){
        if(array[i] < array[j]) {
            tempArray[k] = array[i];
            i++;
            k++;
        }
        else {
            tempArray[k] = array[j];
            j++;
            k++;
        }
    }
    
    // 만약에, 합병 할 두 배열 중 하나가 다 쓰이지 못했다면 그를 정리해 준다.
    if(i > m) {
        for(int p = j ; p <= r; p++) {
            tempArray[k] = array[p];
            k++;
        }
    }
    else {
        for(int p = i ; p <= m; p++) {
            tempArray[k] = array[p];
            k++;
        }
    }
    
    
    
    //임시 배열에서 원래 배열의 자리로 복사한다.
    for(int i = l; i <= r; i++) {
        array[i] = tempArray[i];
    }
}

int* heapSort(int *array, int length) {
    //들어온 배열을 가장 먼저 힙화 시킨다.
    //이것은 상향식 구성 방법으로, 들어온 힙의 N/2 번째 노드부터 힙화 시킨다(들어온 완전 이진 트리라고 가정, 그러면 완전 이진 트리를 배열로 구현했을 때의 특성으로, N/2번 노드 이후의 노드들은 모두 리프노드이다.)
    int n = length-1;
    
    for(int i = (n/2); i >= 0; i--) {
        heapify(array, i, n);
    }
    
    for(int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    //힙에서 하나씩 삭제하며 정렬한다.
    for(int i = n-1; i >= 0; i--) {
        
        int temp = array[0];
        array[0] = array[i+1]; //0번째 노드를 삭제한 것 처럼 뒤로 옮긴다. 뒤부터 정렬된 결과가 쌓인다.
        array[i+1] = temp;
        
        //삭제가 일어났으므로 재 힙화 한다.
        //머리만 바뀐 것이므로, 루트 노드만 힙화를 돌리면 자동적으로 힙이 다시 돌아온다. 힙의 삭제 부분 참조.
        heapify(array, 0, i); //뒤의 정렬된 결과를 제외하고 아직 정렬이 안된 남은 힙만 다시 힙화하는 것이다!
        
     }
    

    return array;
}

//주어진 배열을 힙화 시킨다. h 루트의 위치, m 힙의 길이
int* heapify(int* array, int h, int m) {
    
    //m번쨰 원소를 힙의 루트라고 생각하고, 그 자식들을 포함한 서브트리를 힙화한다.
    //루트의 원소가 리프노드로 이동할 때 까지 반복한다.
    //리프노드인 경우, 왼쪽 자식 i조차도 배열의 범위를 벗어난다는 점을 이용한다.
    int v = array[h];
    
    
    for(int i = h * 2; i <= m ; i = i * 2) {
        //pos 현재 위치
        //i pos의 왼족 자식
        //i+1 pos의 오른쪽 자식
        
        
        //그것이 아니라면, 둘 중 큰 원소와 자리를 바꾼다.
        //그 전에, i가 힙의 범위 내에 있을 때만
        if(i < m && array[i] < array[i+1]) {
            i = i + 1;
        }
        
        //부모가 자식보다 크다면 그냥 멈추고 나간다.
        if(v >= array[i]) {
           return array;
        }
        else {
        //자리바꾸기
            array[i/2] = array[i];
        }
        //pos ,i, j의 인덱스를 다시 바꾼다.
         array[i] = v;
    }
    
    
    return array;
}


void sortTest() {
    
    int a[] = {1,2,3,6,8,4,5,7,9,10}; // 1 2 3 3 4 5 8 9
    int length = sizeof(a) / sizeof(int);
    
    for(int i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    heapSort(a, length);
    
    for(int i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
}
