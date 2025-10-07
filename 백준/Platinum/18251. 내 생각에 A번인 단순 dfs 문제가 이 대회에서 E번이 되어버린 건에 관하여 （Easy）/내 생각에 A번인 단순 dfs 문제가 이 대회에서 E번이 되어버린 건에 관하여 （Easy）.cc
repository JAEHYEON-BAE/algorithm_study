// 18251

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;

void build(int node, int l, int r, int d, std::vector<std::vector<ll>> &a, const std::vector<ll> &v)
{
  int mid=(l+r)>>1;
  a[d][mid]=v[node];
  if ((node<<1)>=v.size()) return;
  build(node<<1, l, mid, d+1, a, v);
  build(1|node<<1, mid+1, r, d+1, a, v);
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<ll> v(n+1, 0);

  bool ALL_NEG=1;
  for (int i=1;i<=n;++i) {
    std::cin >> v[i];
    if (v[i]>0LL) ALL_NEG=0;
  }

  if (ALL_NEG) {
    std::cout << *std::max_element(1+v.begin(), v.end());
    return 0;
  }


  int k=__builtin_ctz(n+1);
  
  std::vector<std::vector<ll>> a(k, std::vector<ll>(n, 0));
  build(1, 0, n, 0, a, v);

  ll res=1LL<<63;

  std::vector<ll> cmp(n);
  for (int rs=0;rs<k;++rs) {
    std::fill(cmp.begin(), cmp.end(), 0);
    for (int re=rs;re<k;++re) {
      for (int i=0;i<n;++i) cmp[i]+=a[re][i];

      ll sum=cmp[0];
      ll max=cmp[0];

      for (int i=1;i<n;++i) {
        sum=std::max(cmp[i], sum+cmp[i]);
        max=std::max(max, sum);
      }

      res=std::max(res, max);
    }
  }
  std::cout << res;
  return 0;
}