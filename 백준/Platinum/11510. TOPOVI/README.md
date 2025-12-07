# [Platinum II] TOPOVI - 11510 

[문제 링크](https://www.acmicpc.net/problem/11510) 

### 성능 요약

메모리: 28468 KB, 시간: 256 ms

### 분류

자료 구조, 해시를 사용한 집합과 맵, 구현, 집합과 맵

### 제출 일자

2025년 12월 7일 17:08:36

### 문제 설명

<p>Mirko is a huge fan of chess and programming, but typical chess soon became boring for him, so he started having fun with rook pieces.</p>

<p>He found a chessboard with N rows and N columns and placed K rooks on it.</p>

<p>Mirko’s game is made of the following rules:</p>

<ol>
	<li>Each rook’s power is determined by an integer.</li>
	<li>A rook sees all the fields that are in his row or column except its own field.</li>
	<li>We say that a field is attacked if the binary XOR of all the powers of the rooks that see the field is greater than 0.</li>
</ol>

<p>Notice that the field a rook is at can be attacked or not.</p>

<p>Initially, Mirko placed the rooks in a certain layout on the board and will make P moves. After each move, determine how many fields are attacked.</p>

<p>Every rook can be moved to any free field on the whole board (not only across column and row).</p>

### 입력 

 <p>The first line of input contains integers N, K, P (1 ≤ N ≤ 1 000 000 000, 1 ≤ K ≤ 100 000, 1 ≤ P ≤ 100 000).</p>

<p>Each of the following K lines contains three integers R, C, X (1 ≤ R, C ≤ N, 1 ≤ X ≤ 1 000 000 000) which denote that initially there is a rook of power X on the field (R, C).</p>

<p>Each of the following P lines contains four integers R1, C1, R2, C2 (1 ≤ R1, C1, R2, C2 ≤ N) which denote that the rook has moved from field (R1, C1) to field (R2, C2).</p>

<p>It is guaranteed that there will not be two rooks on one field at any point. </p>

### 출력 

 <p>The output must consist of P lines, the kth line containing the total number of attacked fields after k moves.</p>

