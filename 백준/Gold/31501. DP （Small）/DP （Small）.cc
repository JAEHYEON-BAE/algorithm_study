// 31501

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

  int n, q;  std::cin >> n >> q;
  std::vector<int> d(n);
  for (int &x:d) std::cin >> x;

  std::vector<int> l(n, 0), r(n, 0);
  for (int i=0;i<n;++i) {
    int max=0;
    for (int j=0;j<i;++j) if (d[j]<d[i]) max=std::max(max, l[j]);
    l[i]=1+max;
  }
  for (int i=n-1;i>=0;--i) {
    int max=0;
    for (int j=n-1;j>i;--j) if (d[j]>d[i]) max=std::max(max, r[j]);
    r[i]=1+max;
  }
  
  while (q--) {
    int a;  std::cin >> a;  --a;
    std::cout << l[a]+r[a]-1 << '\n';
  }
  
  return 0;
}