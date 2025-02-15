// 15573

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;

bool BFS(int x, std::queue<int> q, const std::vector<int> &map, const int &n, const int &m, const int &k)
{
  std::vector<bool> visited(n*m, false);
  int cnt=0;
  while (!q.empty()) {
    int curr=q.front();
    q.pop();
    if (visited[curr]) continue;
    visited[curr]=true;
    if (map[curr]>x) continue;
    ++cnt;

    if (curr%m>0 && !visited[curr-1]) q.push(curr-1);
    if (curr%m<m-1 && !visited[curr+1]) q.push(curr+1);
    if (curr/m<n-1 && !visited[curr+m]) q.push(curr+m);
    if (curr/m>0 && !visited[curr-m]) q.push(curr-m);
  }
  return cnt>=k;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m, k;  std::cin >> n >> m >> k;
  std::queue<int> q;
  std::vector<int> map(n*m);
  for (int i=0;i<n*m;++i) {
    std::cin >> map[i];
    if (i/m==0||i%m==0||i%m==m-1) q.push(i);
  }

  int l=0, r=10'000'000;
  while (l<r) {
    int mid=(l+r)/2;
    if (BFS(mid, q, map, n, m, k)) r=mid;
    else l=mid+1;
  }
  std::cout << l;
  return 0;
}