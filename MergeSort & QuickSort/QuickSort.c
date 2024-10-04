#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int findPivot(int *L, int l, int r) {
  return l + rand() % (r - l + 1);
}

int inPlacePartition(int *A, int l, int r, int k) {
  int p = A[k]; 
  swap(&A[k], &A[r]);  
  int i = l;
  int j = r - 1;
  
  while (i <= j) {
    while (i <= j && A[i] <= p) {
      i++;
    }
    while (j >= i && A[j] >= p) {
      j--;
    }
    if (i < j) {
      swap(&A[i], &A[j]);
    }
  }
  swap(&A[i], &A[r]);
  return i;
}

void inPlaceQuickSort(int *L, int l, int r) {
  if (l >= r) return;
  
  int k = findPivot(L, l, r);
  int b = inPlacePartition(L, l, r, k);
  inPlaceQuickSort(L, l, b - 1);
  inPlaceQuickSort(L, b + 1, r);
}

void printList(int *L, int size) {
  for (int i = 0; i < size; i++) {
    printf(" %d", L[i]);
  }
  printf("\n");
}

int main() {
  srand(time(NULL));  

  int n;
  scanf("%d", &n);

  int *L = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &L[i]);
  }

  inPlaceQuickSort(L, 0, n - 1);

  printList(L, n);

  return 0;
}