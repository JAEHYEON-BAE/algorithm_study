// 21311

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string str;  std::cin >> str;
  std::vector<std::pair<int, int>> num(26, std::make_pair(-1, -1));
  for (int i=0;i<str.size();++i) {
    int x=static_cast<int>(str[i]-'a');
    if (num[x].first==-1) num[x].first=i;
    else if (num[x].second==-1) {
      num[x].second=i;
      if (!((num[x].second-num[x].first)&1)) {
        std::cout << "NO";
        return 0;
      }
    }
    else {
      std::cout << "NO";
      return 0;
    }
  }
  std::cout << "YES";
  return 0;
}