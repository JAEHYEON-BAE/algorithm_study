// 33690

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;  std::cin >> s;
  int n=s.size(), cnt=0;
  cnt+=(n-1)*9;
  cnt+=(s[0]-'1');

  bool FLAG=1;
  for (const char &c:s) {
    if (c<s[0]) {FLAG=0;break;}
    if (c>s[0]) {FLAG=1;break;}
  }

  if (FLAG) ++cnt;

  ++cnt; // 0
  std::cout << cnt;
  return 0;
}

