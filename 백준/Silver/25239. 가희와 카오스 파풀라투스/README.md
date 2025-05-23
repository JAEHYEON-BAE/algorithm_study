# [Silver III] 가희와 카오스 파풀라투스 - 25239 

[문제 링크](https://www.acmicpc.net/problem/25239) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현, 문자열

### 제출 일자

2025년 4월 11일 20:04:24

### 문제 설명

<p>파풀라투스는 메이플스토리의 보스입니다.</p>

<p>파풀라투스가 사용하는 패턴 중, 차원의 균열 봉인 패턴이 있습니다. 이 패턴이 시전되면, 6개의 영역으로 나뉘어진 파풀라투스 시계가 나타나게 됩니다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/8f165a2d-d01e-4fd9-8089-c67f53b925c2/-/preview/"></p>

<p style="text-align: center;"><strong>[그림 1] 파풀라투스의 시계</strong></p>

<p>시침은 12시 방향에서 2시 방향 사이를 가리킬 때 1번 영역에, 2시에서 4시 사이를 가리킬 때 2번 영역에, 4시 방향에서 6시 방향 사이를 가리킬 때 3번 영역에, 6시 방향에서 8시 방향 사이를 가리킬 때 4번 영역에, 8시 방향에서 10시 방향 사이를 가리킬 때 5번 영역에, 10시 방향에서 12시 방향 사이를 가리킬 때 6번 영역에 있습니다. <strong>시침이 정확히 2, 4, 6, 8, 10, 12시를 가리키는 경우는 고려하지 않습니다.</strong></p>

<p>그림 1에서 시침은 6번 영역에 있습니다. 파풀라투스의 시계는 약 11시 55분이고, 이때 시침은 10시 방향과 12시 방향 사이를 가리키고 있기 때문입니다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/4073c89a-c9b8-4e1f-b14d-02377b7a9447/-/preview/"></p>

<p style="text-align: center;"><strong>[그림 2] 파풀라투스의 시계가 가리키는 시각을 바꾸는 아이템들</strong></p>

<p>아이템을 먹어서 파풀라투스의 시계가 가리키는 시각을 특정 시간만큼 증가시킬 수 있습니다. 예를 들어, 파풀라투스의 시계가 가리키는 시각이 11시 55분일 때, 10MIN 아이템을 먹는다면, 파풀라투스의 시계가 가리키는 시각은 11시 55분에서 10분 증가한 12시 05분이 됩니다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d88d8e61-ee16-4ffb-bf98-2a5d5676ef9d/-/preview/"></p>

<p style="text-align: center;"><strong>[그림 3] 1번, 2번, 5번, 6번 영역이 봉인된 시계</strong></p>

<p>시침이 x번 영역에 있을 때, 유저가 시계 왼쪽 포탈에서 윗키를 누르면, x번 영역이 봉인됩니다. 차원의 균열 패턴이 시전되고 1분이 지난 후, 봉인되지 않은 칸이 있다면, 그 칸들에 쓰여 있는 % 수치의 합만큼 체력을 회복하게 됩니다. 이때, % 수치의 합이 100을 넘어간다면 100%만큼 회복합니다. 만약, 1분이 지나기 전에 6개의 칸이 모두 봉인되었다면, <strong>남은 시간과 관계 없이 패턴이 종료됩니다.</strong></p>

<p>차원의 균열 패턴이 시전되고 난 후 가희가 플레이한 이벤트가 주어졌을 때, 패턴이 끝나고 파풀라투스는 몇 %의 체력을 회복할 수 있는지 구해 주세요.</p>

### 입력 

 <p>첫 번째 줄에 차원의 균열 패턴이 시전되었을 때, 파풀라투스의 시계가 가리키고 있는 시각이 <em>hh</em>:<em>mm</em> 형식으로 주어집니다.</p>

<p>두 번째 줄에는 1번 영역에 써져 있는 수부터 6번 영역에 써져 있는 수까지 공백으로 구분되어 주어집니다.</p>

<p>세 번째 줄에 이벤트의 수 <em>L</em>이 주어집니다.</p>

<p>다음 <em>L</em>개의 줄에는 발생한 이벤트 목록이 시간 순서대로 주어집니다. 이벤트 목록에 대한 형식은 아래와 같습니다.</p>

<ul>
	<li>s.T ^
	<ul>
		<li>게임 시간 s.T초에 가희가 시계 왼쪽 포탈에서 키보드 위쪽 키를 누릅니다.</li>
	</ul>
	</li>
	<li>s.T 10MIN
	<ul>
		<li>게임 시간 s.T초에 가희가 10MIN 아이템을 먹습니다.</li>
	</ul>
	</li>
	<li>s.T 30MIN
	<ul>
		<li>게임 시간 s.T초에 가희가 30MIN 아이템을 먹습니다.</li>
	</ul>
	</li>
	<li>s.T 50MIN
	<ul>
		<li>게임 시간 s.T초에 가희가 50MIN 아이템을 먹습니다.</li>
	</ul>
	</li>
	<li>s.T 2HOUR
	<ul>
		<li>게임 시간 s.T초에 가희가 2HOUR 아이템을 먹습니다.</li>
	</ul>
	</li>
	<li>s.T 4HOUR
	<ul>
		<li>게임 시간 s.T초에 가희가 4HOUR 아이템을 먹습니다.</li>
	</ul>
	</li>
	<li>s.T 9HOUR
	<ul>
		<li>게임 시간 s.T초에 가희가 9HOUR 아이템을 먹습니다.</li>
	</ul>
	</li>
</ul>

<p>s.T 포맷에서 s는 0 이상의 정수로 주어지며, T는 0 이상 999 이하의 정수로 주어집니다. 이때 T가 두 자릿수라면 T 앞에 0 이, 한 자릿수라면 T 앞에 00 이 붙습니다. 이는, 게임 시간 s+T×10<sup>-3</sup>초를 의미합니다.</p>

### 출력 

 <p>차원의 균열 패턴이 끝난 후, 파풀라투스가 회복하는 체력이 <em>h</em>%라고 할 때, <em>h</em>를 출력해 주세요.</p>

