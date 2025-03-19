// 16088

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int p, q; std::string str;  std::cin >> p >> q >> str;
  if (p>q) std::swap(p, q);
  int x=-1, y=-1;
  for (int i=0;i<4;++i) if (str[i]=='A') {
    if (x==-1) x=i;
    else y=i;
  } 
  if (x+3==y && p+3==q) {
    std::cout << p+1 << ' ' << p+2;
  }
  else {
    if (x==2 && p==3) std::cout << "1 2";
    else if (y==1 && q==7) std::cout << "8 9";
    else if (x==0 && y==2 && p==6 && q==8) std::cout << "7 9";
    else if (x==1 && y==3 && p==2 && q==4) std::cout << "1 3";
    else if (x==1 && y==2 && p==2 && q==8) std::cout << "1 9";
    else std::cout << -1;
  }
  
  return 0;
}