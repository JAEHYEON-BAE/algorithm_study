// 20162

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];

  std::vector<int> dp=v;
  for (int i=0;i<n;++i) for (int j=0;j<i;++j) {
    if (v[i]>v[j]) dp[i]=std::max(dp[i], dp[j]+v[i]);
  }
  std::cout << *std::max_element(dp.begin(), dp.end());
  return 0;
}