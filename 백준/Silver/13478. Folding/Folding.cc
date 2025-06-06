// 13478

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>


inline int count(int from, int to)
{
  if (from<to) return -1;
  int cnt=0;
  while (from>to) {
    from=(from+1)>>1;
    ++cnt;
  }
  return cnt;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int W, H, w, h;
  std::cin >> W >> H >> w >> h;
  
  int a1=count(W, w), a2=count(H, h);
  int b1=count(W, h), b2=count(H, w);

  if (a1!=-1 && a2!=-1 && b1!=-1 && b2!=-1) {
    std::cout << std::min(a1+a2, b1+b2);
    return 0;
  }
  if (a1==-1 || a2==-1) {
    if (b1==-1 || b2==-1) {
      std::cout << -1;
      return 0;
    }
    std::cout << b1+b2;
    return 0;
  }
  else std::cout << a1+a2;
  return 0;
}