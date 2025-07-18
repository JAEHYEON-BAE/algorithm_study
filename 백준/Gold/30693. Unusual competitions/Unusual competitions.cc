// 30693

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  if (n&1) {
    std::cout << "-1";
    return 0;
  }
  std::string s;  std::cin >> s;

  int cnt=0;
  int tmp=0;
  int balance=0;

  for (const char &c:s) {
    if (c=='(') {
      ++balance;
      if (balance==0) ++tmp;
    }
    else --balance;

    if (balance<0) ++tmp;
    else if (balance==0) {
      cnt+=tmp;
      tmp=0;
    }
  }
  if (balance) std::cout << "-1";
  else std::cout << cnt;
  return 0;
}