// 9328

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>
#include <unordered_set>
#include <bitset>

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

  int t;  std::cin >> t;
  while (t--) {
    int n, m;  std::cin >> n >> m;
    std::vector<std::string> map(n+2, ".");
    for (int i=1;i<=n;++i) {
      std::string line;  std::cin >> line;
      map[i]+=line;
      map[i].push_back('.');
    }
    for (int j=1;j<=m+1;++j) {
      map[0].push_back('.');
      map[n+1].push_back('.');
    }
    std::string line;  std::cin >> line;
    std::bitset<26> keys(0);
    if (line!="0") for (const char &c:line) keys[c-'a']=1;


    int cnt=0;

    while (1) {
      // open
      for (int i=0;i<n+2;++i) for (int j=0;j<m+2;++j) {
        if (map[i][j]>='A' && map[i][j]<='Z' && keys[map[i][j]-'A']) map[i][j]='.';
      }

      
      // BFS
      auto prev=map;
      std::queue<int> q;
      std::vector<bool> visited((n+2)*(m+2), 0);
      q.push(0);
      visited[0]=1;
      while (!q.empty()) {
        int cr=q.front()/(m+2);
        int cc=q.front()%(m+2);

        if (map[cr][cc]=='$') {
          ++cnt;
          map[cr][cc]='.';
        }
        else if (map[cr][cc]>='a' && map[cr][cc]<='z') {
          keys[map[cr][cc]-'a']=1;
          map[cr][cc]='.';
        }
        
        q.pop();
        for (int d=0;d<4;++d) {
          int nr=cr+dr[d];
          int nc=cc+dc[d];
          int tmp=nr*(m+2)+nc;
          if (nr<0 || nr>=n+2 || nc<0 || nc>=m+2 || map[nr][nc]=='*' || visited[tmp]) continue;
          if (map[nr][nc]>='A' && map[nr][nc]<='Z') {
            if (!keys[map[nr][nc]-'A']) continue;
            else map[nr][nc]='.';
          }

          visited[tmp]=1;
          q.push(tmp);
        }
      }
      if (prev==map) break;
    }
    std::cout << cnt << '\n';
  }
  return 0;
}