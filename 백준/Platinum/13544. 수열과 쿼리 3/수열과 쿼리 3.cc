// 13544

#include <iostream>
#include <vector>
#include <algorithm>

class MergeSortTree
{
  std::vector<std::vector<int>> tree;
  int n;
  std::vector<int> v;

  void build(int node, int s, int e) {
    if (s==e) {tree[node]={v[s]}; return;}
    int mid=(s+e)/2;
    build(node*2, s, mid);
    build(node*2+1, mid+1, e);

    std::vector<int> &l=tree[node*2];
    std::vector<int> &r=tree[node*2+1];

    std::merge(l.begin(), l.end(), r.begin(), r.end(), std::back_inserter(tree[node]));
  }

public:
  MergeSortTree(const std::vector<int> &v, const int &n) {
    this->n=n;
    this->tree.resize(4*n);
    this->v=v;
    build(1, 0, n-1);
  }

  int query(const int &i, const int &j, const int&k, int node, int s, int e) {

    if (j<s || i>e) return 0;
    if (i<=s && e<=j) {
      return tree[node].end() - std::upper_bound(tree[node].begin(), tree[node].end(), k);
    }

    int mid=(s+e)/2;
    return query(i, j, k, node*2, s, mid)+query(i, j, k, node*2+1, mid+1, e);
  }

  void print_tree(int i) {
    std::cout << i << ":\t";
    for (int x: tree[i]) std::cout << x << ' ';
    std::cout << std::endl;
  }
};


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];
  MergeSortTree mst(v, n);

  int m;  std::cin >> m;
  int last_ans=0;
  int a, b, c, i, j, k;
  while (m--) {
    std::cin >> a >> b >> c;
    i=(a^last_ans) -1;
    j=(b^last_ans) -1;
    k=c^last_ans;
    std::cout << (last_ans=mst.query(i, j, k, 1, 0, n-1)) << '\n';
  }

  return 0; 
}
