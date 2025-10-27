// 26651

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

static const std::string BASE="BCDEFGHIJKLMNOPQRSTUVWXY";

std::pair<int, int> divide(int x)
{
  // x = p^2+q (maximize p)
  int p=std::sqrt(x);
  int q=x-p*p;
  return {p, q};
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int x;  std::cin >> x;
  if (x==0) {std::cout << "BAEKJOON"; return 0;}

  std::string res="";
  while (x>50) {
    auto [p, q]=divide(x);
    // std::cout << p << ' ' << q << '\n';
    
    std::string tmp="";
    
    for (int i=0;i<p;++i) tmp+='A';
    tmp+=BASE;
    for (int i=0;i<p;++i) tmp+='Z';

    res+=tmp;
    x=q;
  }
  if (x>0) {
    for (int i=0;i<x;++i) res+='A';
    res+=BASE;
    res+='Z';
  }
  
  std::cout << res;
  
  
  return 0;
}