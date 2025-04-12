// 11766
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

static constexpr int dr[4]={-1, 0, 1, 0};
static constexpr int dc[4]={0, 1, 0, -1};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;

  std::queue<std::pair<int, int>> q;
  std::vector<std::vector<bool>> visited(n+2, std::vector<bool>(m+2, 0));
  
  std::vector<std::string> tree(n+2);
  std::vector<std::vector<int>> ring(n+2, std::vector<int>(m+2, 0));
  for (int i=0;i<m+2;++i) {
    ring[0][i]=ring[n+1][i]=0;
    q.push({0, i});
    q.push({n+1, i});
    visited[0][i]=visited[n+1][i]=1;
    
    tree[0].push_back('.');
    tree[n+1].push_back('.');
  }
  for (int i=1;i<=n;++i) {
    std::cin >> tree[i];
    tree[i]='.'+tree[i]+'.';
    for (int j=0;j<m+2;++j) if (tree[i][j]=='.') {
      ring[i][j]=0;
      q.push({i, j});
      visited[i][j]=1;
    }
  }

  int max=0;
  
  while (!q.empty()) {
    std::pair<int, int> curr=q.front();
    q.pop();

    for (int i=0;i<4;++i) {
      int nr=curr.first+dr[i];
      int nc=curr.second+dc[i];

      if (nr<0 || nr>n+1 || nc<0 || nc>m+1 || visited[nr][nc]) 
        continue;

      if (tree[nr][nc]=='T') {
        ring[nr][nc]=1+ring[curr.first][curr.second];
        max=std::max(max, ring[nr][nc]);
        visited[nr][nc]=1;
        q.push({nr, nc});
      }
    }
  }
  for (int r=1;r<=n;++r) {
    for (int c=1;c<=m;++c) {
      if (ring[r][c]==0) std::cout << (max<10?"..":"...");
      else if (ring[r][c]<10) std::cout << (max<10?".":"..") << ring[r][c];
      else std::cout << (max<10?"":".") << ring[r][c];
    }
    std::cout << '\n';
  }

  
  
  return 0;
}