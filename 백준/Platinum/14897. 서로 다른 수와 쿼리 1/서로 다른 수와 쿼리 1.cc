// 14897

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

class SegTree
{
  const std::vector<int> &next;
  std::vector<std::vector<int>> tree;

  void build(int node, int s, int e) {
    if (s==e) {
      tree[node]={next[s]}; return;
    }
    int mid=(s+e)>>1;
    build(node*2, s, mid);
    build(node*2+1, mid+1, e);
    
    std::merge(tree[node*2].begin(), tree[node*2].end(), tree[node*2+1].begin(), tree[node*2+1].end(), std::back_inserter(tree[node]));
  }

  int upper(const int& l, const int& r, int node, int s, int e) {
    if (r<s || e<l) return 0;
    if (l<=s && e<=r) {

      return tree[node].end() - std::upper_bound(tree[node].begin(), tree[node].end(), r);
    }

    int mid=(s+e)>>1;
    return upper(l, r, node*2, s, mid)+upper(l, r, node*2+1, mid+1, e);
  }

public:
  SegTree(const std::vector<int> &next): next(next) {
    tree.resize(next.size()*4);
    build(1, 0, next.size()-1);
  }

  int query(const int& l, const int& r) {
    return upper(l, r, 1, 0, next.size()-1);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  std::unordered_map<int, int> map; /* 
             map[i] = last appearence index of v[i] */
  std::vector<int> next(n, (~0u)>>1); /* 
            next[i] = next appearence index of v[i] */
  
  for (int i=0;i<n;++i) {
    std::cin >> v[i];
    if (map.find(v[i])!=map.end()) {
      next[map[v[i]]] = i;
    }
    map[v[i]] = i;
  }

  SegTree st(next);

  int q;  std::cin >> q;
  while (q--) {
    int l, r;  std::cin >> l >> r;
    --l, --r;
    std::cout << st.query(l, r) << '\n';
  }

  return 0; 
}
