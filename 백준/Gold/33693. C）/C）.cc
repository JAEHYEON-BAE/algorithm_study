// 33693

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stack>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    std::string s;  std::cin >> s;
    int cnt=0;
    for (char &c:s) {
      if (c=='C') c='(';
      else if (c=='U') {
        c=')';
        ++cnt;
      }
    }
    
    int n=s.size();

    std::stack<int> stk;
    int open=0;
    for (int i=0;i<n;++i) {
      char &c=s[i];
      if (c==')') {
        if (!open) {
          c='(';
          ++open;
          stk.push(i);
        }
        else {
          --open;
          stk.pop();
        }
      }
      else {
        ++open;
        stk.push(i);
      }
    }

    if (stk.size()) {
      assert(!(stk.size()&1));
      int tmp=stk.size()>>1;
      while (tmp--) {
        s[stk.top()]=')';
        cnt+=2;
        stk.pop();
      }
    }
    std::cout << cnt << '\n' << s << '\n';
  }
  return 0;
}