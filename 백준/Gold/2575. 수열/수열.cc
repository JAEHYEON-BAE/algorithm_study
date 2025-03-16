// 2575

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int m;  std::cin >> m;
  if (m==1) {
    std::cout << "1 1";
    return 0;
  }

  if (m<4) std::cout << 1 << ' ';
  else {
    if (m%3==2) std::cout << m/3+1 << ' ';
    else if (m%3==1) std::cout << (m-4)/3 + 2 << ' ';
    else std::cout << m/3 << ' ';
  }
  
  int cnt=0;
  while (m%4==0) {
    m/=4;
    ++cnt;
  }
  
  for (int i=2;;++i) {
    if (m==1) break;
    while (m%i==0) {
      m/=i;
      ++cnt;
    }
  }
  std::cout << cnt;
  return 0;
}