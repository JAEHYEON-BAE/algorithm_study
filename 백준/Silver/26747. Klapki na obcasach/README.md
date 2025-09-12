# [Silver I] Klapki na obcasach - 26747 

[문제 링크](https://www.acmicpc.net/problem/26747) 

### 성능 요약

메모리: 4616 KB, 시간: 36 ms

### 분류

그리디 알고리즘, 정렬

### 제출 일자

2025년 9월 12일 20:17:43

### 문제 설명

<p>W Bajtocji powstał właśnie nowy aquapark, a w nim zjeżdżalnia. Niestety, do zjazdu z tej zjezdżalni dopuszczone są tylko osoby mające co najmniej T bajtometrów wzrostu.</p>

<p>Na szczęście w sklepie przy aquaparku można kupić specjalne klapki na obcasach. Założenie j-tej pary klapek powoduje, że staje się wyższym o A<sub>j</sub> bajtometrów, a do pomiaru wzrostu nikt przecież klapek zdejmować nie każe. Rzecz jasna, każda osoba może założyć co najwyżej jedną parę klapek.</p>

<p>Bajtek wraz z grupą przyjaciół chcą teraz mądrze rozplanować, jakie klapki należy kupić i założyć, aby jak najwięcej osób mogło zjechać ze zjeżdżalni. Ze względów higienicznych osoby nie mogą się po założeniu wymieniać klapkami.</p>

<p>Napisz program, który wyznaczy największą liczbę osób jakie mogą zjechać ze zjeżdżalni (dla optymalnego rozplanowania klapek).</p>

### 입력 

 <p>W pierwszym wierszu wejścia znajduje się jedna liczba naturalna N (1 ≤ N ≤ 200 000) określająca liczbę osób w grupie (razem z Bajtkiem). W drugim wierszu znajduje się ciąg N liczb naturalnych H<sub>i</sub> (1 ≤ H<sub>i</sub> ≤ 10<sup>9</sup>) pooddzielanych pojedynczymi odstępami. Są to wzrosty kolejnych osób w grupie. W trzecim wierszu wejścia znajduje się jedna nieujemna liczba całkowita M (0 ≤ M ≤ 200 000) określająca liczbę par klapek, które są dostępne w sklepie. W czwartym wierszu wejścia znajduje się ciąg M liczb naturalnych A<sub>j</sub> (1 ≤ A<sub>j</sub> ≤ 10<sup>9</sup>) pooddzielanych pojedynczymi odstępami. Są to rozmiary obcasów w kolejnych parach klapek w sklepie. W piątym (ostatnim) wierszu wejścia znajduje się jedna liczba naturalna T (1 ≤ T ≤ 2 · 10<sup>9</sup>) – minimalny wzrost, od którego można zjechać ze zjeżdżalni.</p>

### 출력 

 <p>W pierwszym (jedynym) wierszu wyjścia należy wypisać jedną nieujemną liczbę całkowitą – największą możliwą liczbę osób, które mogą zjechać ze zjeżdżalni zgodnie z warunkami powyżej.</p>

