// 9793

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <map>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::cin.ignore();

  std::map<int, int> result;
  while (n--) {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss(line);
    std::string word;

    int cnt=0;
    while (ss>>word) ++cnt;
    ++result[cnt];
  }
  for (const auto &p:result) {
    std::cout << p.first << ' ' << p.second << '\n';
  }
  return 0;
}