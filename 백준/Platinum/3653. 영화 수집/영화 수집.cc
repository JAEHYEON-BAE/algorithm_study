// 3653

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

class FenwickTree
{
  int size;
  std::vector<int> tree;

public:
  FenwickTree(int size): size(size) {
    tree.assign(size, 0);
  }

  void update(int i, int d) {
    while (i<size) {
      tree[i]+=d;
      i+=(i&-i);
    }
  }
  int query(int i) {
    int sum=0;
    while (i>0) {
      sum+=tree[i];
      i-=(i&-i);
    }
    return sum;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int tc;  std::cin >> tc;
  while (tc--) {
    int n, m;  std::cin >> n >> m;
    std::vector<int> pos(n+m+1);
    FenwickTree ft(n+m+1);
    for (int i=1;i<=n;++i) {
      pos[i]=m+i;
      ft.update(pos[i], 1);
    }
    int top=m;
    for (int i=0;i<m;++i) {
      int x;  std::cin >> x;
      std::cout << ft.query(pos[x]-1) << ' ';

      ft.update(pos[x], -1);
      pos[x]=top--;
      ft.update(pos[x], 1);
    }
    std::cout << '\n';
  }
  return 0;
}