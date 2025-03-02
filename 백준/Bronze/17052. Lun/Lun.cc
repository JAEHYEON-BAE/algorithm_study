// 19575

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int MOD=1'000'000'007;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::string str;  std::cin >> n >> str;
  if (str.back()=='x') {
    int x=0;
    for (int i=0;i<n-1;++i) {
      int idx=n-2-i;
      if (i&1) x+=static_cast<int>(str[idx]-'0');
      else {
        int tmp=static_cast<int>(str[idx]-'0')<<1;
        x+=tmp/10+tmp%10;
      }
    }
    x=x*9%10;
    std::cout << x;
    return 0;
  }
  else {
    int x=0;
    bool __double=false;
    for (int i=0;i<n-1;++i) {
      int idx=n-2-i;
      if (i&1) {
        if (str[idx]=='x') continue;
        else x+=static_cast<int>(str[idx]-'0');
      }
      else {
        if (str[idx]=='x') {
          __double=true;
          continue;
        }
        else {
          int tmp=static_cast<int>(str[idx]-'0')<<1;
          x+=tmp/10+tmp%10;
        }
      }
    }
    for (int i=0;i<10;++i) {
      int tmp=i;
      int tmp_x=x;
      if (__double) {
        tmp<<=1;
        tmp_x+=tmp/10+tmp%10;
      } 
      else tmp_x+=tmp;
      if (tmp_x*9%10==static_cast<int>(str.back()-'0')) {
        std::cout << i;
        return 0;
      }
    }
  }
  return 0;
}