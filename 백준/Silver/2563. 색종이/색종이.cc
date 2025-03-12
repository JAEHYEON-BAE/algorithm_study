// 2563

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  int a, b;
  std::bitset<10'000> map;
  map.reset();
  int cnt=0;
  while (n--) {
    std::cin >> a >> b;
    for (int i=a;i<a+10;++i) for (int j=b;j<b+10;++j) {
      if (!map[i*100+j]) {
        map.set(i*100+j);
        ++cnt;
      }
    }
  }
  std::cout << cnt;
 
  return 0;
}