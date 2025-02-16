// 1818

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n); 

  std::vector<int> dp;
  int x;
  for (int i=0;i<n;++i) {
    std::cin >> x;
    v[i]=x;
    auto iter=std::lower_bound(dp.begin(), dp.end(), x);
    if (iter==dp.end()) dp.push_back(x);
    else *iter=x;
  }
  std::cout << n-dp.size();

  return 0;
}