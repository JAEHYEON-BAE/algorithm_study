// 33199

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using Matrix=std::vector<std::vector<int>>;
class Matching
{
  int n, m, t;
  const Matrix &dist;
  std::vector<int> match;
  std::vector<bool> done;

  bool bp_m(int guest) {
    int tmp=dist[n][guest];
    for (int driver=0;driver<m;++driver) {
      if (tmp+dist[guest][driver]>t || done[driver]) continue;
      done[driver]=1;
      if (match[driver]==-1 || bp_m(match[driver])) {
        match[driver]=guest;
        return 1;
      }
    }
    return 0;
  }
public:
  Matching(int t, int n, int m, const Matrix &dist): n(n), m(m), t(t), dist(dist) {
    match.assign(m, -1);
    done.assign(m, 0);
  }

  bool valid() {
    bool POSSIBLE=1;
    for (int guest=m;guest<n;++guest) {
      done.assign(m, 0);
      if (!bp_m(guest)) {POSSIBLE=0; break;}
    }
    if (!POSSIBLE) return 0;
    for (int driver=0;driver<m;++driver) if (match[driver]==-1) {
      if (dist[n][driver]>t) {POSSIBLE=0; break;}
    }
    return POSSIBLE;
  }

  std::vector<int> result() const {
    return match;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;

  Matrix dist(n+1, std::vector<int>(n+1));
  for (auto &r:dist) for (int &x:r) std::cin >> x;

  int l=0, r=200'000'000;
  int ans=0;
  std::vector<int> match;
  while (l<=r) {
    int mid=(l+r)>>1;
    Matching x(mid, n, m, dist);
    if (x.valid()) {
      match=x.result();
      ans=mid;
      r=mid-1;
    }
    else l=mid+1;
  }
  std::cout << ans << '\n';
  for (int &x:match) std::cout << x+1 << '\n';
  
  return 0;
}