// 1522

#include <iostream>
#include <vector>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;  std::cin >> s;
  int l=0;
  for (const char &c:s) if (c=='a') ++l;
  s+=s;
  int cntb=0;
  for (int i=0;i<l;++i) if (s[i]=='b') ++cntb;

  int res=cntb;
  for (int i=l;i<s.size();++i) {
    if (s[i-l]=='b') --cntb;
    if (s[i]=='b') ++cntb;

    res=std::min(res, cntb);
  }
  
  std::cout << res;
  return 0;
}

