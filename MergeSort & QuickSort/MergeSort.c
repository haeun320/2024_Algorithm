#include <stdio.h>
#include <stdlib.h>

// ----------------- 단일 연결 리스트 구현 -----------------
typedef struct Node{
  int data;
  struct Node *next;
}Node;

typedef struct {
  Node *H;
  int size;
}LinkedList;

void initList(LinkedList* L) {
  L->H = NULL;
  L->size = 0;
}

int isEmpty(LinkedList *L) {
  return L->size == 0;
}

void addNode(LinkedList* L, int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;

  if (L->H == NULL){
    L->H = node;
  }
  else {
    Node* p;
    for (p = L->H; p->next != NULL; p = p->next);
    p->next = node;
  }

  L->size++;
}

int deleteFirst(LinkedList *L) {
  int delData = L->H->data;
  L->H = L->H->next;
  L->size--;
  return delData;
}

void printList(LinkedList* L) {
  Node* p = L->H;
  for (Node* i = p; i != NULL; i = i->next) {
    printf(" %d", i->data);
  }
}

// ----------------- 합병 정렬 구현 -----------------
Node* merge(LinkedList *L1, LinkedList *L2) {
  LinkedList *L = (LinkedList*)malloc(sizeof(LinkedList));
  initList(L);

  while (!isEmpty(L1) && !isEmpty(L2)) {
    if (L1->H->data <= L2->H->data) {
      addNode(L, deleteFirst(L1));
    }
    else {
      addNode(L, deleteFirst(L2));
    }
  }

  while (!isEmpty(L1))
    addNode(L, deleteFirst(L1));
  
  while (!isEmpty(L2))
    addNode(L, deleteFirst(L2));

  return L->H;
}

void partition(LinkedList *L, int k, LinkedList *L1, LinkedList *L2) {
  L1->H = L->H;
  L1->size = k;

  Node *p = L->H;
  for (int i = 0; i < k ; i++)
    p = p->next;

  L2->H = p;
  L2->size = L->size - k;
}

void mergeSort(LinkedList *L) {
  if (L->size > 1) {
    LinkedList L1, L2;
    initList(&L1);
    initList(&L2);

    partition(L, L->size / 2, &L1, &L2);

    mergeSort(&L1);
    mergeSort(&L2);

    L->H = merge(&L1, &L2);
  }
}

int main() {
  LinkedList L;
  initList(&L);

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int data;
    scanf("%d", &data);
    addNode(&L, data);
  }

  mergeSort(&L);

  printList(&L);
  return 0;
}