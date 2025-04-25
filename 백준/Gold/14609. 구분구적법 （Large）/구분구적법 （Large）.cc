// 14609

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

long double f(long double x, const std::vector<long double> &c, const int &k)
{
  long double res=0.0L;
  for (int i=0;i<=k;++i) {
    res+=std::pow(x, k-i)*c[i];
  }
  
  return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int k;  std::cin >> k;
  std::vector<long double> c(k+1);
  for (int i=0;i<=k;++i) std::cin >> c[i];
  long double a, b, n;  std::cin >> a >> b >> n;

  long double R=0.0L;

  for (int i=0;i<=k;++i) {
    R+=(std::pow(b, k+1-i)-std::pow(a, k+1-i))/static_cast<long double>(k+1-i)*c[i];
  }

  long double dx=(b-a)/n;

  long double l=0, r=dx;

  while (l+1e-12<r) {
    long double eps=(l+r)/2.0L;
    long double AR=0.0L;
    for (int i=0;i<n;++i) {
      AR+=f(a+dx*i+eps, c, k)*dx;
    }
    
    if (std::abs(AR-R) < 1e-4) break;
    else if (AR<R) l=eps;
    else if (AR>R) r=eps;
  }
  std::cout << (l+r)/2.0L;
  return 0;
}