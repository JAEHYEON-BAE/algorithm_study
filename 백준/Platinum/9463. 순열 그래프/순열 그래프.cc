// 9463
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

class SegTree
{
  std::vector<int> tree;

    public:
  SegTree(const int &n) {
    tree.assign(n*4, 0);
  }

  void insert(const int &x, int node, int l, int r) {
    if (x<l || r<x) return;
    ++tree[node];
    if (l==r) return;
    int mid=(l+r)>>1;
    if (x<=mid) insert(x, node<<1, l, mid);
    else insert(x, (node<<1)+1, mid+1, r);
  }

  void query(const int &x, int node, int l, int r, long long int &result) {
    if (x<l) {result+=tree[node]; return;}
    if (x>=r) return;
    if (l==r) {result+=tree[node]; return;}

    int mid=(l+r)>>1;
    query(x, node<<1, l, mid, result);
    query(x, (node<<1)+1, mid+1, r, result);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int n;  std::cin >> n;
    SegTree st(n);
    std::vector<int> indexing(n+1);
    for (int i=0;i<n;++i) {
      int x;  std::cin >> x;
      indexing[x]=i;
    }

    long long int cnt=0;
    for (int i=0;i<n;++i) {
      int x;  std::cin >> x;
      st.query(indexing[x], 1, 0, n-1, cnt);
      st.insert(indexing[x], 1, 0, n-1);
    }
    std::cout << cnt << '\n';
  }
  
  return 0;
}