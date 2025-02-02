// 28707

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int power10[8];
int n;
const int INF=(~0u)>>1;

bool valid(int x)
{
  int tmp=x%10;
  while (x>0) {
    x/=10;
    if (x%10>tmp) return false;
    tmp=x%10;
  }
  return true;
}

struct Query
{
  int l, r, c;
  int work(int x) const {
    int tmp_l=x/power10[n-l]%10;
    int tmp_r=x/power10[n-r]%10;
    x+=power10[n-l]*(tmp_r-tmp_l);
    x+=power10[n-r]*(tmp_l-tmp_r);
    return x;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  power10[0]=1;
  for (int i=1;i<8;++i) power10[i]=power10[i-1]*10;
  
  std::cin >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) {
    std::cin >> v[i];
    --v[i];
  }
  int start=0, end;
  for (int i=0;i<n;++i) start+=power10[n-i-1]*v[i];

  int m;  std::cin >> m;
  std::vector<Query> queries(m);
  for (int i=0;i<m;++i) {
    std::cin >> queries[i].l >> queries[i].r >> queries[i].c;
  }

  std::sort(v.begin(), v.end());
  std::unordered_map<int, int> map;
  int i=0;
  do {
    int num=0;
    for (int i=0;i<n;++i) num+=power10[n-i-1]*v[i];
    if (map.find(num)==map.end()) {
      map[num]=i++;
      if (valid(num)) end=num;
    }
  } while(std::next_permutation(v.begin(), v.end()));

  std::vector<std::unordered_map<int, int>> graph(map.size());
  do {
    int num=0;
    for (int i=0;i<n;++i) num+=power10[n-i-1]*v[i];
    for (const Query& query: queries) {
      int u=map[num], v=map[query.work(num)];
      if (graph[u].find(v)==graph[u].end()) graph[u][v]=query.c;
      else graph[u][v]=std::min(graph[u][v], query.c);
    }
  } while(std::next_permutation(v.begin(), v.end()));

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
  int s=map[start];
  int e=map[end];
  std::vector<int> dist(map.size(), INF);
  std::vector<bool> done(map.size(), false);
  
  pq.push({0, s});
  dist[s]=0;
  while (!pq.empty()) {
    int curr_node=pq.top().second;
    int curr_dist=pq.top().first;
    pq.pop();
    if (done[curr_node]) continue;
    done[curr_node]=true;
    if (dist[curr_node]<curr_dist) continue;

    for (const auto&next:graph[curr_node]) {
      int next_node=next.first;
      int weight=next.second;
      if (done[next_node]) continue;
      if (dist[next_node]>dist[curr_node]+weight) {
        dist[next_node]=dist[curr_node]+weight;
        pq.push({dist[next_node], next_node});
      }
    }
  }
  if (dist[e]==INF) std::cout << -1;
  else std::cout << dist[e];
  
  return 0; 
}
