#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

int mod_pow(int a, int b)
{
  int res=1;
  a%=10;
  while (b) {
    if (b&1) res*=a, res%=10;
    a*=a, a%=10;
    b>>=1;
  }
  return res?res:10;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int a, b;  std::cin >> a >> b;
    std::cout << mod_pow(a, b) << '\n';
  }
  return 0;
}