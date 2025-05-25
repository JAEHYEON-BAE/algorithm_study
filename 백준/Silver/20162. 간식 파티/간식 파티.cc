// 20162

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::map<int, int> dp;
  dp[0]=0;
  
  for (int i=0;i<n;++i) {
    int k;  std::cin >> k;
    
    std::map<int, int> tmp;
    for (const auto &x:dp) {
      tmp[x.first]=std::max(tmp[x.first], x.second);
      if (x.first<k) tmp[k]=std::max(tmp[k], x.second+k); 
    }
    dp=tmp;
  }

  int max=0;
  for (const auto &x:dp) max=std::max(max, x.second);
  std::cout << max;
  return 0;
}