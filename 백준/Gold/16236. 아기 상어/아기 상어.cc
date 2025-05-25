// 2638

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

struct Prey
{
  int r, c, time;
  Prey(int r, int c, int time): r(r), c(c), time(time) {}
  bool operator<(const Prey &other) const {
    if (time==other.time) {
      if (r==other.r) return c<other.c;
      return r<other.r;
    }
    return time<other.time;
  }
};

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

int dr[4]={-1, 0, 0, 1};
int dc[4]={0, -1, 1, 0};

int BFS(int &pos, int &size, int &cnt, std::vector<std::vector<int>> &v)
{
  int n=v.size();
  std::queue<int> q;
  q.push(pos);

  std::vector<bool> visited(n*n, 0);
  visited[pos]=1;

  std::vector<int> time(n*n, -1);
  time[pos]=0;

  v[pos/n][pos%n]=0;

  std::vector<Prey> preys;
  
  while (!q.empty()) {
    int cr=q.front()/n;
    int cc=q.front()%n;
    int ct=time[q.front()];
    q.pop();

    for (int d=0;d<4;++d) {
      int nr=cr+dr[d];
      int nc=cc+dc[d];
      if (nr<0 || nr>=n || nc<0 || nc>=n || visited[nr*n+nc]) continue;

      
      if (v[nr][nc]>size) continue;
   
      time[nr*n+nc]=1+ct;
      visited[nr*n+nc]=1;
      q.push(nr*n+nc);
      if (v[nr][nc]!=0 && v[nr][nc]<size) {
        preys.push_back(Prey(nr, nc, 1+ct));
      }
    }
  }

  if (preys.empty()) return 0;
  std::sort(preys.begin(), preys.end());
  pos=preys[0].r*n+preys[0].c;
  v[preys[0].r][preys[0].c]=9;
  ++cnt;
  if (cnt==size) ++size, cnt=0;
  return preys[0].time;
}


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));
  int pos, size=2, cnt=0;
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    std::cin >> v[i][j];
    if (v[i][j]==9) pos=i*n+j;
  }

  int tot=0;
  
  while (1) {
    int tmp=BFS(pos, size, cnt, v);
    tot+=tmp;
    if (tmp==0) break;
  }

  std::cout << tot;
  return 0;
}