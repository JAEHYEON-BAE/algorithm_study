// 27378

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;

ll cnt(const ll &x, const int &k, const ll &n) 
{
  // dp[pos][cnt][tight]
  ll dp[65][65][2]={};
  dp[0][0][1]=1;

  for (int pos=1;pos<=64;++pos) {
    int p=(x>>(64-pos))&1;
    int q=(n>>(64-pos))&1;

    for (int cnt=0;cnt<=k;++cnt) {
      if (dp[pos-1][cnt][1]) {
        if (p==1) {
          dp[pos][cnt+(q^1)][1]+=dp[pos-1][cnt][1];
          dp[pos][cnt+(q^0)][0]+=dp[pos-1][cnt][1];
        }
        else dp[pos][cnt+(q^0)][1]+=dp[pos-1][cnt][1];
      }
      if (dp[pos-1][cnt][0]) {
        dp[pos][cnt+(q^1)][0]+=dp[pos-1][cnt][0];
        dp[pos][cnt+(q^0)][0]+=dp[pos-1][cnt][0];
      }
    }
  }
  
  return dp[64][k][0]+dp[64][k][1];
}
int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  ll n, a, b; int k;
  std::cin >> n >> k >> a >> b;

  std::cout << cnt(b, k, n)-cnt(a-1, k, n);
  
  return 0;
}