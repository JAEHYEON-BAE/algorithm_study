// 30441
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<int> v(n);
  int max=0;
  for (int i=0;i<n;++i) {
    std::cin >> v[i];
    max=std::max(max, v[i]);
  }

  std::sort(v.begin(), v.end());
  
  for (int i=0;i<n-m;++i) {
    max=std::max(max, v[i]+v[(n-m)*2-1-i]);
  }
  std::cout << max;
  return 0;
}