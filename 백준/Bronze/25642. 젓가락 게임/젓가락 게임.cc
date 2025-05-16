// 25642

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

bool solve(int a, int b, bool x)
{
  if (a+b>=5) return x;
  else {
    if (x) return solve(a, a+b, x^1);
    else return solve(a+b, b, x^1);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int a, b;  std::cin >> a >> b;
  if (solve(a, b, 1)) std::cout << "yt";
  else std::cout << "yj";

  return 0;
}