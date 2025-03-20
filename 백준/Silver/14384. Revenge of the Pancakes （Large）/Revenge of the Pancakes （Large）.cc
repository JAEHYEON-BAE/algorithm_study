// 14383

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  for (int i=0;i<t;) {
    std::string str;  std::cin >> str;
    int n=str.size();
    int cnt=0;
    int top=0;
    for (int i=1;i<n;++i) {
      if (str[i]!=str[i-1]) {
        ++cnt; top=(str[i-1]=='-');
      }
    }
    if (cnt) {if (!top) ++cnt;}
    else cnt+=(str[0]=='-');
    

    std::cout << "Case #" << ++i << ": " << cnt << '\n';
  }
  
  return 0;
}