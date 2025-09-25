// 31501

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <unordered_map>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

struct Fenwick
{
  int n;
  std::vector<int> tree;

  Fenwick(int n): n(n), tree(n+1, 0) {}

  void update(int i, int x) {
    while (i<=n) {
      tree[i]=std::max(tree[i], x);
      i+=i&-i;
    }
  }
  int query(int i) const {
    int res=0;
    while (i>0) {
      res=std::max(res, tree[i]);
      i-=i&-i;
    }
    return res;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, q;  std::cin >> n >> q;
  std::vector<int> d(n);
  std::set<int> set;
  for (int &x:d) {
    std::cin >> x;
    set.insert(x);
  }

  std::unordered_map<int, int> rank;
  int id=1;
  for (const int &x:set) rank[x]=id++;

  // coordinate compression
  for (int &x:d) x=rank[x];

  int m=rank.size();

  std::vector<int> l(n, 0), r(n, 0);
  Fenwick lf(m), rf(m);
  for (int i=0;i<n;++i) {
    l[i]=1+(d[i]>1?lf.query(d[i]-1):0);
    lf.update(d[i], l[i]);
  }
  for (int i=n-1;i>=0;--i) {
    int tmp=m+1-d[i];
    r[i]=1+(tmp>1?rf.query(tmp-1):0);
    rf.update(tmp, r[i]);
  }
  
  while (q--) {
    int a;  std::cin >> a;  --a;
    std::cout << l[a]+r[a]-1 << '\n';
  }
  
  return 0;
}