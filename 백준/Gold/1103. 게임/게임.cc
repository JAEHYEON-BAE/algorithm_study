// 1103

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;

std::vector<std::vector<int>> dp;
std::vector<std::vector<int>> map;
std::vector<std::vector<bool>> visited;

static int FLAG=false;

int move(int r, int c, const int &n, const int &m) 
{
  if (visited[r][c]) {FLAG=true; return -1;}
  if (FLAG) return -1;
  if (dp[r][c]!=-1) return dp[r][c];

  int tmp=0;
  visited[r][c]=true;
  int v=map[r][c];
  if (r+v<n && map[r+v][c]!=24)  
    tmp=std::max(tmp, 1+move(r+v, c, n, m));
  if (r-v>=0 && map[r-v][c]!=24) 
    tmp=std::max(tmp, 1+move(r-v, c, n, m));
  if (c+v<m && map[r][c+v]!=24)
    tmp=std::max(tmp, 1+move(r, c+v, n, m));
  if (c-v>=0 && map[r][c-v]!=24)
    tmp=std::max(tmp, 1+move(r, c-v, n, m));
  visited[r][c]=false;
  if (FLAG) return -1;
  return dp[r][c]=tmp;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  dp.assign(n, std::vector<int>(m, -1));
  map.assign(n, std::vector<int>(m));
  visited.assign(n, std::vector<bool>(m, false));

  for (int i=0;i<n;++i) {
    std::string line;  std::cin >>line;
    for (int j=0;j<m;++j) map[i][j]=line[j]-'0';
  }

  int x=move(0, 0, n, m);
  if (x==-1) std::cout << -1;
  else std::cout << x+1;
  
  return 0; 
}