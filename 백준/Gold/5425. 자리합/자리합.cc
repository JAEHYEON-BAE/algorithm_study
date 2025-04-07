// 5425
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

long long int digit_sum(const long long int &x)
{
  if (x<10) {
    int result=0;
    for (int i=0;i<=x;++i) result+=i;
    return result;
  }
  else for (int i=15;i>=0;--i) {
    if (x/power10[i]) {
      long long int d=x/power10[i]%10;
      long long int r=x%power10[i];
      if (r==power10[i]-1) return digit_sum(r)*(d+1) + digit_sum(d)*power10[i];
      else {
        return digit_sum(x-r-1) + digit_sum(r) + (r+1LL)*d;
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    long long int a, b;  std::cin >> a >> b;
    std::cout << digit_sum(b)-digit_sum(a>0?a-1:0) << '\n';
  }
  return 0;
}