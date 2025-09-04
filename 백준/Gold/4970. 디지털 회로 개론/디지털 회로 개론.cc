// 4970

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string str;
  while (std::cin >> str) {
    if (str==".") break;

    int cnt=0;
    for (int p=0;p<3;++p) for (int q=0;q<3;++q) for (int r=0;r<3;++r) {
      std::vector<char> stk;
      stk.reserve(str.size());
      
      for (char c:str) {
        
        if (c=='P') c=static_cast<char>(p+'0');
        else if (c=='Q') c=static_cast<char>(q+'0');
        else if (c=='R') c=static_cast<char>(r+'0');

        if (c==')') {
          char rhs=stk.back(); stk.pop_back();
          char op=stk.back();  stk.pop_back();
          char lhs=stk.back(); stk.pop_back();
          stk.pop_back();  // (

          char result;
          if (op=='+') {
            if (lhs=='0' && rhs=='0') result='0';
            else if (lhs=='2' || rhs=='2') result='2';
            else result='1';
          }
          else if (op=='*') {
            if (lhs=='0' || rhs=='0') result='0';
            else if (lhs=='2' && rhs=='2') result='2';
            else result='1';
          }
          else assert(!"INVALID OPERATION");

          if (stk.back()=='-') {
            stk.pop_back();
            result='2'-result+'0';
          }
          stk.push_back(result);
        }
        else if (stk.back()=='-') {
          if (c=='-') stk.pop_back();
          else if (c>='0' && c<='2') stk.pop_back(), stk.push_back('2'-c+'0');
          else stk.push_back(c);
        }
        else stk.push_back(c);
      }

      assert(stk.size()==1);
      if (stk[0]=='2') ++cnt;
    }
    std::cout << cnt << '\n';
  }
  
  
  return 0;
}