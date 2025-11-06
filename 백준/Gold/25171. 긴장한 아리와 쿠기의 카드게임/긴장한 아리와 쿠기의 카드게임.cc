// 25171

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;

ll count(const std::vector<ll> &sum, ll T)
{
  int n=sum.size();
  ll cnt=0LL;
  int l=0, r=0;
  for (;r<n;++r) {
    while (l<=r && sum[r]-(l?sum[l-1]:0)>T) ++l;
    cnt+=r-l+1;
  }
  return cnt;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  ll x, y;  std::cin >> x >> y;
  std::vector<ll> v(n), sum(n+1, 0LL);
  for (int i=0;i<n;++i) {
    std::cin >> v[i];
    sum[i+1]=sum[i]+v[i];
  }

  ll cnt=0LL;
  for (int i=0;i<n;++i) for (int j=i;j<n;++j) {
    ll ap=sum[j+1]-sum[i];
    ll T=(y+ap-1)/ap*x;

    // std::cout << i << ' ' << j << '\t' << T << '\t';
    std::vector<ll> ksum;
    for (int k=0;k<n;++k) {
      if (k>=i && k<=j) continue;
      else ksum.push_back((ksum.empty()?0:ksum.back())+v[k]);
    }
    int l=ksum.size();
    // for (int k=0;k<l;++k) std::cout << ksum[k] << ' ';
    // std::cout << '\t';
    // std::cout << (l+1)*l/2 - count(ksum, T) << std::endl;
    cnt+=(l+1)*l/2-count(ksum, T);
  }
  if (cnt) std::cout << cnt;
  else std::cout << "IMPOSSIBLE";
  return 0;
}