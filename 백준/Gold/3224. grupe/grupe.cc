// 3224

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);

std::string __result="";

void __push(std::stack<std::pair<int, int>> &stk, std::pair<int, int> p)
{
  if (stk.empty()) stk.push(p);
  else {
    int l=stk.top().first, r=stk.top().second;
    if (p.second==l-1) {
      stk.pop();
      __result.append(std::to_string(p.first)+' '+std::to_string(r)+'\n');
      __push(stk, std::make_pair(p.first, r));
    }
    else if (p.first==r+1) {
      stk.pop();
      __result.append(std::to_string(l)+' '+std::to_string(p.second)+'\n');
      __push(stk, std::make_pair(l, p.second));
    }
    else {
      stk.push(p);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::stack<std::pair<int, int>> stk;
  for (int i=0;i<n;++i) {
    int x;  std::cin >> x;
    __push(stk, std::make_pair(x, x));
  }
  if (stk.size()==1) {
    std::cout << "DA\n" << __result;
  }
  else {
    std::cout << "NE";
  }
 
  return 0;
}