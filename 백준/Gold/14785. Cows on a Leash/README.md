# [Gold V] Cows on a Leash - 14785 

[문제 링크](https://www.acmicpc.net/problem/14785) 

### 성능 요약

메모리: 2272 KB, 시간: 8 ms

### 분류

그리디 알고리즘, 정렬, 스위핑

### 제출 일자

2025년 7월 7일 12:00:55

### 문제 설명

<p>Farmer John has forced indignity onto the N (1 <= N <= 32,000) cows: he has purchased a number of leashes and has leashed the cows to stakes (conveniently located at integer locations) next to a long, linear fence that is no longer than 5,300,000 meters and runs east-west. Every single cow is straining her leash as much as she can to the east (though never beyond the end of the fence).</p>

<p>Happily, the cows have acquired an ally: FJ's wife thinks that leashes are barbaric and has come to the fence with her dull butcher knife. She can perform only a few cuts with it and wants to do the best job she can. She can locate herself halfway between two integer points along the fence and cut all the leashes that cross in front of her at that place.</p>

<p>Given the length of each leash and the location of its stake in the ground, what is the minimal number of cuts she must perform to free the cows?</p>

### 입력 

 <ul>
	<li>Line 1: A single integer, N</li>
	<li>Lines 2..N+1: Each line contains two space-separated positive integers that describe a leash. The first is the location of the leash's stake; the second is the length of the leash.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the minimum number of cuts so that each leash is cut at least once.</li>
</ul>

