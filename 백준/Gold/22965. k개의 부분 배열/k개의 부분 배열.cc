// 8980

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  int x;  std::cin >> x;

  int l=x, r=x;
  int pre=x;

  std::vector<std::pair<int, int>> asc;
  for (int i=1;i<n;++i) {
    std::cin >> x;
    if (x>pre) r=x;
    else {
      asc.push_back({l, r});
      l=x, r=x;
    }
    pre=x;
  }
  asc.push_back({l, r});

  if (asc.size()==1) std::cout << 1;
  else if (asc.size()==2 && asc[0].first>asc[1].second) std::cout << 2;
  else std::cout << 3;
  
  return 0;
}