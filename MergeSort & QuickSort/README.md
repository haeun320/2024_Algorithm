# 합병 정렬 / 퀵 정렬

## 분할 통치법

<aside>
💡

문제를 몇 개의 부 문제로 분할하고 재귀적으로 위임

</aside>

1. 분할: 입력 데이터 ***L***을 둘 이상의 분리된 부분집합으로 나눈다.
2. 재귀: 각 부분집합에 대한 부문제를 재귀적으로 해결한다.
3. 통치: 부문제들에 대한 해결을 합쳐 ***L***의 해결을 구한다.

## 합병 정렬

- 분할 통치법에 기초한 정렬 알고리즘
- `O(nlogn)` 시간에 수행
    
    <img width="265" alt="image" src="https://github.com/user-attachments/assets/8813274f-d40d-4b2c-8719-8245b98a5876">

    
- 비교에 기초한 정렬, 데이터를 순차적 방식으로 접근

1. 분할: 무순리스트 L을 각각 n/2개의 원소를 가진 두 개의 부리스트 L1, L2로 분할
2. 재귀: L1, L2를 각각 재귀적으로 정렬
3. 통치: L1, L2를 단일 순서리스트로 합병

```
Alg mergeSort(L)
	input list L with n elements
	output sorted list L
	
1. if (L.size() > 1)
	L1, L2 <- partition(L, n/2) // 분할
	mergeSort(L1) // 재귀
	mergeSort(L2)
	L <- merge(L1, L2) // 통치
2. return
```

### 합병
<img width="463" alt="image 1" src="https://github.com/user-attachments/assets/013c8a4f-492c-4414-9859-3bf5a4eabeb9">


두 개의 부리스트 front 값을 비교해 작은걸 삭제 후 L에 추가한다.

```
Alg merge(L1, L2)
	input sorted list L1 and L2 with n/2 elements each
	output sorted list of L1 union L2
	
1. L <- empty list
2. while (!L1.isEmpty() & !L2.isEmpty())
	if (L1.get(1) <= L2.get(1))
		L.addLast(L1.removeFirst())
	else
		L.addLast(L2.removeFirst())
3. while (!L1.isEmpty())
		L.addLast(L1.removeFirst())
4. while (!L2.isEmpty())
		L.addLast(L2.removeFirst())
5. return
```

### 합병 정렬 트리

<img width="320" alt="image 2" src="https://github.com/user-attachments/assets/029f8bd0-dddf-4f8a-8edd-3533a2ff7c3f">
<img width="320" alt="image" src="https://github.com/user-attachments/assets/91e3240a-e946-42ec-aa85-a04b388fbbc0">


mergeSort의 재귀 실행 과정을 이진 트리로 나타냄

## 퀵 정렬

- 분할 통치법에 기초한 정렬 알고리즘
- 기대 실행 시간 `O(nlogn)`

1. 분할: 입력 리스트 원소 가운데 기준원소 ***p***(pivot)를 택하여 ***L***을 다음 세 부분으로 분할한다.
	- ***LT***: p보다 작은 원소들
	- ***EQ***: p와 같은 원소들
	- ***GT***: p보다 큰 원소들
2. 재귀: ***LT***와 ***GT***를 정렬한다.
3. 통치: ***LT, EQ, GT***를 결합한다.

```
Alg quickSort(L)
	input list L with n elements
	output sorted list L
	
1. if (L.size() > 1)
	k <- a position in L // p의 위치
	LT, EQ, GT <- partition(L, k)
	quickSort(LT)
	quickSort(GT)
	L <- merge(LT, EQ, GT)
2. return
```

### 분할

알고리즘 `partition`은 입력 리스트를 다음과 같이 분할한다.

1. ***L***로부터 각 원소 ***e***를 차례로 삭제한다.
2. ***e***를 기준원소 ***p***와의 비교 결과에 따라 부리스트 ***LT, EQ, GT***에 삽입한다.

```
Alg partition(L,k)
	input list L with n elements, position k of pivot
	output sublists LT,EQ,GT

1. p <- L.get(k) // pivot
2. LT, EQ, GT <- empty list
3. while (!L.isEmpty())
	e <- L.removeFirst()
	if (e < p)
		LT.addLast(e)
	elseif (e = p)
		EQ.addLast(e)
	else {e > p}
		GT.addLast(e)
4. return LT, EQ, GT
```

### 퀵 정렬 트리
<img width="320" alt="image 3" src="https://github.com/user-attachments/assets/be317b72-3025-4c06-b572-b169f89fba9c">
<img width="320" alt="image 4" src="https://github.com/user-attachments/assets/8b8a09fc-0a65-412e-9a36-5973202478f8">

quickSort 재귀 실행 과정을 이진 트리로 나타냄

- 최악실행시간 `O(n^2)` : pivot을 항상 부리스트의 최대 또는 최소값으로 선택
- 기대실행시간 `O(nlogn)` : 무작위 퀵 정렬

## 제자리 퀵 정렬

분할 단계에서 입력 리스트의 원소들을 재배치하기 위해, 입력 리스트 내에서 재배치되어야 할 원소들의 자리를 맞바꾼다.

- LT: a보다 아래의, 기준원소보다 작은 원소들
- EQ: a와 b사이의, 기준원소와 같은 원소들
- GT: b보다 위의, 기준원소보다 큰 원소들

```
Alg inplaceQuickSort(L, l, r)
	input list L, position l, r
	output list L with elements of position from l to r rearranged in increasing order
	
1. if (l >= r)
	return
2. k <- a position between i and r
3. a, b <- inPlacePartition(L, l, r, k)
4. inPlaceQuickSort(L, l, a-1)
5. inPlaceQuickSort(L, b+1, r)
```

`inPlacePartition` 알고리즘은 입력리스트 L의 왼쪽 경계점 l과 오른쪽 경계점 r, 기준원소의 위치 k를 매개변수로 호출된다.

```
Alg inPlacePartition(A, l, r, k)
	input array A[l..r] of distinct elements, index l, r, k
	output final index of the pivot resulting from partitioning A[l..r] into LT, pivot, GT
	
1. p <- A[k]  // pivot
2. A[k] <-> A[r]  // hide pivot
3. i <- l
4. j <- r - 1
5. while (i <= j)
	while (i <= j & A[i] <= p)
		i <- i + 1
	while (j >= i & A[j] >= p)
		j <- j - 1
	if (i < j)
		A[i] <-> A[j]  // replace pivot
6. A[i] <-> A[r]
7. return i  // index of pivot
```

<img width="350" alt="image 5" src="https://github.com/user-attachments/assets/b1e1033c-dbe6-4107-a2fa-6c8a9fa665cd">
