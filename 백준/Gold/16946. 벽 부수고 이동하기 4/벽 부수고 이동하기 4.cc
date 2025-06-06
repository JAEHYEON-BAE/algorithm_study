// 14442

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>
#include <unordered_set>

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

int dr[4]={0, 1, 0, -1};
int dc[4]={1, 0, -1, 0};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::vector<bool>> map(n, std::vector<bool>(m));
  std::vector<std::vector<int>> partition(n, std::vector<int>(m, 0));

  std::unordered_set<int> us;
  for (int i=0;i<n;++i) {
    std::string line;  std::cin >> line;
    for (int j=0;j<m;++j) {
      map[i][j]=(line[j]=='1');
      if (!map[i][j]) us.insert(i*m+j);
    }
  }

  std::vector<bool> visited(n*m, 0);
  int part=1;
  std::vector<int> cnt={0};
  
  for (const int &b:us) {
    if (visited[b]) continue;
    std::queue<int> q;
    q.push(b);
    visited[b]=1;
    partition[b/m][b%m]=part;
    cnt.push_back(1);
    while (!q.empty()) {
      int cr=q.front()/m;
      int cc=q.front()%m;
      q.pop();
      for (int d=0;d<4;++d) {
        int nr=cr+dr[d];
        int nc=cc+dc[d];
        int tmp=nr*m+nc;
        if (nr<0 || nr>=n || nc<0 || nc>=m || map[nr][nc] || visited[tmp]) continue;
        partition[nr][nc]=part;
        ++cnt.back();
        visited[tmp]=1;
        q.push(tmp);
      }
    }
    ++part;
  }

  for (int r=0;r<n;++r) {
    for (int c=0;c<m;++c) {
      if (partition[r][c]) std::cout << 0;
      else {
        int tmp=1;
        std::vector<bool> used(part, 0);
        for (int d=0;d<4;++d) {
          int nr=r+dr[d];
          int nc=c+dc[d];
          if (nr<0 || nr>=n || nc<0 || nc>=m || !partition[nr][nc]) continue;
          int p=partition[nr][nc];
          if (p==0 || used[p]) continue;
          used[p]=1;
          tmp+=cnt[p];
        }
        std::cout << tmp%10;
      }
    }
    std::cout << '\n';
  }
  
  
  return 0;
}