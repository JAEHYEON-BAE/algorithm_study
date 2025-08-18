// 1263

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  std::map<int, int, std::greater<>> map;
  for (int i=0;i<n;++i) {
    int t, s;  std::cin >> t >> s;
    map[s]+=t;
  }

  int curr=map.begin()->first;
  for (auto &p:map) {
    if (p.first>=curr) curr-=p.second;
    else curr=p.first-p.second;
    // std::cout << p.first << ' ' << p.second << '\n';
  }
  std::cout << (curr<0?-1:curr);

  return 0;
}

