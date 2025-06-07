// 17141

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

template <typename T>
inline void print_v(const std::vector<std::vector<T>> &v)
{
  for (auto x:v) {
    for (auto y:x) std::cout << y << ' ';
    std::cout << '\n';
  }
  std::cout << std::endl;
  return;
}
template <typename T, size_t N>
inline void print_v(const T (&v)[N][N])
{
  for (int i=0;i<N;++i) {
    for (int j=0;j<N;++j) std::cout << v[i][j] << ' ';
    std::cout << '\n';
  }
  std::cout << std::endl;
}

int dr[4]={-1, 0, 1, 0};
int dc[4]={0, 1, 0, -1};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<int> map(n*n);
  std::vector<int> cand;
  for (int i=0;i<n*n;++i) {
    std::cin >> map[i];
    if (map[i]==2) cand.push_back(i);
  }
  int size=cand.size();
  std::vector<bool> comb(size, 0);
  std::fill(comb.begin(), comb.begin()+m, 1);

  int min=INF;
  do {
    std::vector<int> dist(n*n, -1);
    for (int i=0;i<n*n;++i) {
      if (map[i]!=1) dist[i]=INF; 
    }
    std::queue<int> q;
    std::vector<bool> visited(n*n, 0);
    for (int i=0;i<size;++i) if (comb[i]) {
      q.push({cand[i]});
      dist[cand[i]]=0;
      visited[cand[i]]=1;
    }

    int max=0;
    
    while (!q.empty()) {
      int curr=q.front();
      q.pop();

      for (int d=0;d<4;++d) {
        int nr=curr/n+dr[d];
        int nc=curr%n+dc[d];
        int next=nr*n+nc;
        if (nr<0 || nr>=n || nc<0 || nc>=n || visited[next]) continue;
        if (dist[next]==-1) continue;
        visited[next]=1;
        dist[next]=dist[curr]+1;
        q.push({next});
        max=std::max(max, dist[next]);
      }
    }

    bool FLAG=0;
    for (const int& x:dist) {
      if (x==INF) {FLAG=1; break;}
    }
    if (FLAG) continue;
    min=std::min(min, max);
  } while (std::prev_permutation(comb.begin(), comb.end()));

  std::cout << (min!=INF?min:-1);
  
  return 0;
}