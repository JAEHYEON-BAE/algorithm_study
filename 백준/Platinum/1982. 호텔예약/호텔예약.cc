// 1982

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

constexpr int INF=(~0u)>>2;

struct Room
{
  int cap, cost;
  Room() {}
  Room(int x, int y): cap(x), cost(y) {}
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int m, f, r, c;  std::cin >> m >> f >> r >> c;
  std::vector<Room> rooms(r);
  for (Room &x:rooms) std::cin >> x.cap >> x.cost;

  std::vector<std::vector<std::vector<int>>> dp(m+1, std::vector<std::vector<int>>(f+1, std::vector<int>(c+1, INF)));
  dp[0][0][0]=0;

  auto tmp=dp;
  for (const auto &[cap, cost]:rooms) {
    tmp=dp;
    for (int i=0;i<=m;++i) for (int j=0;j<=f;++j) for (int k=0;k<=c;++k) {
      if (dp[i][j][k]==INF) continue;
      int curr=dp[i][j][k];
      for (int di=1;di<=std::min(cap, m-i);++di) {
        tmp[i+di][j][k]=std::min(tmp[i+di][j][k], curr+cost);
      }
      for (int dj=1;dj<=std::min(cap, f-j);++dj) {
        tmp[i][j+dj][k]=std::min(tmp[i][j+dj][k], curr+cost);
      }
      if (cap>=2 && i<m && j<f && k<c) {
        tmp[i+1][j+1][k+1]=std::min(tmp[i+1][j+1][k+1], curr+cost);
      }
    }
    std::swap(dp, tmp);
  }

  int &res=*std::min_element(dp[m][f].begin(), dp[m][f].end());
  if (res==INF) std::cout << "Impossible";
  else std::cout << res;
  
  return 0;
}