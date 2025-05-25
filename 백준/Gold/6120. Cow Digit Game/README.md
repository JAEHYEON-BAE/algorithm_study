# [Gold IV] Cow Digit Game - 6120 

[문제 링크](https://www.acmicpc.net/problem/6120) 

### 성능 요약

메모리: 5928 KB, 시간: 20 ms

### 분류

다이나믹 프로그래밍, 게임 이론

### 제출 일자

2025년 5월 25일 12:58:29

### 문제 설명

<p>Bessie is playing a number game against Farmer John, and she wants you to help her achieve victory.</p>

<p>Game i starts with an integer N_i (1 <= N_i <= 1,000,000). Bessie goes first, and then the two players alternate turns. On each turn, a player can subtract either the largest digit or the smallest non-zero digit from the current number to obtain a new number. For example, from 3014 we may subtract either 1 or 4 to obtain either 3013 or 3010, respectively. The game continues until the number becomes 0, at which point the last player to have taken a turn is the winner.</p>

<p>Bessie and FJ play G (1 <= G <= 100) games. Determine, for each game, whether Bessie or FJ will win, assuming that both play perfectly (that is, on each turn, if the current player has a move that will guarantee his or her win, he or she will take it).</p>

<p>Consider a sample game where N_i = 13. Bessie goes first and takes 3, leaving 10. FJ is forced to take 1, leaving 9. Bessie takes the remainder and wins the game.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: G</li>
	<li>Lines 2..G+1: Line i+1 contains the single integer: N_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Lines 1..G: Line i contains "YES" if Bessie can win game i, and "NO" otherwise.</li>
</ul>

<p> </p>

