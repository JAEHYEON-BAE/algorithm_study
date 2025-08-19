// 31784

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::string s;
  std::cin >> n >> k >> s;

  for (char &c:s) {
    if (c=='A') continue;
    else if ('Z'+1-c<=k) k-='Z'+1-c, c='A';
  }

  k%=26;
  int d=s.back()-'A';
  d+=k;
  d%=26;
  s.back()=d+'A';
  std::cout << s;
  
  return 0;
}

