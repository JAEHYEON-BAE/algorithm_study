// 12851
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;

  int dist[100'001], cnt[100'001];
  memset(dist, -1, sizeof(dist));
  memset(cnt, 0, sizeof(cnt));
  
  // BFS
  std::queue<int> q;
  q.push(n);
  dist[n]=0;
  cnt[n]=1;
  while (!q.empty()) {
    int curr=q.front();
    q.pop();
    for (int next:{curr-1, curr+1, curr<<1}) {
      if (next<0 || next>100'000) continue;
      if (dist[next]==-1) {
        dist[next]=dist[curr]+1;
        cnt[next]=cnt[curr];
        q.push(next);
      } else if (dist[next]==dist[curr]+1) {
        cnt[next]+=cnt[curr];
      }
    }
  }
  std::cout << dist[k] << '\n' << cnt[k]; 
  
  return 0; 
}
