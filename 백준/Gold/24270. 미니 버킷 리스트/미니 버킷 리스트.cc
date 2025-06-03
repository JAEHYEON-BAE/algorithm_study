// 12660

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

static constexpr long long int MOD=1'000'000'007;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  int r=0;
  for (int i=0;i<n;++i) {
    int x;  std::cin >> x;
    r+=x;
  }
  r=k-r;
  long long int res=1;
  for (int i=r+1;i<=r+n;++i) res=res*i%MOD;
  std::cout << res;
  return 0;
}