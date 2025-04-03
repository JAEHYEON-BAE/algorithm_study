// 14891
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>1;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::bitset<8> wheel[4];
  std::cin >> wheel[0] >> wheel[1] >> wheel[2] >> wheel[3];

  int k;  std::cin >> k;
  while (k--) {
    int x, d;  std::cin >> x >> d;
    int rotate[4]={0,};
    rotate[--x]=d;
    for (int i=x;i>0;--i) {
      if (wheel[i][1]==wheel[i-1][5]) break;
      rotate[i-1]=(x-i)&1?d:-d;
    }
    for (int i=x;i<3;++i) {
      if (wheel[i][5]==wheel[i+1][1]) break;
      rotate[i+1]=(i-x)&1?d:-d;
    }

    for (int i=0;i<4;++i) {
      if (rotate[i]==1) {
        bool first=wheel[i][0];
        wheel[i]>>=1;
        if (first) wheel[i].set(7);
      }
      else if (rotate[i]==-1) {
        bool last=wheel[i][7];
        wheel[i]<<=1;
        if (last) wheel[i].set(0);
      }
      else continue;
    }
  }

  int score=0;
  for (int i=0;i<4;++i) {
    if (wheel[i][7]) score+=1<<i;
  }
  std::cout << score;

  return 0;
}