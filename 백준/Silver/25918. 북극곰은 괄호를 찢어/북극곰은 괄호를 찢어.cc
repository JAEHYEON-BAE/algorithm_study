// 25918

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::string s;  std::cin >> n >> s;

  int cntl=0, cntr=0;
  int O=0, X=0;
  int ans=0;
  for (int i=0;i<n;++i) {
    if (s[i]=='(') {
      if (X) --X;
      else ++O;
      ++cntl;
    }
    else if (s[i]==')') {
      if (O) --O;
      else ++X;
      ++cntr;
    }
    ans=std::max(ans, std::max(O, X));
  }
  if (cntl==cntr) std::cout << ans;
  else std::cout << "-1";
  
  return 0;
}

