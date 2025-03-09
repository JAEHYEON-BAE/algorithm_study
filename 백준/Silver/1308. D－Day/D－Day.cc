// 1308

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int date(int y, int m, int d)
{
  int tmp=0;
  --y;
  tmp+=y*365;
  tmp+=y/4-y/100+y/400;
  ++y;
  for (int i=1;i<m;++i) {
    if (i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
      tmp+=31;
    else if (i==2) {
      tmp+=28;
      if (y%4==0 && (y%100!=0 || y%400==0)) ++tmp;
    }
    else tmp+=30;
  }
  tmp+=d;
  
  return tmp;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a, b, c;
  int x, y, z;
  std::cin >> a >> b >> c >> x >> y >> z;
  if (x-a>1000) {std::cout << "gg"; return 0;}
  else if (x-a==1000) {
    if (y>b) {std::cout << "gg"; return 0;}
    else if (y==b) {
      if (z>=c) {std::cout << "gg"; return 0;}
    }
  }

  std::cout << "D-" << date(x, y, z)-date(a, b, c);

  return 0;
}