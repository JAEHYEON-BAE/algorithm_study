# [Platinum III] Reversi - 30430 

[문제 링크](https://www.acmicpc.net/problem/30430) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

애드 혹, 게임 이론, 홀짝성

### 제출 일자

2025년 11월 28일 12:31:20

### 문제 설명

<p>리버와 스캐럽의 수를 과소평가해 집과 집 안에 있던 전 재산을 잃은 동호는 빚더미에 앉게 되었다! 동호는 빚을 갚기 위해 게임을 잘하는 시이를 "세계 리버시 대회"에 출전시켜 시이의 상금 일부를 얻으려고 한다.</p>

<p>리버시는 오델로라고도 불리는 게임으로, 흑과 백이 번갈아 돌을 놓으며 게임이 끝난 후 돌이 더 많은 쪽이 승리하는 게임이다. 그러나 본 문제와는 별로 관련이 없으니 자세한 규칙 설명은 넘어가자.</p>

<p>하지만, 대회에서 하는 리버시는 일반적인 리버시와는 다른 게임으로, 돌을 뒤집지 못한다!</p>

<p>돌을 뒤집는 것이 게임의 핵심 부분인 게임에서 돌을 뒤집지 못하면 게임이 매우 재미없어지기 때문에, 그 대신 다음과 같은 룰을 사용하기로 하였다.</p>

<ul>
	<li>보드는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>행 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>열의 격자이다.</li>
	<li>선공은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>×</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2 \times 1$</span></mjx-container> 크기의 돌을 가지고 있고, 후공은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>×</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \times 1$</span></mjx-container> 크기의 돌을 가지고 있다. 돌은 그대로 놓거나 90도 회전시켜 놓을 수 있다.</li>
	<li>선공부터 번갈아 가며 보드에 하나씩 자신의 돌을 놓는다. 한 칸에는 최대 하나의 돌만 위치할 수 있다.</li>
	<li>둘 중 한 명이 돌을 더 이상 놓을 수 없으면, 남은 한 명이 남은 공간을 자신의 돌로 최대한 많이 채운 후 게임이 끝난다.</li>
	<li>게임이 끝난 후, 보드에서 자신의 돌으로 더 많은 공간을 차지한 플레이어가 승리한다. 만약에 차지한 공간이 같으면 무승부이다.</li>
</ul>

<p>시이를 포함한 세계 리버시 대회의 출전자들은 모두 엄청난 게임 실력을 가지고 있으므로 이기기 위해 항상 최선의 행동을 한다. 시이는 동전 던지기에서 이길 운이 없기 때문에 항상 후공을 잡는다.</p>

<p>시이가 대회에서 좋은 성적을 거둬 동호가 빚을 모두 갚을 수 있을지를 알아보자.</p>

### 입력 

 <p>첫 번째 줄에 테스트 케이스의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>이 주어진다.</p>

<p>그다음 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>번, 한 줄에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>과 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>이 공백을 사이에 두고 주어진다.</p>

### 출력 

 <p>각 테스트 케이스별로, 시이가 승리하면 <span style="color:#e74c3c;"><code>W</code></span>, 패배하면 <span style="color:#e74c3c;"><code>L</code></span>, 무승부이면 <span style="color:#e74c3c;"><code>D</code></span>를 공백이나 줄바꿈 없이 출력한다.</p>

