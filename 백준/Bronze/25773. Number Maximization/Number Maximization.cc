// 25773

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string str;  std::cin >> str;
  std::sort(str.begin(), str.end(), std::greater<char>());
  std::cout << str;
  
  return 0; 
}