// 1427

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string n;  std::cin >> n;
  std::sort(n.begin(), n.end(), std::greater<char>());
  std::cout << n;
  
  return 0;
}