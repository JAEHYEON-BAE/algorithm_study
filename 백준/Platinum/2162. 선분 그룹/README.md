# [Platinum V] 선분 그룹 - 2162 

[문제 링크](https://www.acmicpc.net/problem/2162) 

### 성능 요약

메모리: 2192 KB, 시간: 72 ms

### 분류

자료 구조, 기하학, 분리 집합, 선분 교차 판정

### 제출 일자

2025년 6월 10일 20:01:45

### 문제 설명

<p>N개의 선분들이 2차원 평면상에 주어져 있다. 선분은 양 끝점의 x, y 좌표로 표현이 된다.</p>

<p>두 선분이 서로 만나는 경우에, 두 선분은 같은 그룹에 속한다고 정의하며, 그룹의 크기는 그 그룹에 속한 선분의 개수로 정의한다. 두 선분이 만난다는 것은 선분의 끝점을 스치듯이 만나는 경우도 포함하는 것으로 한다.</p>

<p>N개의 선분들이 주어졌을 때, 이 선분들은 총 몇 개의 그룹으로 되어 있을까? 또, 가장 크기가 큰 그룹에 속한 선분의 개수는 몇 개일까? 이 두 가지를 구하는 프로그램을 작성해 보자.</p>

### 입력 

 <p>첫째 줄에 N(1 ≤ N ≤ 3,000)이 주어진다. 둘째 줄부터 N+1번째 줄에는 양 끝점의 좌표가 x1, y1, x2, y2의 순서로 주어진다. 각 좌표의 절댓값은 5,000을 넘지 않으며, 입력되는 좌표 사이에는 빈칸이 하나 있다.</p>

### 출력 

 <p>첫째 줄에 그룹의 수를, 둘째 줄에 가장 크기가 큰 그룹에 속한 선분의 개수를 출력한다.</p>

