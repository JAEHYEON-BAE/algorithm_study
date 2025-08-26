// 10375

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

constexpr int digit_sum(int x) 
{
  int res=0;
  while (x) {
    res+=x%10;
    x/=10;
  }
  return res;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  std::array<long long int, 55> sum{};
  std::array<int, 55> cnt{};

  std::array<long long int, 5001> res{};
  std::fill(res.begin(), res.end(), (~0uLL)>>1);

  for (long long int x=1;x<1'000'000;++x) {
    int digit=digit_sum(x);
    if (cnt[digit]<5000) {
      sum[digit]+=x;
      int k=++cnt[digit];
      res[k]=std::min(res[k], sum[digit]);
    }
  }
  
  std::cout << res[n];
  
  return 0;
}
