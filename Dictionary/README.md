# 사전

## 사전 ADT

<aside>
💡

(키, 원소) 쌍으로 표현된 데이터 항목의 모음

</aside>

주요 작업: 탐색, 삽입, 삭제

- 무순사전 ADT: 데이터 항목들이 키 순서와 관계 없이 저장됨
- 순서사전 ADT: 데이터 항목들이 키 순서에 의해 정렬되어 저장됨

## 사전 ADT 메소드

일반 메소드

- integer size(): 사전의 항목 수 반환
- boolean isEmpty(): 사전이 비어 있는지 여부를 반환

접근 메소드

- element findElement(k): 사전에 키 k를 가진 항목이 존재하면 해당 원소를 반환, 그렇지 않으면 특별 원소 NoSuchKey를 반환

갱신 메소드

- insertItem(k, e): 사전에 (k, e) 항목을 삽입
- element removeElement(k): 사전에 키 k를 가진 항목이 존재하면 해당 항목을 삭제하고 원소를 반환, 그렇지 않으면 특별 원소 NoSuchKey를 반환

## 사전 ADT 구현

사전 구현에 따른 탐색 기법

| 구현 형태 | 구현 종류 | 예 | 주요 탐색 기법 |
| --- | --- | --- | --- |
| 리스트 | 무순사전 ADT<br/>순서사전 ADT | 기록파일<br/>알람표 | 선형탐색<br/>이진탐색 |
| 트리 | 탐색트리 | 이진탐색트리, AVL 트리, 스플레이 트리 | 트리탐색 |
| 해시테이블 |  |  | 해싱 |

## 무순사전 ADT

- insertItem: 새로운 항목을 기존 리스트의 맨 앞 또는 맨 뒤에 삽입. O(1)
- findElement, removeElement: 최악의 경우(항목이 존재하지 않을 경우), 리스트 전체를 순회. O(n)

⇒ 삽입이 빠른 대신 탐색, 삭제가 느리다

### 선형탐색

```
Alg findElement(k)
	input list L, key k
	output element with key k
	
1. L.initialize(i)
2. while (L.isValid(i))
		if (L.key(i) = k)
			return L.element(i)
		else
			L.advance(i)
3. return NoSuchKey
```

## 순서사전 ADT

- findElement: 이진탐색을 사용하면 O(logn)
- insertItem: 최악의 경우(n개의 기존 항목을 이동), O(n)
- removeElement: 최악의 경우, O(n)

⇒ 탐색이 빠른 대신 삽입, 삭제가 느리다

### 이진탐색 - 재귀

- 배열에 기초한 리스트로 구현된 사전에 대해 탐색 작업 수행
- 재귀할 때마다 탐색 범위가 절반으로 줄어든다

```
Alg findElement(k)
	input sorted array A[0..n-1], key k
	output element with key k

1. return rFindElement(k, 0, n-1)
```

```
Alg rFindElement(k, l, r)
1. if (l > r)
	return NoSuchKey
2. mid <- (l+r)/2
3. if (k = key(A[mid])
	return element(A[mid])
	elseif (k < key(A[mid])
		return rFindElement(k, l, mid - 1)
	else {k > key(A[mid])}
		return rFindElement(k, mid + 1, r)
```

<img width="521" alt="image" src="https://github.com/user-attachments/assets/4585137d-5b05-4364-a172-275e8bc1289a">

- 탐색범위 시작 `l` , 탐색범위 끝 `r` , 탐색범위 중간 `mid`
- 찾고자 하는 값 == mid : 찾음!
- 찾고자 하는 값 < mid : l ~ mid-1로 탐색범위 줄이기 (mid 왼쪽)
- 찾고자 하는 값 > mid : mid+1 ~ r로 탐색범위 줄이기 (mid 오른쪽)