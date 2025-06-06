// 13460

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

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

int mv(const std::vector<std::string> &map, std::pair<int, int> &R, std::pair<int, int> &B, int d)
{
  bool R_out=0, B_out=0;
  
  bool r_R_first=R.first<B.first;
  bool c_R_first=R.second<B.second;
  
  while (map[R.first+dr[d]][R.second+dc[d]]!='#') {
    R.first+=dr[d];
    R.second+=dc[d];
    if (map[R.first][R.second]=='O') {R_out=1;break;}
  }
  while (map[B.first+dr[d]][B.second+dc[d]]!='#') {
    B.first+=dr[d];
    B.second+=dc[d];
    if (map[B.first][B.second]=='O') {B_out=1;break;}
  }
  if (B_out) return -1;
  if (R_out) return 1;
  if (R==B) {
    if (d==0) {
      if (r_R_first) ++B.first;
      else ++R.first;
    }
    else if (d==1) {
      if (c_R_first) --R.second;
      else --B.second;
    }
    else if (d==2) {
      if (r_R_first) --R.first;
      else --B.first;
    }
    else {
      if (c_R_first) ++B.second;
      else ++R.second;
    }
  }

  return 0;
}


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::string> map(n);
  std::pair<int, int> init_r, init_b;
  for (int i=0;i<n;++i) {
    std::cin >> map[i];
    for (int j=0;j<m;++j) {
      if (map[i][j]=='R') init_r={i, j}, map[i][j]='.';
      else if (map[i][j]=='B') init_b={i, j}, map[i][j]='.';
    }
  }

  int min=15;
  for (int bitmask=0;bitmask<(1<<20);++bitmask) {
    std::pair<int, int> R=init_r, B=init_b;
    int p=4;
    for (int i=0;i<10;++i) {
      int d=bitmask>>(i<<1)&3;
      if (p==d) break;
      p=d;

      int res=mv(map, R, B, d);
      if (res==1) {min=std::min(min, i+1);break;}
      else if (res==-1) break;
    }
  }
  std::cout << (min!=15?min:-1);

  return 0;
}