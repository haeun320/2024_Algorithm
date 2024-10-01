# 우선순위 큐

<aside>
💡

임의의 데이터 항목이 삽입되며, 일정한 순서에 의해 삭제되는 데이터 구조

(키, 원소) 쌍으로 저장됨

</aside>

- 우선순위 큐 데이터 삽입 방법
    - 무순리스트: 키를 고려하지 않은 삽입
    - 순서리스트: 키 순서대로 삽입


## 우선순위 큐 ADT 메소드

**주요 메소드**

- `insertItem(k, e)` : 키 k인 원소 e를 큐에 삽입
- `element removeMin()` : 큐로부터 최소 키를 가진 원소를 삭제하여 반환

**일반 메소드**

- `integer size()` : 큐의 길이 반환
- `boolean isEmpty()` : 큐가 비어있는지 여부 반환

**접근 메소드**

- `element minElement()` : 최소 키를 가진 원소 반환
- `element minKey()` : 최소 키 반환

**예외**

- `emptyQueueException()` : 비어있는 큐에 대해 삭제나 접근 시도
- `fullQueueException()` : 만원 큐에 대해 삽입 시도

## 우선순위 큐를 이용한 정렬

<aside>
💡

우선순위 큐에서 최소 키를 가진 원소부터 차례로 삭제 후 리스트에 삽입해 정렬된 리스트 얻기

</aside>

```Pseudocode
Alg PQ-Sort(L)
	input list L
	output sorted list L
	
1. P <- empty priority queue // 우선순위 큐 P 초기화
2. while (!L.isEmpty()) // 입력 리스트 L의 원소를 P에 차례대로 삽입
			e <- L.removeFirst()
			P.insertItem(e)
3. while (!P.isEmpty()) // P에서 최소 키를 가진 원소부터 차례로 삭제 후 L에 삽입
			e <- P.removeMin()
			L.addLast(e)
4. return
```

**`PQ-Sort` 알고리즘의 단계별 실행 시간**

- **무순리스트**로 구현하는 경우
    - 우선순위 큐의 항목들을 리스트에 임의 순서로 저장
    - 삽입: O(1)
    - 최소 키 찾기: O(N)
    - `선택 정렬`에 사용 (minKey 선택해서 정렬)
- **순서리스트**로 구현하는 경우
    - 우선순위 큐의 항목들을 리스트에 키 순서대로 저장
    - 삽입: O(N)
    - 최소 키 찾기: O(1)
    - `삽입 정렬`에 사용 (자기 순서 찾아 삽입)


## 제자리 정렬

<aside>
💡

리스트 자체 내부 공간 이외에 추가로 O(1) 크기의 외부 공간만을 사용하는 정렬

</aside>

### 제자리 선택 정렬

현재 우선순위 큐에서 최소 키를 가진 원소를 우선순위 큐의 가장 왼쪽 원소와 맞바꿈

- 오른쪽에 정렬된 일반 리스트, 왼쪽에 무순리스트 우선순위 큐

```Pseudocode
Alg inPlaceSelectionSort(A)
	input array A of n keys
	output sorted array A
	
1. for pass <- 0 to n - 2
			minLoc <- pass
			for j <- (pass+1) to n - 1
				if (A[j] < A[minLoc])
					minLoc <- j
			A[pass] <-> A[minLoc]
2. return
```


### 제자리 삽입 정렬

아직 우선순위 큐에 삽입되지 않은 원소 중 가장 왼쪽의 원소를 우선순위 큐의 키 순에 따른 자기 자리에 삽입

- 오른쪽에 순서리스트 우선순위 큐, 왼쪽에 무순리스트

```Pseudocode
Alg inPlaceInsertionSort(A)
	input array A of n keys
	output sorted array A
	
1. for pass <- 1 to n - 1
			save <- A[pass]
			j <- pass - 1
			
			while ((j >= 0) & (A[j] > save))
				A[j+1] <- A[j]
				j <- j - 1
			A[j + 1] <- save
2. return
```