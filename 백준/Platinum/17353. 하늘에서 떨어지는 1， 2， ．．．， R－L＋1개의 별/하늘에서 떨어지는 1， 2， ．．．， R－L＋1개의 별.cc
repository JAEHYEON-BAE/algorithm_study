// 17353

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;

struct Fenwick
{
  // 1 ~ n
  int n;  
  std::vector<ll> tree;

  Fenwick(int n): n(n), tree(n+1, 0) {}

  void update(int i, ll x) {
    for (;i<=n;i+=i&-i) tree[i]+=x;
  }

  ll query(int i) const {
    ll res=0ll;
    for (;i>0;i-=i&-i) res+=tree[i];
    return res;
  }
};

struct RURQ
{
  int n;
  Fenwick f1, f2;

  RURQ(int n): n(n), f1(n), f2(n) {}

  void update(int l, int r, ll x) {
    f1.update(l, x);
    f2.update(l, x*l);

    if (r+1<=n) {
      f1.update(r+1, -x);
      f2.update(r+1, -x*(r+1));
    }
  }

  ll query(int i) const {
    return (i+1LL)*f1.query(i)-f2.query(i);
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<ll> a(n);
  RURQ rurq(n);
  for (ll &x:a) std::cin >> x;

  // DIFFERENTIAL ARRAY !

  int q;  std::cin >> q;
  while (q--) {
    int cmd;  std::cin >> cmd;
    if (cmd==1) {
      int l, r;  std::cin >> l >> r;
      rurq.update(l, r, 1);
      if (r+1<=n) {
        rurq.update(r+1, r+1, -1LL*(r+1-l));
      }
    }
    else {
      int x;  std::cin >> x;
      std::cout << rurq.query(x)+a[x-1] << '\n';
    }
  }
  
  return 0;
}