// 2618

#include <iostream>
#include <vector>
#include <algorithm>

class _2618
{
  const int &w;
  const std::vector<std::pair<int, int>> &events;
  std::vector<std::vector<int>> dp;
  std::vector<std::vector<int>> trace;

  inline int dist(int x, int y) {
    return std::abs(events[x].first-events[y].first)+std::abs(events[x].second-events[y].second);
  }

  int DP(int x, int y) {
    if (dp[x][y]!=-1) return dp[x][y];

    int next=1+std::max(x, y);
    if (next>=w+2) return 0;

    int d1=DP(next, y)+dist(x, next);
    int d2=DP(x, next)+dist(y, next);

    if (d1<d2) {
      trace[x][y]=1;
      return dp[x][y]=d1;
    }
    else {
      trace[x][y]=2;
      return dp[x][y]=d2;
    }
  }

public:
  _2618(const int &w, const std::vector<std::pair<int, int>> &events): w(w), events(events) {
    dp.assign(w+2, std::vector<int>(w+2, -1));
    trace.assign(w+2, std::vector<int>(w+2, 0));
  }

  void solve() {
    std::cout << DP(0, 1) << '\n';

    int x=0, y=1;
    for (int i=2;i<w+2;++i) {
      std::cout << trace[x][y] << '\n';
      if (trace[x][y]==1) x=i;
      else y=i;
    }
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, w;  std::cin >> n >> w;

  std::vector<std::pair<int, int>> events(w+2);
  events[0]={1, 1};
  events[1]={n, n};
  
  for (int i=2;i<w+2;++i) std::cin >> events[i].first >> events[i].second;

  _2618 x(w, events);
  x.solve();
  
  return 0;
}