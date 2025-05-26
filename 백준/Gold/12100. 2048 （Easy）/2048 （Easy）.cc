// 12100

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

void up(std::vector<std::vector<int>> &v)
{
  int n=v.size();
  for (int i=0;i<n;++i) {
    std::queue<int> q;
    for (int j=0;j<n;++j) {
      if (v[j][i]) q.push(v[j][i]);
      v[j][i]=0;
    }

    std::vector<bool> dirty(n, 0);

    int j=0;
    while (!q.empty()) {
      if (j && v[j-1][i]==q.front() && !dirty[j-1]) {
        v[j-1][i]<<=1;
        dirty[j-1]=1;
      }
      else v[j][i]=q.front(), ++j;
      q.pop();
    }
  }
}
void down(std::vector<std::vector<int>> &v) 
{
  int n=v.size();
  for (int i=0;i<n;++i) {
    std::queue<int> q;
    for (int j=n-1;j>=0;--j) {
      if (v[j][i]) q.push(v[j][i]);
      v[j][i]=0;
    }

    std::vector<bool> dirty(n, 0);

    int j=n-1;
    while (!q.empty()) {
      if (j<n-1 && v[j+1][i]==q.front() && !dirty[j+1]) {
        v[j+1][i]<<=1;
        dirty[j+1]=1;
      }
      else v[j][i]=q.front(), --j;
      q.pop();
    }
  }
}
void right(std::vector<std::vector<int>> &v) 
{
  int n=v.size();
  for (int i=0;i<n;++i) {
    std::queue<int> q;
    for (int j=n-1;j>=0;--j) {
      if (v[i][j]) q.push(v[i][j]);
      v[i][j]=0;
    }
    
    std::vector<bool> dirty(n, 0);

    int j=n-1;
    while (!q.empty()) {
      if (j<n-1 && v[i][j+1]==q.front() && !dirty[j+1]) {
        v[i][j+1]<<=1;
        dirty[j+1]=1;
      }
      else v[i][j]=q.front(), --j;
      q.pop();
    }
  }
}
void left(std::vector<std::vector<int>> &v) 
{
  int n=v.size();
  for (int i=0;i<n;++i) {
    std::queue<int> q;
    for (int j=0;j<n;++j) {
      if (v[i][j]) q.push(v[i][j]);
      v[i][j]=0;
    }

    std::vector<bool> dirty(n, 0);

    int j=0;
    while (!q.empty()) {
      if (j && v[i][j-1]==q.front() && !dirty[j-1]) {
        v[i][j-1]<<=1;
        dirty[j-1]=1;
      }
      else v[i][j]=q.front(), ++j;
      q.pop();
    }
  }
}

void DFS(std::vector<std::vector<int>> &v, int depth, int &max)
{
  if (depth==5) {
    int n=v.size();
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
      max=std::max(max, v[i][j]);
    }
    return;
  }
  
  for (int d=0;d<4;++d) {
    auto tmp=v;
    if (d==0) up(v);
    else if (d==1) right(v);
    else if (d==2) down(v);
    else left(v);

    DFS(v, depth+1, max);
    v=tmp;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::vector<int>> v(n, std::vector<int>(n));
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) std::cin >> v[i][j];

  int max=0;

  DFS(v, 0, max);
  std::cout << max;
  return 0;
}