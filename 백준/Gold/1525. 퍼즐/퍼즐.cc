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
static constexpr long long int lpower10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};
static constexpr int ipower10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int t2i(const std::vector<int> &table)
{
  int tmp=0;
  for (int i=0;i<9;++i) tmp+=table[i]*ipower10[8-i];
  return tmp;
}

int mv(const int &x, int dir)
{
  int tmp=x;
  int idx=-1;
  for (int i=0;i<9;++i) {
    if (x/ipower10[8-i]%10==0) {
      idx=i;
      break;
    }
  }
  
  assert(idx!=-1);
  if (dir==0) {
    if (idx<3) return -1;
    int k=x/ipower10[11-idx]%10;
    tmp-=k*ipower10[11-idx];
    tmp+=k*ipower10[8-idx];
    return tmp;
  }
  else if (dir==1) {
    if (idx%3==2) return -1;
    int k=x/ipower10[7-idx]%10;
    tmp-=k*ipower10[7-idx];
    tmp+=k*ipower10[8-idx];
    return tmp;
  }
  else if (dir==2) {
    if (idx>5) return -1;
    int k=x/ipower10[5-idx]%10;
    tmp-=k*ipower10[5-idx];
    tmp+=k*ipower10[8-idx];
    return tmp;
  }
  else {
    if (idx%3==0) return -1;
    int k=x/ipower10[9-idx]%10;
    tmp-=k*ipower10[9-idx];
    tmp+=k*ipower10[8-idx];
    return tmp;
  }
}

void mapping(std::vector<int> &map)
{
  std::vector<int> init={0, 1, 2, 3, 4, 5, 6, 7, 8};
  int i=0;
  do {
    map[i++]=t2i(init);
  } while (std::next_permutation(init.begin(), init.end()));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::vector<int> d={1, 2, 3, 4, 5, 6, 7, 8, 0};

  std::vector<int> map(362880, 0);
  mapping(map);
  std::unordered_map<int, int> rmap;
  for (int i=0;i<362880;++i) rmap[map[i]]=i;
  int dest=rmap[t2i(d)];

  std::vector<int> v(9);
  for (int i=0;i<9;++i) std::cin >> v[i];

  int init=rmap[t2i(v)];

  
  std::queue<int> q;
  std::vector<bool> visited(362880, 0);
  std::vector<int> dist(362880, -1);
  q.push(init);
  visited[init]=1;
  dist[init]=0;

  while (!q.empty()) {
    int curr=q.front();
    q.pop();

    if (curr==dest) break;

    for (int dir=0;dir<4;++dir) {
      int next=mv(map[curr], dir);
      
      if (next!=-1 && !visited[rmap[next]]) {
        q.push(rmap[next]);
        dist[rmap[next]]=1+dist[curr];
        visited[rmap[next]]=1;
      }
    }
  }

  std::cout << dist[dest];
  return 0;
}