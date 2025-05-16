// 15256

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  for (int i=1;i<=t;++i) {
    int n;  std::cin >> n;
    long double x, start=-1;
    while (n--) {
      std::cin >> x;
      
      if (x>=30.0L && x<=30.2 && n>=3) {
        start=x;
        break;
      }
    }

    if (start==-1) {
      std::cout << "Data Set " << i << ":\n0.00\n\n";
      continue;
    }

    for (int j=0;j<2;++j) std::cin >> x;
    
    n-=2;
    long double min=100.1L;
    while (n--) {
      std::cin >> x;
      min=std::min(min, x);
    }

    std::cout << "Data Set " << i << ":\n" << std::fixed << std::setprecision(2) << (min-30.0L) << "\n\n";
  }

  return 0;
}