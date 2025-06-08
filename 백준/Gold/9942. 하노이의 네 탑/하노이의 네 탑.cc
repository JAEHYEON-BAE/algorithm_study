// 9942

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <array>

static constexpr long long int INFL=(~0ul)>>1;

template <size_t N>
std::array<long long int, N> build()
{
  std::array<long long int, N> res={};
  res[0]=0, res[1]=1, res[2]=3;
  for (int i=3;i<N;++i) {
    res[i]=INFL;
    for (int j=i-1;j>=0;--j) {
      if ((1LL<<(i-j))-1<0) break;
      long long int tmp=2*res[j]+(1LL<<(i-j))-1;
      if (tmp<0) break;
      res[i]=std::min(res[i], tmp);
    }
  }
  return res;
}
auto hanoi_4=build<1001>();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int tc=0, n;
  while (std::cin >> n) {
    std::cout << "Case " << ++tc << ": " << hanoi_4[n] << '\n';
  }

  return 0;
}