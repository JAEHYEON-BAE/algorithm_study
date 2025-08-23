// 19805

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int cnt(int n, int idx, const std::vector<int> &c)
{
  if (n==0) return 1;
  if (idx>=c.size()) return 0;
  int res=0;
  for (int i=idx;i<c.size();++i) {
    int prev=c[i];
    while (prev<=n) {
      res+=cnt(n-prev, i+1, c);
      prev+=c[i];
    }
  }
  return res;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, c;  std::cin >> n >> c;
  std::vector<int> v(c);
  for (int &i:v) std::cin >> i;

  std::cout << cnt(n, 0, v);
  return 0;
}

