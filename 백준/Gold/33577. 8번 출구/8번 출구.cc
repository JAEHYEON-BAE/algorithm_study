// 12660

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <array>


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




int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<long long int> v(n), sum(n, 0);
  
  for (int i=0;i<n;++i) {
    std::cin >> v[i];
    if (i) sum[i]=sum[i-1]+v[i];
    else sum[0]=v[0];
  }

  std::vector<long long int> tmp(n, 0);
  tmp[0]=v[0];
  for (int i=1;i<n;++i) {
    tmp[i]=std::max(tmp[i-1], v[i]-sum[i-1]);
  }

  long long int cnt=0, curr=0;
  for (int i=0;i<n;++i) {
    if (v[i]>curr) {
      // go back for 'back' times;
      long long int back=(v[i]-curr+tmp[i]-1)/tmp[i];
      curr+=back*tmp[i];
      cnt+=back;
    }
    curr-=v[i];
  }
  std::cout << cnt;
  return 0;
}