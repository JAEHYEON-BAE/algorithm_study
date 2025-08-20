// 3663

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    std::string s;  std::cin >> s;
    int n=s.size();

    int total=0;
    std::vector<int> togo;
    for (int i=0;i<n;++i) {
      int tmp=std::min(s[i]-'A', 'A'+26-s[i]);
      total+=tmp;
      if (tmp && i) togo.push_back(i);
    }

    if (togo.empty()) {
      std::cout << total << '\n';
      continue;
    }

    // DEBUG(total);

    int mv=std::min(togo.back(), n-togo[0]);
    int m=togo.size();
    for (int i=0;i<m-1;++i) {
      int d=std::min(togo[i], n-togo[i+1]);
      mv=std::min(mv, d+togo[i]+n-togo[i+1]);
    }

    // DEBUG(mv);
    std::cout << total+mv << '\n';
  }

  return 0;
}

