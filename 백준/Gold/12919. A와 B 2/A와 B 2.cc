// 12919

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);

void compare(const std::string &s, std::string t)
{
  if (s==t) {
    std::cout << 1; exit(0);
  }
  if (s.size()>t.size()) return;
  
  std::string tmp=t;
  if (tmp.back()=='A') {tmp.pop_back(); compare(s, tmp);}
  if (t[0]=='B') {
    std::reverse(t.begin(), t.end());
    t.pop_back();
    compare(s, t);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s, t;  std::cin >> s >> t;
  compare(s, t);
  std::cout << 0;

  return 0;
}