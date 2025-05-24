// 16564

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

int dr[4]={0, 1, 0, -1};
int dc[4]={1, 0, -1, 0};

int BFS(int ur, int uc, int vr, int vc, const std::vector<std::string>& map)
{
  std::vector<std::vector<int>> dist(map.size(), std::vector<int>(map[0].size(), -1));
  dist[ur][uc]=0;
  std::queue<std::pair<int, int>> q;
  q.push({ur, uc});
  while (!q.empty()) {
    int r=q.front().first;
    int c=q.front().second;
    q.pop();
    for (int i=0;i<4;++i) {
      int next_r=r+dr[i];
      int next_c=c+dc[i];
      if (next_r<0 || next_r>=map.size() || next_c<0 || next_c>=map[0].size() || map[next_r][next_c]=='#' || dist[next_r][next_c]!=-1) continue;
      q.push({next_r, next_c});
      dist[next_r][next_c]=dist[r][c]+1;
      if (next_r==vr && next_c==vc) return dist[vr][vc];
    }
  }
  assert(dist[vr][vc]!=-1);
  return dist[vr][vc];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int r, c, d;  std::cin >> r >> c >> d;
    std::vector<std::string> map(r);

    if (d==0) {
      int s_r, s_c, e_r, e_c;
      for (int i=0;i<r;++i) {
        std::cin >> map[i];
        for (int j=0;j<c;++j) {
          if (map[i][j]=='S') s_r=i, s_c=j;
          else if (map[i][j]=='E') e_r=i, e_c=j;
        }
      }
      std::cout << BFS(s_r, s_c, e_r, e_c, map) << '\n';
    }
    else {
      std::vector<std::pair<int, int>> checkpoint(d);
  
      int s_r, s_c, e_r, e_c;
      for (int i=0;i<r;++i) {
        std::cin >> map[i];
        for (int j=0;j<c;++j) {
          int tmp=map[i][j]-'1';
          if (tmp>=0 && tmp<d) checkpoint[tmp]={i, j};
          else if (map[i][j]=='S') s_r=i, s_c=j;
          else if (map[i][j]=='E') e_r=i, e_c=j;
        }
      }
  
      int cnt=0;
      cnt+=BFS(s_r, s_c, checkpoint[0].first, checkpoint[0].second, map)+BFS(checkpoint.back().first, checkpoint.back().second, e_r, e_c, map);
      
      for (int i=1;i<d;++i) {
        cnt+=BFS(checkpoint[i-1].first, checkpoint[i-1].second, checkpoint[i].first, checkpoint[i].second, map);
      }
      
      std::cout << cnt << '\n';
    }
  }
  return 0;
}