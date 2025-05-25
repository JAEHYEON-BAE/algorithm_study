// 2638

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

void print_v(const std::vector<std::vector<bool>> &v)
{
  for (auto x:v) {
    for (auto y:x) std::cout << y << ' ';
    std::cout << '\n';
  }
  std::cout << '\n';
  return;
}

int dr[4]={-1, 0, 1, 0};
int dc[4]={0, 1, 0, -1};

void BFS(std::vector<std::vector<bool>> &v)
{
  int n=v.size(), m=v[0].size();
  std::vector<bool> visited(n*m, 0);
  std::queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int cr=q.front()/m;
    int cc=q.front()%m;
    q.pop();

    for (int d=0;d<4;++d) {
      int nr=cr+dr[d];
      int nc=cc+dc[d];
      if (nr<0 || nr>=n || nc<0 || nc>=m) continue;
      if (visited[nr*m+nc]) {
        if (v[nr][nc]) v[nr][nc]=0;
        continue;
      }
      visited[nr*m+nc]=1;
      if (!v[nr][nc]) {
        q.push(nr*m+nc);
      }
    }
  }
}


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::vector<bool>> zeros(n, std::vector<bool>(m, 0));
  std::vector<std::vector<bool>> v(n, std::vector<bool>(m, 0));
  for (int i=0;i<n;++i) for (int j=0;j<m;++j) {
    int x;  std::cin >> x;
    v[i][j]=x;
  }

  int cnt=0;
  while (v!=zeros) {
    ++cnt;
    BFS(v);
  }
  std::cout << cnt;
  return 0;
}