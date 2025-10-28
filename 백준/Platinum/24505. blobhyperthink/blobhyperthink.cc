// 24505

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
constexpr ll MOD=1'000'000'007;

struct Fenwick
{
  int n;
  std::vector<ll> tree;

  Fenwick(int n): n(n), tree(n+1, 0) {}

  void insert(int i, ll x) {
    while (i<=n) {
      tree[i]+=x;
      tree[i]%=MOD;
      i+=i&-i;
    }
  }

  ll sum(int i) const {
    ll res=0;
    while (i>0) {
      res+=tree[i];
      res%=MOD;
      i-=i&-i;
    }
    return res;
  }
  ll sum(int l, int r) const {
    return (sum(r)-sum(l-1)+MOD)%MOD;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> a(n);
  for (int &x:a) std::cin >> x;  

  const int L=11;
  std::vector<Fenwick> fws(L, n);
  
  ll res=0LL;
  for (int i=0;i<n;++i) {
    ll x=a[i];
    ll dp;
    for (int len=L-1;len>=0;--len) {
      if (len==0) dp=1;
      else dp=fws[len-1].sum(x-1);

      fws[len].insert(x, dp);
      if (len==L-1) {
        res+=dp;
        res%=MOD;
      }
    }
  }
  std::cout << res;
  return 0;
}