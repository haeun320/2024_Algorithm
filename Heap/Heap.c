#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

int H[MAX_HEAP_SIZE];
int n = 0;

void swap(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void upHeap(int i) {
  // 루트노드 도달
  if (i == 1)
    return;
  
  // 최대힙 구현
  if (H[i] > H[i/2]) {
    swap(&H[i], &H[i/2]);
    upHeap(i/2);
  }
}

void downHeap(int i) {
  // 범위 밖
  if (2*i > n)
    return;

  // 더 큰 자식노드 찾기
  int larger = 2 *i;
  if (2*i+1 <= n && H[2*i+1] > H[2*i])
    larger = 2*i+1;
  
  // 자식노드보다 크면 downHeap 종료
  if (H[i] >= H[larger])
    return;
  
  swap(&H[i], &H[larger]);
  downHeap(larger);
}

// 삽입식 힙 생성
void insertItem(int key) {
  n++;
  H[n] = key;
  upHeap(n);
  printf("0\n");
}

// 재귀적 상향식 힙 생성
void rBuildHeap(int i) {
  if (i > n) return;

  rBuildHeap(2*i);
  rBuildHeap(2*i+1);
  downHeap(i);
  return;
}

// 비재귀적 상향식 힙 생성
void buildHeap(){
  for (int i = n/2; i >= 1; i--) {
    downHeap(i);
  }
  return;
}

int removeMax() {
  int key = H[1];
  H[1] = H[n];
  n--;
  downHeap(1);
  return key;
}

void printHeap() {
  for (int i = 1; i <= n; i++) {
    printf(" %d", H[i]);
  }
  printf("\n");
}

int main(){
  while (1) {
    char op;
    int key;
    scanf(" %c", &op);

    switch (op)
    {
    case 'i':
      scanf(" %d", &key);
      insertItem(key);
      break;
    case 'd':
      printf("%d\n", removeMax());
      break;
    case 'p':
      printHeap();
      break;
    case 'q':
      return 0;
    default:
      break;
    }
  }

  return 0;
}