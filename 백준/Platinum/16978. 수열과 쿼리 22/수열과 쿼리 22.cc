// 16978

#include <iostream>
#include <vector>
#include <algorithm>

struct Query
{
  int k, i, j, v, index;

  Query(int i, int v): i(i), v(v) {}
  Query(int k, int i, int j, int index): k(k), i(i), j(j), index(index) {}

  bool operator<(const Query& other) {
    return k<other.k;
  }
};

struct SegTree
{
  const std::vector<int> &v;
  std::vector<long long> tree;

  SegTree(const std::vector<int>& v): v(v) {
    tree.resize(v.size()*4);
    build(1, 0, v.size()-1);
  }
  void build(int node, int s, int e) {
    if (s==e) {
      tree[node]=static_cast<long long>(v[s]);
      return;
    }
    int mid=(s+e)/2;
    build(node*2, s, mid);
    build(node*2+1, mid+1, e);
    tree[node] = tree[node*2]+tree[node*2+1];
  }

public:
  long long sum(const int &l, const int &r, int node, int s, int e) {
    if (r<s || l>e) return 0;
    if (l<=s && e<=r) return tree[node];

    int mid=(s+e)/2;
    return sum(l, r, node*2, s, mid)
          +sum(l, r, node*2+1, mid+1, e);
  }

  void update(const int& idx, const int& value, int node, int s, int e) {
    if (idx<s || idx>e) return;
    if (s==e) {
      tree[node]=value;
      return;
    }
    int mid=(s+e)/2;
    if (idx<=mid) update(idx, value, node*2, s, mid);
    else update(idx, value, node*2+1, mid+1, e);
    tree[node]=tree[node*2]+tree[node*2+1];
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];

  int m;  std::cin >> m;
  std::vector<Query> q1, q2;
  int q2_idx=0;
  while (m--) {
    int type;std::cin >> type;
    if (type==1) {
      int i, v;  std::cin >> i >> v;
      q1.push_back(Query(i-1,v));
    }
    else {
      int k, i, j; std::cin >> k >> i >> j;
      q2.push_back(Query(k, i-1, j-1, q2_idx++));
    }
  }
  std::sort(q2.begin(), q2.end());

  SegTree st(v);
  int idx=0;
  std::vector<long long> results(q2_idx);
  for (const Query& q: q2) {
    while (q.k>idx) {
      st.update(q1[idx].i, q1[idx].v, 1, 0, n-1);
      ++idx;
    }
    results[q.index]=st.sum(q.i, q.j, 1, 0, n-1);    
  }

  for (const long long &x: results) std::cout << x << '\n';

  return 0; 
}
