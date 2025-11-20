// 14726

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
  while (t--) {
    std::string s;  std::cin >> s;

    int sum=0;
    for (int i=0;i<16;++i) {
      if (i&1) sum+=s[i]-'0';
      else {
        int d=2*(s[i]-'0');
        if (d>=10) d+=d/10, d%=10;
        sum+=d;
      }
    }
    if (sum%10) std::cout << "F\n";
    else std::cout << "T\n";
  }
  return 0;
}