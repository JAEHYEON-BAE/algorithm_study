// 12919

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);

bool compare(const std::string &s, std::string t)
{
  if (s==t) {
    return true;
  }
  if (s.size()>t.size()) return false;
  
  std::string tmp=t;
  bool success=false;
  if (tmp.back()=='A') {tmp.pop_back(); success=compare(s, tmp);}
  if (!success && t[0]=='B') {
    std::reverse(t.begin(), t.end());
    t.pop_back();
    success=compare(s, t);
  }
  return success;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s, t;  std::cin >> s >> t;
  std::cout << compare(s, t);

  return 0;
}
