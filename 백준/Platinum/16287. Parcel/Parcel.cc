// 16287

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int w, n;  std::cin >> w >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];
  std::sort(v.begin(), v.end());

  std::unordered_map<int, std::pair<int, int>> map;
  for (int i=0;i<n-1;++i) for (int j=i+1;j<n;++j) {
    if (!map.count(v[i]+v[j])) map[v[i]+v[j]]={i, j};
  }

  for (int i=0;i<n-1;++i) for (int j=i+1;j<n;++j) {
    int tmp=w-v[i]-v[j];
    if (tmp<0 || !map.count(tmp)) continue;
    const auto &[ii, jj]=map.at(tmp);
    if (ii!=i && ii!=j && jj!=i && jj!=j) {
      std::cout << "YES";
      return 0;
    }
  }
  std::cout << "NO";
  return 0;
}