// 18017

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long double a, b;  std::cin >> a >> b;
  const long double c=299'792'458;

  long double result=(a+b)/(1+a*b/c/c);
  std::cout << std::fixed << std::setprecision(15) << result;
  
  return 0;
}