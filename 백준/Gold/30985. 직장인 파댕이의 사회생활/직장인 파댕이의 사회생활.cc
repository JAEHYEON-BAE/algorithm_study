// 30985

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};
static constexpr long long int LLINF=(~0ul)>>2;


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m, k;  std::cin >> n >> m >> k;
  std::unordered_map<int, std::unordered_map<int, long long int>> map;
  for (int i=0;i<m;++i) {
    int u, v;
    long long int c;
    std::cin >> u >> v >> c;
    --u;--v;
    map[u][v]=c;
    map[v][u]=c;
  }

  std::vector<long long int> elev(n);
  std::vector<int> up;
  for (int i=0;i<n;++i) {
    std::cin >> elev[i];
    if (elev[i]!=-1) up.push_back(i);
  }

  if (up.empty()) {
    std::cout << -1;
    return 0;
  }

  std::vector<long long int> u_dist(n, LLINF), v_dist(n, LLINF);
  std::priority_queue<std::pair<long long int, int>, std::vector<std::pair<long long int, int>>, std::greater<std::pair<long long int, int>>> pq;
  
  u_dist[0]=0;
  pq.push({0, 0});
  while (!pq.empty()) {
    int curr=pq.top().second;
    long long int dist=pq.top().first;
    pq.pop();

    if (dist>u_dist[curr]) continue;

    if (map.find(curr)==map.end()) continue;
    for (const auto &[next, n_dist] : map.at(curr)) {
      if (u_dist[next]>u_dist[curr]+n_dist) {
        u_dist[next]=u_dist[curr]+n_dist;
        pq.push({u_dist[next], next});
      }
    }
  }

  while (!pq.empty()) pq.pop();

  v_dist[n-1]=0;
  pq.push({0, n-1});
  while (!pq.empty()) {
    int curr=pq.top().second;
    long long int dist=pq.top().first;
    pq.pop();

    if (dist>v_dist[curr]) continue;

    if (map.find(curr)==map.end()) continue;
    for (const auto &[next, n_dist] : map.at(curr)) {
      if (v_dist[next]>v_dist[curr]+n_dist) {
        v_dist[next]=v_dist[curr]+n_dist;
        pq.push({v_dist[next], next});
      }
    }
  }

  long long int min=LLINF;
  for (const int &x:up) {
    long long int t1=u_dist[x];
    long long int t2=v_dist[x];
    // std::cout << x << ' ' << t1 << ' ' << t2 << '\n';
    if (t1<LLINF && t2<LLINF) {
      min=std::min(min, t1+t2+static_cast<long long int>(k-1)*elev[x]);
    }
  }

  if (min<LLINF) std::cout << min;
  else std::cout << -1;
  return 0;
}