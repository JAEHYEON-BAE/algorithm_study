// 26993

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <unordered_map>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

constexpr int dr[4]={-1, 0, 1, 0};
constexpr int dc[4]={0, 1, 0, -1};

namespace std
{
  template<>
  struct hash<std::pair<int, int>> 
  {
    size_t operator()(const std::pair<int, int> &p) const {
      return p.first*1001+p.second;
    }
  };
}
int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int w, h;  std::cin >> w >> h;
  std::vector<std::vector<int>> board(h, std::vector<int>(w));

  std::pair<int, int> s, e;
  std::unordered_map<std::pair<int, int>, int> from_s, from_e;
  for (int i=0;i<h;++i) for (int j=0;j<w;++j) {
    std::cin >> board[i][j];
    if (board[i][j]==2) s={i, j};
    else if (board[i][j]==3) e={i, j};
    else if (board[i][j]==4) {
      from_s[std::make_pair(i, j)]=-1;
      from_e[std::make_pair(i, j)]=-1;
    }
  }
  int m=from_s.size();

  // from S
  std::queue<std::pair<int, int>> q;
  std::vector<std::vector<int>> dist(h, std::vector<int>(w, -1));
  q.push(s);
  dist[s.first][s.second]=0;

  int cnt=0;
  while (!q.empty()) {
    std::pair<int, int> curr=q.front();
    q.pop();
    
    auto [cr, cc]=curr;
    int cd=dist[cr][cc];
    
    if (from_s.count(curr)) {
      from_s[curr]=cd;
      if (++cnt==m) break;
    }
    for (int d=0;d<4;++d) {
      int nr=cr+dr[d];
      int nc=cc+dc[d];
      if (nr<0 || nr>=h || nc<0 || nc>=w || board[nr][nc]==1 || board[nr][nc]==3 || dist[nr][nc]!=-1) continue;
      dist[nr][nc]=1+cd;
      q.push({nr, nc});
    }
  }

  // from E
  while (!q.empty()) q.pop();
  for (int r=0;r<h;++r) for (int c=0;c<w;++c) dist[r][c]=-1;

  q.push(e);
  dist[e.first][e.second]=0;

  cnt=0;
  while (!q.empty()) {
    std::pair<int, int> curr=q.front();
    q.pop();

    auto [cr, cc]=curr;
    int cd=dist[cr][cc];

    if (from_e.count(curr)) {
      from_e[curr]=cd;
      if (++cnt==m) break;
    }
    for (int d=0;d<4;++d) {
      int nr=cr+dr[d];
      int nc=cc+dc[d];
      if (nr<0 || nr>=h || nc<0 || nc>=w || board[nr][nc]==1 || board[nr][nc]==3 || dist[nr][nc]!=-1) continue;      
      dist[nr][nc]=1+cd;
      q.push({nr, nc});
    }
  }

  int ans=(~0u)>>1;
  for (const auto &p:from_s) {
    int _s=p.second;
    int _e=from_e[p.first];
    if (_s!=-1 && _e!=-1) ans=std::min(ans, _s+_e);
  }
  std::cout << ans;
  return 0;
}