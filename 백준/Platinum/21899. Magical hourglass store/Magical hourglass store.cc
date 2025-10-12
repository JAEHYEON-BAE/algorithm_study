// 21899

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, t;  std::cin >> n >> t;
  std::vector<int> v(t+1, 0);

  const int rt=std::sqrt(t);

  std::vector<std::vector<int>> starts(1+rt);
  for (int i=0;i<n;++i) {
    int a, b;  std::cin >> a >> b;
    if (b>rt) for (int k=a;k<=t;k+=b) ++v[k];
    else if (a<=t) starts[b].push_back(a);
  }

  for (int b=1;b<=rt;++b) {
    if (starts[b].empty()) continue;

    std::vector<int> d(1+t, 0);
    for (const int &a:starts[b]) ++d[a];
    for (int k=b;k<=t;++k) d[k]+=d[k-b];
    for (int k=1;k<=t;++k) v[k]+=d[k];
  }
  
  for (int i=1;i<=t;++i) std::cout << v[i] << ' ';
  return 0;
}