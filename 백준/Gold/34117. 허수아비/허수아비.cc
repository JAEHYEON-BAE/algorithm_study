// 34117

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

  int n, p;  std::cin >> n >> p;
  std::multiset<int, std::greater<>> s;
  for (int i=0;i<n;++i) {
    int x; std::cin >> x;
    s.insert(x);

    int tmp=p;
    auto it=s.begin();
    int cnt=0;
    while (tmp>0 && it!=s.end()) {
      tmp-=*it;
      std::advance(it, 1);
      ++cnt;
    }
    if (tmp>0) std::cout << "-1 ";
    else std::cout << cnt << ' ';
  }
  
  return 0;
}