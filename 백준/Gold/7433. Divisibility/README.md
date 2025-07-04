# [Gold IV] Divisibility - 7433 

[문제 링크](https://www.acmicpc.net/problem/7433) 

### 성능 요약

메모리: 2180 KB, 시간: 12 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 7월 4일 17:17:28

### 문제 설명

<p>Consider an arbitrary sequence of integers. One can place + or - operators between integers in the sequence, thus deriving different arithmetical expressions that evaluate to different values. Let us, for example, take the sequence: 17, 5, -21, 15. There are eight possible expressions:</p>

<ul>
	<li>17 + 5 + -21 + 15 = 16</li>
	<li>17 + 5 + -21 - 15 = -14</li>
	<li>17 + 5 - -21 + 15 = 58</li>
	<li>17 + 5 - -21 - 15 = 28</li>
	<li>17 - 5 + -21 + 15 = 6</li>
	<li>17 - 5 + -21 - 15 = -24</li>
	<li>17 - 5 - -21 + 15 = 48</li>
	<li>17 - 5 - -21 - 15 = 18</li>
</ul>

<p>We call the sequence of integers <b>divisible</b> by <em>K</em> if + or - operators can be placed between integers in the sequence in such way that resulting value is divisible by <em>K</em>. In the above example, the sequence is divisible by 7 (17+5+-21-15=-14) but is not divisible by 5.</p>

<p>You are to write a program that will determine divisibility of sequence of integers.</p>

### 입력 

 <p>The first line of the input file contains two integers, <em>N</em> and <em>K</em> (1 ≤ <em>N</em> ≤ 10000, 2 ≤ <em>K</em> ≤ 100) separated by a space.</p>

<p>The second line contains a sequence of <em>N</em> integers separated by spaces. Each integer is not greater than 10000 by it's absolute value.</p>

### 출력 

 <p>Write to the output file the word "Divisible" if given sequence of integers is divisible by <em>K</em> or "Not divisible" if it's not.</p>

