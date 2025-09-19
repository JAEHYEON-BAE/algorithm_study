# [Gold II] Worms - 8398 

[문제 링크](https://www.acmicpc.net/problem/8398) 

### 성능 요약

메모리: 5496 KB, 시간: 16 ms

### 분류

그래프 이론, 그래프 탐색, 트리, 너비 우선 탐색, 깊이 우선 탐색, 트리의 지름

### 제출 일자

2025년 9월 19일 20:20:39

### 문제 설명

<p>In the Mysterious Land of Worms there are many worm-houses. Not all of them are inhabited. It is known however, that at most one worm lives in each house. Some pairs of houses are connected with a path. For any pair of two different houses there exists exactly one route consisting of paths, so that none of the paths repeats on the route.</p>

<p>One day, all of the worms decided to meet in one of the houses. They agreed that every hour each of them will move along a path leaving the house it is presently in and will go to the other house at the opposite end of that path (walking along any path in the Mysterious Land of Worms takes exactly one hour). Worms intend to continue their travel untill the moment, when all of them meet in the same house (they need to be in that house exactly in the same time).</p>

<p>Unfortunately, worms have not foreseen that it may take a long period of time to meet if they apply this method of movement. Sometimes it is even impossible to meet. That is why worms asked you for help with verifying whether their meeting can be arranged and if so, how long it will take to meet in the best case.</p>

<p>Write a program which:</p>

<ul>
	<li>reads the description of the Mysterious Land of Worms from the standard input,</li>
	<li>checks whether the worms can meet and if so, how long it will take in the best case,</li>
	<li>writes the answer to the standard output.</li>
</ul>

### 입력 

 <p>The first line of the standard input contains two integers <em>n</em> and <em>m</em> (2 ≤ <em>n</em> ≤ 50 000, 1 ≤ <em>m</em> ≤ 50 000), separated with a single space and denoting accordingly the number of houses and the number of paths in the Mysterious Land of Worms. Houses are numbered with natural numbers ranging from 1 to <em>n</em>. Following <em>m</em> lines contain descriptions of paths. Each of them consists of two integers <em>a</em> and <em>b</em> (1 ≤ <em>a</em>, <em>b</em> ≤ <em>n</em>), separated with a single space and denoting numbers of houses connected with a given path. Description of paths is followed by a line containing one integer <em>k</em> (2 ≤ <em>k</em> ≤ <em>n</em>), denoting the number of worms living in the Mysterious Land of Worms. Each of the following <em>k</em> lines contains one integer <em>d</em> (1 ≤ <em>d</em> ≤ <em>n</em>) denoting the house where the <em>k</em>-th worm lives.</p>

### 출력 

 <p>The first and only line of standard output should contain only one word <code>NIE</code> (i.e. <i>no</i> in Polish), if worms cannot meet while moving according to the rules, or one integer equal to the number of hours required by all worms to get to the meeting place.</p>

