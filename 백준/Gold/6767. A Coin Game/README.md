# [Gold V] A Coin Game - 6767 

[문제 링크](https://www.acmicpc.net/problem/6767) 

### 성능 요약

메모리: 2168 KB, 시간: 0 ms

### 분류

구현, 그래프 이론, 자료 구조, 그래프 탐색, 집합과 맵, 너비 우선 탐색, 최단 경로

### 제출 일자

2025년 8월 24일 15:42:19

### 문제 설명

<p>When she is bored, Jo Coder likes to play the following game with coins on a table. She takes a set of distinct coins and lines them up in a row. For example, let us say that she has a penny (P, worth <span>$</span>0.01), a nickel (N, worth <span>$</span>0.05), and a dime (D, worth <span>$</span>0.10). She lines them up in an arbitrary order, (for example, D N P), and then moves them around with the goal of placing them in strictly increasing order by value, that is P N D (i.e., <span>$</span>0.01, <span>$</span>0.05, <span>$</span>0.10). She has particular rules that she follows:</p>

<ul>
	<li>The initial coin line-up defines all positions where coins can be placed. That is, no additional positions can be added later, and even if one of the positions does not have a coin on it at some point, the position still exists.</li>
	<li>The game consists of a sequence of moves and in each move Jo moves a coin from one position to an adjacent position.</li>
	<li>The coins can be stacked, and in a move Jo always takes the top coin from one stack and moves it to the top of another stack.</li>
	<li>In a stack of coins, Jo never places a higher-value coin on top of a lower-value coin.</li>
</ul>

<p>For simplicity, let the coins have consecutive integer values (e.g., denote the penny as 1, nickel as 2, and dime as 3). Then, in the above example, Jo could play the game in the following way in 20 moves (where XY denotes that coin X is on top of coin Y):</p>

<table class="table table-bordered" style="width:50%">
	<tbody>
		<tr>
			<td style="text-align:center">Move</td>
			<td style="text-align:center">Position 1</td>
			<td style="text-align:center">Position 2</td>
			<td style="text-align:center">Position 3</td>
		</tr>
		<tr>
			<td style="text-align:center">initial</td>
			<td style="text-align:center">3</td>
			<td style="text-align:center">2</td>
			<td style="text-align:center">1</td>
		</tr>
		<tr>
			<td style="text-align:center">1</td>
			<td style="text-align:center">3</td>
			<td style="text-align:center">12</td>
			<td style="text-align:center"> </td>
		</tr>
		<tr>
			<td style="text-align:center">2</td>
			<td style="text-align:center">13</td>
			<td style="text-align:center">2</td>
			<td style="text-align:center"> </td>
		</tr>
		<tr>
			<td style="text-align:center">3</td>
			<td style="text-align:center">13</td>
			<td style="text-align:center"> </td>
			<td style="text-align:center">2</td>
		</tr>
		<tr>
			<td style="text-align:center">4</td>
			<td style="text-align:center">3</td>
			<td style="text-align:center">1</td>
			<td style="text-align:center">2</td>
		</tr>
		<tr>
			<td style="text-align:center">5</td>
			<td style="text-align:center">3</td>
			<td style="text-align:center"> </td>
			<td style="text-align:center">12</td>
		</tr>
		<tr>
			<td style="text-align:center">6</td>
			<td style="text-align:center"> </td>
			<td style="text-align:center">3</td>
			<td style="text-align:center">12</td>
		</tr>
		<tr>
			<td style="text-align:center">7</td>
			<td style="text-align:center"> </td>
			<td style="text-align:center">13</td>
			<td style="text-align:center">2</td>
		</tr>
		<tr>
			<td style="text-align:center">8</td>
			<td style="text-align:center">1</td>
			<td style="text-align:center">3</td>
			<td style="text-align:center">2</td>
		</tr>
		<tr>
			<td style="text-align:center">9</td>
			<td style="text-align:center">1</td>
			<td style="text-align:center">23</td>
			<td style="text-align:center"> </td>
		</tr>
		<tr>
			<td style="text-align:center">10</td>
			<td style="text-align:center"> </td>
			<td style="text-align:center">123</td>
			<td style="text-align:center"> </td>
		</tr>
		<tr>
			<td style="text-align:center">11</td>
			<td style="text-align:center"> </td>
			<td style="text-align:center">23</td>
			<td style="text-align:center">1</td>
		</tr>
		<tr>
			<td style="text-align:center">12</td>
			<td style="text-align:center">2</td>
			<td style="text-align:center">3</td>
			<td style="text-align:center">1</td>
		</tr>
		<tr>
			<td style="text-align:center">13</td>
			<td style="text-align:center">2</td>
			<td style="text-align:center">13</td>
			<td style="text-align:center"> </td>
		</tr>
		<tr>
			<td style="text-align:center">14</td>
			<td style="text-align:center">12</td>
			<td style="text-align:center">3</td>
			<td style="text-align:center"> </td>
		</tr>
		<tr>
			<td style="text-align:center">15</td>
			<td style="text-align:center">12</td>
			<td style="text-align:center"> </td>
			<td style="text-align:center">3</td>
		</tr>
		<tr>
			<td style="text-align:center">16</td>
			<td style="text-align:center">2</td>
			<td style="text-align:center">1</td>
			<td style="text-align:center">3</td>
		</tr>
		<tr>
			<td style="text-align:center">17</td>
			<td style="text-align:center">2</td>
			<td style="text-align:center"> </td>
			<td style="text-align:center">13</td>
		</tr>
		<tr>
			<td style="text-align:center">18</td>
			<td style="text-align:center"> </td>
			<td style="text-align:center">2</td>
			<td style="text-align:center">13</td>
		</tr>
		<tr>
			<td style="text-align:center">19</td>
			<td style="text-align:center"> </td>
			<td style="text-align:center">12</td>
			<td style="text-align:center">3</td>
		</tr>
		<tr>
			<td style="text-align:center">20</td>
			<td style="text-align:center">1</td>
			<td style="text-align:center">2</td>
			<td style="text-align:center">3</td>
		</tr>
	</tbody>
</table>

<p>For some starting configurations, it is not always possible to obtain the goal of strictly increasing order.</p>

### 입력 

 <p>The input will contain some number of test cases. A test case consists of two lines. The first line contains a positive integer n (n < 5), which is the number of coins. We assume that the coins are labeled 1, 2, 3, . . . n. The second line contains a list of numbers 1 to n in an arbitrary order, which represents the initial coin configuration.</p>

<p>The end of test cases is indicated by 0 on a line by itself.</p>

### 출력 

 <p>For each test case, output one line, which will either contain the minimal number of moves in which Jo can achieve the goal coin line-up, or, if it is not possible to achieve the goal coin line-up, IMPOSSIBLE.</p>

