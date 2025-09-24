# [Gold III] Orderly Class - 15100 

[문제 링크](https://www.acmicpc.net/problem/15100) 

### 성능 요약

메모리: 3408 KB, 시간: 0 ms

### 분류

애드 혹, 문자열

### 제출 일자

2025년 9월 24일 12:48:40

### 문제 설명

<p>Ms. Thomas is managing her class of n students.</p>

<p>She placed all her students in a line, and gave the i-th student from the left a card with the letter a<sub>i</sub> written on it.</p>

<p>She would now like to rearrange the students so that the i-th student from the left has a card with the letter b<sub>i</sub> written on it.</p>

<p>To do this, she will choose some consecutive group of students, and reverse their order. Students will hold on to their original cards during this process.</p>

<p>She’s now wondering, what is the number of valid ways to do this? (It may be impossible, in which case, the answer is zero). With sequences abba and aabb, Ms. Thomas can choose the group a(bba).</p>

<p>With sequences caxcab and cacxab, Ms. Thomas can choose ca(xc)ab or c(axca)b. With sequences a and z, there are clearly no solutions.</p>

### 입력 

 <p>The input is two lines of lowercase letters, A and B. The i-th character of A and B represent a<sub>i</sub> and b<sub>i</sub> respectively. It is guaranteed that A and B have the same positive length, and A and B are not identical. The common length is allowed to be as large as 100 000.</p>

### 출력 

 <p>For each test case, output a single integer, the number of ways Ms. Thomas can reverse some consecutive group of A to form the line specified by string B.</p>

