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
  while (t--) {
    int n; std::string p;  std::cin >> n >> p;
    if (n==1) {
      std::cout << "8 2\n";
      continue;
    }
    int sum=0;
    for (const char &c:p) {
      sum+=static_cast<int>(c-'0');
    }
    sum%=3;
    for (int i=0;i<n;++i) {
      std::string tmp=p;
      int x=tmp[i]-'0';
      if (x-sum>0) tmp[i]-=sum;
      else tmp[i]+=3-sum;
      std::cout << tmp << " 3\n";
    }
  }
  
  return 0;
}