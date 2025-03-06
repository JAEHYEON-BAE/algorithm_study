// 24464

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};
const int MOD = 1'000'000'007;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> dp={1, 1, 1, 1, 1};
  for (int i=1;i<n;++i) {
    std::vector<int> tmp=dp; 
    dp[0]=(((tmp[1]+tmp[2])%MOD+tmp[3])%MOD+tmp[4])%MOD;
    dp[1]=((tmp[0]+tmp[3])%MOD+tmp[4])%MOD;
    dp[2]=(tmp[0]+tmp[4])%MOD;
    dp[3]=(tmp[0]+tmp[1])%MOD;
    dp[4]=((tmp[0]+tmp[1])%MOD+tmp[2])%MOD;
  }
  std::cout << ((((dp[0]+dp[1])%MOD+dp[2])%MOD+dp[3])%MOD+dp[4])%MOD;
  return 0;
}