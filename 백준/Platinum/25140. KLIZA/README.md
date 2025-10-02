# [Platinum V] KLIZA - 25140 

[문제 링크](https://www.acmicpc.net/problem/25140) 

### 성능 요약

메모리: 38800 KB, 시간: 256 ms

### 분류

그래프 이론, 그래프 탐색, 집합과 맵, 너비 우선 탐색, 역추적

### 제출 일자

2025년 10월 2일 23:22:22

### 문제 설명

<p>Mladi programer Ivica dobio je za rođendan izrazito zanimljivu igračku imena <strong>klizeći 8-puzzle</strong>. Klizeći 8-puzzle je <strong>3x3 kvadrat</strong> koji sadrži <strong>8</strong> pokretnih jediničnih kvadratića na kojima su zapisani brojevi od 1 do 8 te jedno prazno polje.</p>

<p>Cilj igre je posložiti igračku krenuvši iz nekog početnog stanja pri čemu za igračku kažemo da je posložena ako je u stanju kao na slici:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/805e1ed4-1f27-4ac6-af0e-efb419f22eb4/-/preview/" style="width: 99px; height: 98px;"></p>

<p>Igru slažemo tako da u svakom koraku pomaknemo neki <strong>kvadratić susjedan praznom polju</strong> sa svoje pozicije na <strong>prazno polje</strong>. Na primjer, ako označimo slobodni kvadratić s X, tada vrijedi:</p>

<table class="table table-bordered th-center td-center">
	<thead>
		<tr>
			<th style="width:33%;">iz stanja</th>
			<th style="width:34%;">jednim korakom možemo pomicanjem trojke doći u stanje</th>
			<th style="width:33%;">ili pomicanjem jedinice u stanje</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><img alt="" src="https://upload.acmicpc.net/b8b4878b-e141-4fa1-933e-5a336f9a9de1/-/crop/195x196/0,0/-/preview/" style="width: 98px; height: 98px;"></td>
			<td><img alt="" src="https://upload.acmicpc.net/b8b4878b-e141-4fa1-933e-5a336f9a9de1/-/crop/195x196/422,0/-/preview/" style="width: 98px; height: 98px;"></td>
			<td><img alt="" src="https://upload.acmicpc.net/b8b4878b-e141-4fa1-933e-5a336f9a9de1/-/crop/195x196/889,0/-/preview/" style="width: 98px; height: 98px;"></td>
		</tr>
	</tbody>
</table>

<p>Tvoj zadatak je posložiti igračku u <strong>minimalnom</strong> broju koraka.</p>

### 입력 

 <p>Stanje u kojem se nalazi igračka: tri retka svaki s tri znaka odvojena razmakom uz točno jedan znak X, a ostali su brojevi između 1 i 8 od kojih se svaki pojavljuje točno jednom. Ulazni podaci bit će takvi da je uvijek moguće posložiti igračku.</p>

### 출력 

 <p>U prvi redak ispiši N, broj koraka koje tvoje rješenje zahtijeva da posloži igračku. U drugom retku ispiši N prirodnih brojeva odvojenih razmakom gdje je i-ti broj broj zapisan na polju koje je pomaknuto na prazno polje (X) u i-tom potezu. Budući da rješenje ne mora biti jedinstveno, potrebno je ispisati bilo koje.</p>

