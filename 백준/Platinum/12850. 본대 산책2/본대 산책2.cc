// 12850

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
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

static constexpr int MOD=1'000'000'007;
long long int I[8][8]={
{1, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 1, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 0, 0, 0},
{0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 0, 0, 1, 0},
{0, 0, 0, 0, 0, 0, 0, 1}
};
long long int adj[8][8]={
{0, 1, 1, 0, 0, 0, 0, 0},
{1, 0, 1, 1, 0, 0, 0, 0},
{1, 1, 0, 1, 1, 0, 0, 0},
{0, 1, 1, 0, 1, 1, 0, 0},
{0, 0, 1, 1, 0, 1, 1, 0},
{0, 0, 0, 1, 1, 0, 0, 1},
{0, 0, 0, 0, 1, 0, 0, 1},
{0, 0, 0, 0, 0, 1, 1, 0}
};

void multiply(const long long int (&a)[8][8], const long long int (&b)[8][8], long long int (&result)[8][8]) {
  long long int tmp[8][8]={};
  for (int i=0;i<8;++i) for (int k=0;k<8;++k) {
    int aik=a[i][k];
    for (int j=0;j<8;++j) {
      tmp[i][j]+=aik*b[k][j];
      tmp[i][j]%=MOD;
    }
  }
  for (int i=0;i<8;++i) for (int j=0;j<8;++j) {
    result[i][j]=tmp[i][j];
  }
}

void power(long long int (&a)[8][8], long long int r, long long int (&result)[8][8])
{
  while (r) {
    if (r&1) multiply(result, a, result);
    multiply(a, a, a);
    r>>=1;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  power(adj, n, I);
  std::cout << I[0][0];
  
  return 0;
}