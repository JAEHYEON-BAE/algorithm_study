// 23331

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;
using Matrix=std::vector<std::vector<int>>;
constexpr int INF=(~0u)>>1;

bool check(int x, const std::vector<int> &cuts, const Matrix &v, const int &a)
{
  int n=v.size();
  int m=v[0].size();
  int seg=cuts.size()+1;
  std::vector<int> block(seg, 0);
  int cnt=0;
  for (int i=0;i<n;++i) {
    std::vector<int> add(seg, 0);
    int j=0;
    int id=0;
    for (const int &cut:cuts) {
      for (;j<=cut;++j) add[id]+=v[i][j];
      ++id;
    }
    assert(id==seg-1);
    for (;j<m;++j) add[id]+=v[i][j];

    bool OVER=0;
    for (id=0;id<seg;++id) {
      if (add[id]>x) return 0;
      block[id]+=add[id];
      if (block[id]>x) OVER=1;
    }

    if (OVER) {
      if (cnt>=a) return 0;
      ++cnt;
      block=add;
    }
  }
  return 1;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m, a, b;  std::cin >> n >> m >> a >> b;
  Matrix v(n, std::vector<int>(m));
  for (auto &r:v) for (int &x:r) std::cin >> x;

  int ans=INF;
  std::vector<bool> comb(m-1, 0);
  std::fill(comb.begin(), comb.begin()+b, 1);
  do {
    std::vector<int> cuts;
    for (int i=0;i<m-1;++i) if (comb[i]) cuts.push_back(i);

    int l=0, r=INF, res=r;
    while (l<=r) {
      int mid=(l+r)>>1;
      if (check(mid, cuts, v, a)) {
        res=mid;
        r=mid-1;
      }
      else l=mid+1;
    }
    ans=std::min(ans, res);
    
  } while (std::prev_permutation(comb.begin(), comb.end()));

  std::cout << ans;
  
  return 0;
}