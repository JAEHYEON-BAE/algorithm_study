// 20301

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

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

  int n, k, m;  std::cin >> n >> k >> m;
  Fenwick fw(n);

  bool FLAG=0;
  int curr=k-1;
  int cnt=0;
  while (n) {
    ++cnt;
    int pos=fw.find(curr+1);
    std::cout << pos << '\n';
    
    fw.kill(pos);
    --n;

    if (cnt%m==0) FLAG^=1;
    if (n) {
      if (FLAG) curr=((curr-k)%n+n)%n;
      else curr=(curr+k-1)%n;
    }
  }

  return 0;
}