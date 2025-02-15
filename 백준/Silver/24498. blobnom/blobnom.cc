// 24498

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];

  int max=0;
  for (int i=1;i<n-1;++i) {
    max=std::max(max, v[i]+std::min(v[i-1], v[i+1]));
  }
  max=std::max(max, std::max(v[0], v[n-1]));
  std::cout << max;
  
  return 0; 
}