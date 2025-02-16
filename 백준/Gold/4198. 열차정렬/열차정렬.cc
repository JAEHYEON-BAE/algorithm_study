// 4198

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
  for (int i=0;i<n;++i) std::cin >> v[i];
  if (n==0) {std::cout << 0; return 0;}

  int max=0;
  for (int i=0;i<n;++i) {
    std::vector<int> dp_lis, dp_lds;
    dp_lis.emplace_back(v[i]);
    dp_lds.emplace_back(v[i]);

    for (int j=i+1;j<n;++j) {
      if (v[j]>dp_lis[0]) {
        auto it=std::lower_bound(dp_lis.begin(), dp_lis.end(), v[j]);
        if (it==dp_lis.end()) dp_lis.emplace_back(v[j]);
        else *it=v[j];
      }
      if (v[j]<dp_lds[0]) {
        auto it=std::lower_bound(dp_lds.begin(), dp_lds.end(), v[j], std::greater<int>());
        if (it==dp_lds.end()) dp_lds.emplace_back(v[j]);
        else *it=v[j];
      }
    }
    max=std::max(max, static_cast<int>(dp_lis.size()+dp_lds.size())-1);
  }

  std::cout << max;

  return 0;
}