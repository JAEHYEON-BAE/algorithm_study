// 1438

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  std::unordered_map<int, std::vector<int>> map;
  std::set<int> x_s;
  
  for (int i=0;i<n;++i) {
    int x, y;
    std::cin >> x >> y;

    map[x].push_back(y);
    x_s.insert(x);
  }

  std::vector<int> x_v;
  for (const int& x: x_s) x_v.push_back(x);

  int result = (~0u)>>1;
  for (int i=0;i<x_v.size();++i) for (int j=i;j<x_v.size();++j) {
    // select x range (i, j)
    std::vector<int> y_v;
    for (int k=i;k<=j;++k) for (const int& y: map[x_v[k]]) {
      y_v.push_back(y);
    }
    if (y_v.size()<n/2) continue;
    std::sort(y_v.begin(), y_v.end());
    for (int l=0;l+n/2-1<y_v.size();++l) {
      int area = (x_v[j]-x_v[i]+2)*(y_v[l+n/2-1]-y_v[l]+2);
      result = std::min(result, area);
    }
  }
  
  std::cout << result;
}

