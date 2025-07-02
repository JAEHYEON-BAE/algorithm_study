// 23943

#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  for (int i=1;i<=t;++i) {
    int l, r;  std::cin >> l >> r;
    std::vector<std::pair<int, int>> cnt(r-l+1, {0, 0});

    // d: divisor candidate
    for (int d=1;d*d<=r;++d) {
      
      // s: minimum number s.t. s>=l and d|s
      int s=(l%d)?(l/d+1)*d:l;

      // k: multiply of d s.t. k in [l, r]
      for (int k=s;k<=r;k+=d) {
        if (d>k/d) continue;

        if (d&1) ++cnt[k-l].first;
        else ++cnt[k-l].second;

        if ((k/d)&1) ++cnt[k-l].first;
        else ++cnt[k-l].second;
      }
    }
    
    int result=0;
    for (int i=0;i<=r-l;++i) if (std::abs(cnt[i].first-cnt[i].second)<=2) ++result;
    
    std::cout << "Case #" << i << ": " << result << '\n';
  }
  return 0;
}
