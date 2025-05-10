# [Gold IV] Wormholes - 10568 

[문제 링크](https://www.acmicpc.net/problem/10568) 

### 성능 요약

메모리: 2176 KB, 시간: 0 ms

### 분류

플로이드–워셜, 그래프 이론, 최단 경로

### 제출 일자

2025년 5월 10일 15:24:16

### 문제 설명

<p>With our time on Earth coming to an end, Cooper and Amelia have volunteered to undertake what could be the most important mission in human history: travelling beyond this galaxy to discover whether mankind has a future among the stars. Fortunately, astronomers have identified several potentially inhabitable planets and have also discovered that some of these planets have wormholes joining them, which effectively makes the travel distance between these wormhole connected planets zero. For all other planets, the travel distance between them is simply the Euclidean distance between the planets. Given the location of Earth, planets, and wormholes, find the shortest travel distance between any pairs of planets.</p>

### 입력 

 <ul>
	<li>The first line of input is a single integer, T (1 ≤ T ≤ 10) the number of test cases.</li>
	<li>Each test case consists of planets, wormholes, and a set of distance queries.</li>
	<li>The planets list for a test case starts with a single integer, p (1 ≤ p ≤ 60), the number of planets. Following this are p lines, where each line contains a planet name along with the planet’s integer coordinates, i.e. name x y z (0 ≤ x, y, z ≤ 2 · 10<sup>6</sup>) The names of the planets will consist only of ASCII letters and numbers, and will always start with an ASCII letter. Planet names are case-sensitive (Earth and earth are distinct planets). The length of a planet name will never be greater than 50 characters. All coordinates are given in parsecs.</li>
	<li>The wormholes list for a test case starts with a single integer, w (0 ≤ w ≤ 40), the number of wormholes, followed by the list of w wormholes. Each wormhole consists of two planet names separated by a space. The first planet name marks the entrance of wormhole, and the second planet name marks the exit from the wormhole. The planets that mark wormholes will be chosen from the list of planets given in the preceding section. Note: you can’t enter a wormhole at its exit.</li>
	<li>The queries list for a test case starts with a single integer, q (1 ≤ q ≤ 20), the number of queries. Each query consists of two planet names separated by a space. Both planets will have been listed in the planet list.</li>
</ul>

### 출력 

 <p>For each test case, output a line, “Case i:”, the number of the ith test case. Then, for each query in that test case, output a line that states “The distance from planet<sub>1</sub> to planet<sub>2</sub> is d parsecs.”, where the planets are the names from the query and d is the shortest possible travel distance between the two planets. Round d to the nearest integer.</p>

