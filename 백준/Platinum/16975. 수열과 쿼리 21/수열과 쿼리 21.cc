// 16975

#include <iostream>
#include <vector>
#include <algorithm>

class SegTree
{
  const std::vector<int> &v;
  std::vector<long long> tree;
  std::vector<long long> lazy;

  void build(int node, int s, int e) {
    if (s==e) {
      tree[node]=static_cast<long long>(v[s]); return;
    }
    int mid=(s+e)/2;
    build(node*2, s, mid); build(node*2+1, mid+1, e);
    tree[node]=tree[node*2]+tree[node*2+1];
    return;
  }

  void update(const int& l, const int& r, const long long& k, int node, int s, int e) {
    if (lazy[node]) {
      tree[node]+=lazy[node]*(e+1-s);
      if (s!=e) {
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
      }
      lazy[node]=0;
    }
    if (r<s || l>e) return;
    if (l<=s && e<=r) {
      tree[node]+=k*(e+1-s);
      if (s!=e) {
        lazy[node*2]+=k; lazy[node*2+1]+=k;
      }
      return;
    }
    int mid=(s+e)>>1;
    update(l, r, k, node*2, s, mid);
    update(l, r, k, node*2+1, mid+1, e);
    tree[node]=tree[node*2]+tree[node*2+1];
    return;
  }

  long long print(const int& x, int node, int s, int e) {
    if (lazy[node]) {
      tree[node]+=lazy[node]*(e+1-s);
      if (s!=e) {
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
      }
      lazy[node]=0;
    }
    if (x<s || e<x) return 0;
    if (s==x && e==x) { 
      return tree[node];
    }
    int mid=(s+e)>>1;
    return print(x, node*2, s, mid) 
         + print(x, node*2+1, mid+1, e);
  }

public:
  SegTree(const std::vector<int> &v): v(v) {
    tree.assign(v.size()*4, 0);
    lazy.assign(v.size()*4, 0);
    build(1, 0, v.size()-1);
  }
  void query(const int &i, const int &j, const long long &k) {
    update(i, j, k, 1, 0, v.size()-1);
  }
  long long query(const int &x) {
    return print(x, 1, 0, v.size()-1);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];

  SegTree st(v);

  int m;  std::cin >> m;
  int type, i, j, x;
  long long k;
  while (m--) {
    std::cin >> type;
    if (type==1) {
      std::cin >> i >> j >> k;
      st.query(i-1, j-1, k);
    } else {
      std::cin >> x;
      std::cout << st.query(x-1) << '\n';
    }
  }

  return 0; 
}
