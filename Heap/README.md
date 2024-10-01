# 힙과 힙 정렬

## 힙

- 힙 순서: 루트를 제외한 모든 내부 노드 v에 대해 `key(v) >= key(parent(v))` 를 만족한다
- 완전이진트리로 구성된다

<img width="243" alt="image" src="https://github.com/user-attachments/assets/27168ae7-56aa-4936-9e46-ca9fdb1aa6a4">

## 힙을 이용한 우선순위 큐 구현

*최소 힙 기준 설명

### 삽입식 힙 생성

<img width="458" alt="image 1" src="https://github.com/user-attachments/assets/53e5f309-8ed9-46f7-9a8e-c60143506c6a">


```
Alg insertItem(k)
	input key k, node last
	output none
	
1. advanceLast()
2. z <- last
3. Set node x to k
4. expandExternal(z)
5. upHeap(z)
6. return
```

```
Alg upHeap(v)
	input node v
	output none
	
1. if (isRoot(v))
	return
2. if (key(v) >= key(parent(v))
	return
3. swapElements(v, parent(v))
4. upHeap(parent(v))
```

### 재귀적 상향식 힙 생성

```
Alg rBuildHeap(i)
	input root index i of current subTree, non-heap array H
	output heap array H

1. if (i > n) // 전역변수 n
	return
2. rBuildHeap(2i) // 현재 서브트리의 왼쪽 서브트리를 힙 생성
3. rBuildHeap(2i + 1) // 현재 서브트리의 오른쪽 서브트리를 힙 생성
4. downHeap(i) // 현재 서브트리의 루트와 좌우 서브트리를 합친 힙 생성
5. return
```

### 비재귀적 상향식 힙 생성

```
Alg buildHeap()
	input non-heap array H
	output heap array H
	
1. for i <- n/2 downto 1
	downHeap(i)
2. return
```

### 루트 키 삭제
<img width="445" alt="image 2" src="https://github.com/user-attachments/assets/28e71231-5542-4edf-86c1-44e78372f44c">

```
Alg removeMin()
	input node last
	output key
	
1. k <- key(root())
2. w <- last
3. Set root to key(w) 
4. retreatLast()
5. z <- rightChild(w)
6. reduceExternal(z)
7. downHeap(root())
8. return k
```

```
Alg downHeap(k)
	input node v whose left and right subtrees are heaps
	output a heap with root v
	
1. if (isExternal(leftChild(v)) & isExternal(rightChild(v))
	return
2. smaller <- leftChild(v)
3. if (isInternal(rightChild(v))
	if (key(rightChild(v)) < key(smaller))
		smaller <- rightChild(v)
4. if (key(v) <= key(smaller))
	return
5. swapElements(v, smaller)
6. downHeap(smaller)
```

## 순차힙 성능

- size, isEmpty: O(1)
- insertItem, removeMin: O(logn)
- minKey, minElement: O(1)
- advanceLast, retreatLast: O(1)
- 공간소요: O(n)


## 제자리 힙 정렬

<aside>
💡

입력 리스트의 일부를 가상 힙으로 사용해 정렬

</aside>

배열의 왼쪽은 힙을 구성하는 원소를, 오른쪽은 아직 힙에 편입되지 않은 원소를 나타낸다.

**1기**

- 비어 있는 힙에서 출발해, 단계 *i*(i = 1, …, n)에서 첨자 *i*에 있는 원소를 힙에 추가함으로써 힙을 확장한다.
- 왼쪽에서 오른쪽으로 한 번에 한 칸씩 이동한다.

**2기**

- 비어 있는 리스트에서 출발해, 단계 *i*(i = n, …, 2)에서 힙의 최대 원소를 삭제하여 리스트의 첨자 *i*에 저장함으로써 리스트를 확장한다.

<img width="373" alt="image 3" src="https://github.com/user-attachments/assets/20b5f98d-e3aa-4a8f-866c-1812510a568a">
<img width="403" alt="image 4" src="https://github.com/user-attachments/assets/3ab2ad0e-3ced-4d38-87c3-3ebf5ebf3697">

```
Alg inPlaceHeapSort(A)
	input array A of n keys
	output sorted array A
		
1. buildHeap(A) // 1기
2. for i <- n downto 2
	A[1] <-> A[i]
	downHeap(1, i-1) 
3. return
```
