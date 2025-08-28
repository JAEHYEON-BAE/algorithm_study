// 27455

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <bitset>

using ll=long long int;
constexpr ll MAX=(~0uLL)>>2;

struct Edge
{
  int e; ll d;
  Edge(){}
  Edge(int e, int d): e(e), d(d) {}
};

struct Node
{
  int id; ll d;
  Node() {}
  Node(int id, ll d): id(id), d(d) {}

  bool operator<(const Node &o) const {
    return d>o.d;
  }
};

ll DP(int i, int bitfield, const int &n, std::vector<std::vector<ll>> &dp, const std::vector<std::vector<std::vector<ll>>> &dist)
{
  // std::cout << "CALL DP:\t" << i << ' ' << std::bitset<2>(bitfield) << std::endl;
  ll &res=dp[i][bitfield];

  if (res<MAX) return res;
  
  int star=n-__builtin_popcount(bitfield);

  for (int next=1;next<=n;++next) if (bitfield & (1<<(next-1))) {
    if (dist[star][i][next]==MAX) continue;
    
    ll tmp=DP(next, bitfield^(1<<(next-1)), n, dp, dist);
    if (tmp<MAX) res=std::min(res, tmp+dist[star][i][next]);
  }
  return res;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, v, e;  std::cin >> n >> v >> e;
  std::vector<int> l(v), k(n+1, 0);
  // std::vector<bool> is_card(v, 0);
  std::vector<Edge> edges(e);
  std::vector<std::vector<Edge>> graph(v);
  for (int &i:l) std::cin >> i;
  for (int i=0;i<n;++i) {
    std::cin >> k[i+1]; --k[i+1];
    // is_card[k[i+1]]=1;
  }
  for (int i=0;i<e;++i) {
    int s, e; ll d;  std::cin >> s >> e >> d;
    --s;--e;
    graph[s].push_back(Edge(e, d));
  }

  // dist[s][i][j] := 현재 star가 s개 있을 때, 정점 k[i]와 정점 k[j] 사이의 거리
  std::vector<std::vector<std::vector<ll>>> dist(n+1, std::vector<std::vector<ll>>(n+1, std::vector<ll>(n+1, MAX)));

  std::vector<ll> d(v, MAX);
  for (int s=0;s<=n;++s) {
    for (int i=0;i<=n;++i) {
      if (l[k[i]]>s) continue;
      // dijkstra

      d.assign(v, MAX);
      std::priority_queue<Node> pq;

      d[k[i]]=0;
      pq.push(Node(k[i], 0));

      while (!pq.empty()) {
        int curr_i=pq.top().id;
        ll curr_d=pq.top().d;
        pq.pop();

        if (d[curr_i]!=curr_d) continue;
        if (l[curr_i]>s) continue;
        // if (curr_i!=k[i] && is_card[curr_i]) continue;

        for (const Edge &edge:graph[curr_i]) {
          int next_i=edge.e;
          ll next_d=curr_d+edge.d;
          if (l[next_i]>s) continue;
          if (next_d<d[next_i]) {
            d[next_i]=next_d;
            pq.push(Node(next_i, next_d));
          }
        }
      }

      for (int j=0;j<=n;++j) {
        if (s) dist[s][i][j]=std::min(dist[s-1][i][j], d[k[j]]);
        else dist[s][i][j]=d[k[j]];
      }
    }
  }

  // dp[i][j] := 현재 위치가 i번째 star이고, 현재 스타 상태가 j(비트필드)일 때, 나머지를 모두 획득하는데에 필요한 이동거리
  std::vector<std::vector<ll>> dp(n+1, std::vector<ll>(1<<14, MAX));

  for (int i=0;i<=n;++i) dp[i][0]=0;
  ll res=DP(0, (1<<n)-1, n, dp, dist);

  if (res==MAX) std::cout << "-1";
  else std::cout << res;
  return 0;
}

