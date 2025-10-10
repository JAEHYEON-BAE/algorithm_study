// 12454

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

  int t;  std::cin >> t;
  for (int tc=1;tc<=t;++tc) {
    int m, c, w;  std::cin >> m >> c >> w;
    --w;

    std::vector<std::pair<int, int>> cuts(c);
    for (auto &cut:cuts) {
      std::cin >> cut.first >> cut.second;
      --cut.first;
    }
    for (int i=c-1;i>=0;--i) {
      const auto &[a, b]=cuts[i];
      if (w<b) w+=a;
      else if (w<a+b) w-=b;
      else continue;
    }
    std::cout << "Case #" << tc << ": " << w+1 << '\n';
  }
  
  return 0;
}