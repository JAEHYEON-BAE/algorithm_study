// 33689

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  int cnt=0;
  for (int i=0;i<n;++i) {
    std::string s;  std::cin >> s;
    if (s.front()=='C') ++cnt;
  }
  std::cout << cnt;
  return 0;
}

