// 12903

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

using ll=long long int;
constexpr ll MOD=1'000'000'007LL;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  // preprocess: combination
  std::array<std::array<ll, 1001>, 1001> comb;

  for (int i=0;i<=1000;++i) comb[i][0]=comb[i][i]=1LL;
  
  for (int i=1;i<=1000;++i) {
    for (int j=1;j<=((i+1)>>1);++j) {
      comb[i][j]=comb[i][i-j]=(comb[i-1][j]+comb[i-1][j-1])%MOD;
    }
  }
  
  int k; std::cin >> k;

  ll res=1;
  int sum=0;
  
  int x;
  while (std::cin >> x) {
    res*=comb[sum+x-1][x-1];
    res%=MOD;
    sum+=x;
  }
  
  std::cout << res;
  return 0;
}

