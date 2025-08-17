// 14315

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
  for (int tc=1;tc<=t;++tc) {
    long long int l, r;  std::cin >> l >> r;
    while (l>r) --l;
    while (r>l) --r;

    std::cout << "Case #" << tc << ": " << (l+1)*l/2 << '\n';
  }
  
  return 0;
}

