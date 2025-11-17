# [Platinum II] Taxi - 5843 

[문제 링크](https://www.acmicpc.net/problem/5843) 

### 성능 요약

메모리: 8296 KB, 시간: 44 ms

### 분류

그리디 알고리즘, 수학, 누적 합

### 제출 일자

2025년 11월 17일 14:22:23

### 문제 설명

<p>Bessie is running a taxi service for the other cows on the farm.  The cows have been gathering at different locations along a fence of length M (1 <= M <= 1,000,000,000).  Unfortunately, they have grown bored with their current locations and each wish to go somewhere else along the fence.  Bessie must pick up each of her friends at their starting positions and drive them to their destinations.  Bessie's car is small so she can only transport one cow in her car at a time.  Cows can enter and exit the car instantaneously.</p><p>To save gas, Bessie would like to minimize the amount she has to drive.  Given the starting and ending positions of each of the N cows (1 <= N <= 100,000), determine the least amount of driving Bessie has to do.  Bessie realizes that to save the most gas she may need to occasionally drop a cow off at a position other than her destination.</p><p>Bessie starts at the leftmost point of the fence, position 0, and must finish her journey at the rightmost point on the fence, position M.</p>

### 입력 

 <ul><li>Line 1: N and M separated by a space.</li><li>Lines 2..1+N: The (i+1)th line contains two space separated integers, s_i and t_i (0 <= s_i, t_i <= M), indicating the starting position and destination position of the ith cow.</li></ul>

### 출력 

 <ul><li>Line 1: A single integer indicating the total amount of driving Bessie must do.  Note that the result may not fit into a 32 bit integer.</li></ul>

