#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

int H[MAX_HEAP_SIZE];
int n = 0;

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void upHeap(int i) {
  if (i == 1) return;
  
  if (H[i] > H[i/2]) {
    swap(&H[i], &H[i/2]);
    upHeap(i/2);
  }
}

void downHeap(int i, int last) {
  int larger;
  if (2*i > last) return;
  
  larger = 2*i;
  if (2*i+1 <= last && H[2*i] < H[2*i+1])
    larger = 2*i+1;
  
  if (H[i] < H[larger]) {
    swap(&H[i], &H[larger]);
    downHeap(larger, last);
  }
}

void buildHeap(){
  for (int i = n/2; i >= 1; i--) {
    downHeap(i, n);
  }
}

void inPlaceHeapSort() {
  buildHeap();

  for (int i = n; i > 1; i--) {
    swap(&H[1], &H[i]);
    downHeap(1, i-1);
  }
}

void printArray() {
  for (int i = 1; i <= n; i++) {
    printf(" %d", H[i]);
  }
  printf("\n");
}

int main() {
  int N;
  scanf("%d", &N);

  for (int i = 1; i <= N; i++) {
    scanf("%d", &H[i]);
    n++;
  }

  inPlaceHeapSort();
  printArray();

  return 0;
}