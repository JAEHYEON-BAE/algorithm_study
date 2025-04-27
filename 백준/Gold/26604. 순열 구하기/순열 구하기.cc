// 26604

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

std::vector<int> operator ^(const std::vector<int> &lhs, const std::vector<int> &rhs) 
{
  int n=lhs.size(), m=rhs.size();
  std::vector<int> result(std::max(n, m));
  for (int i=0;i<std::min(n, m);++i) {
    result[i]=lhs[i]^rhs[i];
  }

  if (n<m) for (int i=n;i<m;++i) result[i]=rhs[i];
  else for (int i=m;i<n;++i) result[i]=lhs[i];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> b(n+1);
  std::vector<std::vector<int>> a(n+1);
  a[n].resize(n+1);
  for (int i=1;i<=n;++i) {
    std::cin >> b[i];
    a[n][i]=i;
  }

  std::vector<bool> used(n+1, 0);

  for (int i=n;i>0;--i) {
    for (int j=i;j<=n;++j) {
      b[i]^=a[j][i];
    }
    used[b[i]]=1;
  

    if (i==1) break;
    a[i-1].push_back(0);
    for (int k=1;k<=n;++k) {
      if (!used[k]) a[i-1].push_back(k);
    }
  }

  for (int i=1;i<=n;++i) std::cout << b[i] << ' ';
  return 0;
}