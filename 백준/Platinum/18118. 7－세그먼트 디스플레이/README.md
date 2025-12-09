# [Platinum IV] 7-세그먼트 디스플레이 - 18118 

[문제 링크](https://www.acmicpc.net/problem/18118) 

### 성능 요약

메모리: 4260 KB, 시간: 352 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 12월 10일 08:22:40

### 문제 설명

<p>7-세그먼트 디스플레이란 아래와 같이 7개의 선분으로 글자를 표시할 수 있는 장치를 말한다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/c1a99f22-5f97-454a-9018-d917febbecde/-/preview/" style="height: 122px; width: 96px; margin-top: 16px; margin-bottom: 16px;"></p>

<p>최근 시프트는 디지털 회로에 관한 강의를 듣고 있다. 시프트가 이번 주에 받은 과제의 내용은 아래와 같다.</p>

<blockquote>
<p>7-세그먼트 디스플레이 <em>n</em>개를 사용한 회로를 구성한다. 양의 정수 <em>m</em>을 입력받아, <em>n</em>개의 7-세그먼트 디스플레이에 표현할 수 있는 가장 큰 <em>m</em>의 배수를 표시하시오.</p>
</blockquote>

<p>다행히도 입출력은 강의자료에 전부 나와 있어서 그대로 따라 하면 됐기 때문에 별로 문제가 될 건 없었다. 더군다나, <em>n</em>자리 수로 만들 수 있는 가장 큰 <em>m</em>의 배수를 계산하는 건 너무 쉽다.</p>

<p>하지만 시프트는 놀라운 발견을 하게 되는데, 7-세그먼트 디스플레이 하나에는 0~9의 숫자뿐만 아니라 11도 표시할 수 있다는 사실이었다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/eaa08ddb-202b-4e4f-91fb-b9c4480f06bb/-/preview/" style="width: 358px; height: 122px; margin-top: 16px; margin-bottom: 16px;"></p>

<p>두 개의 7-세그먼트 디스플레이로 1을 표시하는 대신 한 개의 디스플레이로 11을 표시하면 한 자리를 아낄 수 있고, 이 방법으로 더 큰 <em>m</em>의 배수를 표현할 수 있을지도 모른다. 예를 들어 4자리 수 중 가장 큰 3의 배수는 9999이지만, 4개의 디스플레이로 만들 수 있는 가장 큰 3의 배수는 <span style="color:#f1c40f;"><span style="background-color:#000000;"> 9 </span></span> <span style="color:#f1c40f;"><span style="background-color:#000000;"> 11 </span></span> <span style="color:#f1c40f;"><span style="background-color:#000000;"> 11 </span></span> <span style="color:#f1c40f;"><span style="background-color:#000000;"> 11 </span></span>이다.</p>

<p>이 방법을 활용해, 정수 <em>n</em>과 <em>m</em>에 대해 시프트가 <em>n</em>개의 7-세그먼트 디스플레이에 표현할 수 있는 가장 큰 <em>m</em>의 배수를 출력하라.</p>

### 입력 

 <p>첫 번째 줄에 테스트 케이스의 개수 <em>t</em>가 주어진다. (1 ≤ <em>t</em> ≤ 25)</p>

<p>각 테스트 케이스는 한 줄로 이루어져 있으며, 두 개의 수 <em>n</em>과 <em>m</em>이 주어진다. (1 ≤ <em>n</em> ≤ 9, 1 ≤ <em>m</em> ≤ 10<sup>5</sup>)</p>

### 출력 

 <p>각 테스트 케이스마다 <em>n</em>개의 7-세그먼트 디스플레이에 표현할 수 있는 가장 큰 <em>m</em>의 배수를 한 줄에 하나씩 출력한다. 가능한 가장 큰 값이 0일 경우, "0"(따옴표 제외)을 출력한다.</p>

