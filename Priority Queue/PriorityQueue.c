#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// 제자리 선택 정렬
void inPlaceSelectionSort(int A[], int n) { 
  for (int pass = n - 1; pass > 0; pass--) {
    int maxLoc = pass;
    for (int j = 0; j < pass; j++) {
      if (A[j] > A[maxLoc]) {
        maxLoc = j;
      }
    }

    if (maxLoc != pass) {
      swap(&A[pass], &A[maxLoc]);
    }
  }
}

// 제자리 삽입 정렬
void inPlaceInsertionSort(int A[], int n) {
  for (int pass = 1; pass < n; pass++) {
    int save = A[pass];
    int j = pass - 1;

    while ((j >= 0) && A[j] > save) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = save;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL)
    return -1;

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // inPlaceSelectionSort(arr, n);
  inPlaceSelectionSort(arr, n);

  for (int i = 0; i < n; i++) {
    printf(" %d", arr[i]);
  }
  free(arr);

  return 0;
}