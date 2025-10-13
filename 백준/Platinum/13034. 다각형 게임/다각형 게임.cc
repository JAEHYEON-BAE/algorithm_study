// 13034

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> G(n+1);
  G[0]=0;
  G[1]=0;
  G[2]=1;
  for (int i=3;i<=n;++i) {
    std::set<int> s;
    s.insert(G[i-2]);
    for (int j=1;j<=i-j-2;++j) s.insert(G[j]^G[i-j-2]);
    int tmp=0;
    while (s.count(tmp)) ++tmp;
    G[i]=tmp;
  }
  std::cout << (G[n]?1:2);
  return 0;
}