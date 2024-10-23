#include <stdio.h>
#include <stdlib.h>

// 재귀
int rfindElement(int *arr, int k, int l, int r) {
  if (l > r)
    return r;
  
  int mid = l + (r - l) / 2;
  
  if (arr[mid] == k)
    return mid;
  else if (arr[mid] < k) 
    return rfindElement(arr, k, mid + 1, r);
  else
    return rfindElement(arr, k, l, mid - 1);
}

// 비재귀
int findElement(int *arr, int n, int k) {
  int left = 0;
  int right = n - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == k) {
      return mid;
    } 
    else if (arr[mid] < k) {
      left = mid + 1;
    } 
    else {
      right = mid - 1;
    }
  }

  return right;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  int *arr = (int*)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int result = rfindElement(arr, k, 0, n - 1);
  printf(" %d", result);

  return 0;
}