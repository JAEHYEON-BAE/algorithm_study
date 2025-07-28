# [Platinum V] Cover - 15497 

[문제 링크](https://www.acmicpc.net/problem/15497) 

### 성능 요약

메모리: 2260 KB, 시간: 20 ms

### 분류

다이나믹 프로그래밍, 정렬

### 제출 일자

2025년 7월 28일 19:16:21

### 문제 설명

<p>You are given N points in the coordinate system. They need to be covered with one or more rectangles, such that the following conditions are met:</p>

<ul>
	<li>The sides of each rectangle are parallel with the coordinate axes,</li>
	<li>The center of each rectangle is in the origin, i.e. point (0, 0),</li>
	<li>Each given point is located either inside of the rectangle or on its boundaries.</li>
</ul>

<p>Of course, it is possible to cover all the points using only one rectangle, but this rectangle could have a very large surface area. Our goal is to find a selection of required rectangles such that the sum of their surface areas is minimal.</p>

### 입력 

 <p>The first line of input contains the integer N (1 ≤ N ≤ 5000), the number of points.</p>

<p>Each of the following N lines contains two integers X and Y (-50 000 000 ≤ X, Y ≤ 50 000 000, XY ≠ 0), the coordinates of each point.</p>

### 출력 

 <p>You must output the required minimal sum of surface areas of the rectangles.</p>

