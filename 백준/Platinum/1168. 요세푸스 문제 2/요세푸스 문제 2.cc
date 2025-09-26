// 1168

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_set>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

class Fenwick
{
  int n;
  std::vector<int> tree;

public:
  Fenwick(int n): n(n), tree(n+1, 0) {
    for (int i=1;i<=n;++i) {
      ++tree[i];
      int j=i+(i&-i);
      if (j<=n) tree[j]+=tree[i];
    }
  }
  void kill(int i) {
    while (i<=n) {
      --tree[i];
      i+=i&-i;
    }
  }
  int find(int k) const {
    int i=0, b=1;
    while ((b<<1)<=n) b<<=1;
    for (;b;b>>=1) {
      int tmp=i+b;
      if (tmp<=n && tree[tmp]<k) {
        i=tmp;
        k-=tree[tmp];
      }
    }
    return i+1;
  }

};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  Fenwick fw(n);

  int curr=k-1;
  std::cout << '<';
  while (n) {
    int pos=fw.find(curr+1);
    std::cout << pos;
    
    fw.kill(pos);
    --n;

    if (n) {
      curr=(curr+k-1)%n;
      std::cout << ", ";
    }
    else std::cout << '>';
  }
  return 0;
}