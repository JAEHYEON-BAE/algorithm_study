// 16495

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, S, E;  std::cin >> n >> S >> E;
  long double total=0.0L;
  for (int i=0;i<n;++i) {
    int s=S, e=E;
    int r, a; long double d;  std::cin >> r >> a >> d;
    long double dps=d/static_cast<long double>(a);
    if (s%(r+a)<=r) s=s/(r+a)*(r+a);
    else {
      total+=static_cast<long double>(a-s%(r+a)+r)*dps;
      s=(s/(r+a)+1)*(r+a); 
    }

    if (e%(r+a)<=r) e=e/(r+a)*(r+a);
    else {
      total+=static_cast<long double>(e%(r+a)-r)*dps;
      e=e/(r+a)*(r+a);
    }

    total+=d*(e/(r+a)-s/(r+a));
  }
  std::cout << std::fixed << std::setprecision(10) << total/static_cast<long double>(E-S);

  return 0;
}