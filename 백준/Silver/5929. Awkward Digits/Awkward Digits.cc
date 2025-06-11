// 5929

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

std::string b2t(std::string b, int &x)
{
  x=0;
  for (int i=0;i<b.size();++i) {
    if (b[i]=='1') x+=1<<(b.size()-i-1);
  }
  int tmp=x;
  std::string res="";
  while (tmp) {
    res+='0'+tmp%3;
    tmp/=3;
  }
  std::reverse(res.begin(), res.end());
  return res;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  
  std::string b,t;  std::cin >> b >> t;
  int x=0;
  for (char &c:b) {
    c='0'+'1'-c;
    std::string tmp=b2t(b, x);
    if (tmp.size()==t.size()) {
      int n=tmp.size();
      int cnt=0;
      for (int i=0;i<n;++i) {
        if (tmp[i]!=t[i]) ++cnt;
        if (cnt>=2) break;
      }
      if (cnt==1) {
        std::cout << x;
        return 0;
      }
    }
    c='0'+'1'-c;
  }

  return 0;
}
