// 29682

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;

struct Fenwick
{
  int n;
  std::vector<ll> tree;

  Fenwick(int n): n(n), tree(n+1, 0) {}

  void update(int idx, ll v) {
    while (idx<=n) {
      tree[idx]=std::max(tree[idx], v);
      idx+=idx&-idx;
    }
  }
  ll query(int idx) const {
    ll res=0;
    while (idx>0) {
      res=std::max(res, tree[idx]);
      idx-=idx&-idx;
    }
    return res;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<ll> w(n+1);
  ll tot=0;
  for (int i=1;i<=n;++i) {
    std::cin >> w[i]; tot+=w[i];
  }
  std::vector<int> a(n);
  for (int &x:a) {
    std::cin >> x;
  }

  Fenwick fw(n);

  // maximum weight increasing subsequence
  // dp[i]=w[a[i]]+max{dp[j] s.t. j<i && a[j]<a[i]};
  ll max=0;
  for (int i=0;i<n;++i) {
    ll curr=w[a[i]]+(a[i]>1?fw.query(a[i]-1):0);
    fw.update(a[i], curr);
    max=std::max(max, curr);
  }

  std::cout << (tot-max)*2;
  return 0;
}