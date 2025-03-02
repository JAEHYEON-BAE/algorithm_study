# [Gold IV] grupe - 3224 

[문제 링크](https://www.acmicpc.net/problem/3224) 

### 성능 요약

메모리: 81912 KB, 시간: 140 ms

### 분류

자료 구조, 그리디 알고리즘, 스택

### 제출 일자

2025년 3월 2일 13:23:44

### 문제 설명

<p>First N positive integers (numbers from 1 to N) are written on the blackboard in some arbitrary order (from left to right).</p>

<p>A group is set of integers which form an interval. For example, sets [2], [4 5] and [3 5 6 4] are groups, but [5 7 2] and [2 4 5] aren't. At the beginning, we assume that each number on the blackboard forms a single group with only itself in it.</p>

<p>There is only one allowed operation - concatenating two adjacent groups, but only if the new set would be a group.</p>

<p>Write a program which will determine wheather sequence of N-1 operations exists, after which all written numbers will be in the same group. If such sequence exists, your program must find at least one of them.</p>

<p>Example (one possible solution for third example):</p>

<pre>[6] [3] [2] [1] [4] [5]
[6] [3] [2 1] [4] [5]
[6] [3 2 1] [4] [5]
[6] [3 2 1] [4 5]
[6] [3 2 1 4 5]
[6 3 2 1 4 5] </pre>

### 입력 

 <p>In the first line, there will be integer N, 1 ≤ N ≤ 500,000.</p>

<p>In the second line, there will be N positive integers, separated by single space. These numbers are written on the blackboard (i.e. this is an initial state).</p>

### 출력 

 <p>In the first line there must be word 'DA' (yes) or 'NE' (no), depending wheather requested sequence exists. If given answer is 'NE', then first line must be the last.</p>

<p>If the written word is 'DA', then the next N–1 lines should consist of two integers a and b so that those numbers in the line (i+1) are the smallest and the biggest number in the group made in i-th gathering.</p>

