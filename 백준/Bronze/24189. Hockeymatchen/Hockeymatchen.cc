// 34329

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int d1, g1, s1, d2, g2, s2;

  std::cin >> d1 >> g1 >> s1 >> d2 >> g2 >> s2;
  
  // d1+g2=s2
  // d2+g1=s1

  if (d1==-1) {
    if (g2==-1 && s2==0) d1=g2=0; 
    else if (g2!=-1 && s2!=-1) d1=s2-g2;
  }
  if (g2==-1) {
    if (d1==-1 && s2==0) d1=g2=0;
    else if (d1!=-1 && s2!=-1) g2=s2-d1;
  }
  if (s2==-1 && d1!=-1 && g2!=-1) s2=d1+g2;

  if (d2==-1) {
    if (g1==-1 && s1==0) d2=g1=0; 
    else if (g1!=-1 && s1!=-1) d2=s1-g1;
  }
  if (g1==-1) {
    if (d2==-1 && s1==0) d2=g1=0;
    else if (d2!=-1 && s1!=-1) g1=s1-d2;
  }
  if (s1==-1 && d2!=-1 && g1!=-1) s1=d2+g1;

  std::cout << d1 << ' ' << g1 << ' ' << s1 << '\n' << d2 << ' ' << g2 << ' ' << s2;
  
  return 0;
}