# [Gold IV] Earthquake - 26046 

[문제 링크](https://www.acmicpc.net/problem/26046) 

### 성능 요약

메모리: 77656 KB, 시간: 636 ms

### 분류

브루트포스 알고리즘, 자료 구조, 해시를 사용한 집합과 맵, 런타임 전의 전처리, 정렬, 문자열, 트리를 사용한 집합과 맵, 집합과 맵

### 제출 일자

2025년 12월 9일 21:06:17

### 문제 설명

<p>Cimrman has quite a number of collaborators. Tomorrow morning, he is planning to make phone calls to many of them and his assistant had prepared a list of phone numbers on a sheet of paper. Regrettably, an earthquake struck yesterday. The coffee and juice stored close to the list had spilled out and made stains on the list. Upon close examination of the affected list, the following turned out:</p>

<ul>
	<li>No digit affected by a stain is readable.</li>
	<li>Each coffee stain covers exactly one digit in any of the numbers.</li>
	<li>There are at most two coffee stains on any of the numbers.</li>
	<li>Each juice stain covers one or more consecutive digits in any of the numbers.</li>
	<li>There is at most one juice stain on any of the numbers.</li>
	<li>No stain affects more than one number.</li>
	<li>No number has been affected by coffee and juice simultaneously.</li>
</ul>

<p>Fortunately, Cimrman has an older list of his collaborators phone numbers. This older list was stored in the drawer and it survived the earthquake undamaged. Now, it will help to restore the damaged list. First, the assistant needs to know, to how many items on the old list may correspond each of the items on the damaged list.</p>

### 입력 

 <p>The first input line contains one integer N (1 ≤ N ≤ 10<sup>4</sup>), the number of phone numbers in the older undamaged list. Each of the next N lines contains one phone number consisting of exactly 9 digits, leading zeros are allowed. All numbers are mutually different. Next, there is a line with one integer Q (1 ≤ Q ≤ 3 · 10<sup>5</sup>), the number of phone numbers on the damaged list. Each of the next Q lines contains one, possibly stained, phone number from the damaged list. A coffee stain is represented by a question mark (“?”), a juice stain is represented by an asterisk (“*”). There are no spaces in any numbers. The phone numbers are given in no specific order.</p>

### 출력 

 <p>Output Q lines, the i-th line should contain the number of items in the undamaged list which may correspond to the i-th item on the damaged list.</p>

