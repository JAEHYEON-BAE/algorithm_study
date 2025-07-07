// 14785

#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::pair<int, int>> v(n);
  for (int i=0;i<n;++i) {
    int p, l; std::cin >> p >> l;
    v[i].second=p, v[i].first=p+l;
  }

  std::sort(v.begin(), v.end());

  int cnt=0, last_cut=-1;
  for (const auto &pair:v) {
    if (last_cut<pair.second) {
      last_cut=pair.first-1;
      ++cnt;
    }
  }
  std::cout << cnt;
  return 0;
}