// 1015

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::pair<int, int>> a(n);
  for (int i=0;i<n;++i) {
    std::cin >> a[i].first;
    a[i].second=i;
  }
  std::sort(a.begin(), a.end());
  std::vector<int> p(n);
  for (int i=0;i<n;++i) {
    p[a[i].second]=i;
  }
  for (int &x:p) std::cout << x << ' ';
  return 0;
}