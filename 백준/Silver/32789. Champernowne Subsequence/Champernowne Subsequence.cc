// 32789

#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n; std::string s;
  std::cin >> n >> s;

  int i=0, num=0;
  while (i<n) {
    ++num;
    std::string snum=std::to_string(num);
    for (const char &c:snum) if (c==s[i]) {
      ++i;
      if (i==n) break;
    }
  }
  std::cout << num;
  return 0;
}
