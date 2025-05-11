// 2248

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

void print_binary(int x, int n)
{
  for (int i=n-1;i>=0;--i) {
    uint tmp=1<<i;
    if (x>=tmp) {
      std::cout << 1;
      x-=tmp;
    }
    else std::cout << 0;
  }
}

void recur(int n, int l, int I, const std::vector<std::vector<uint>> &dp)
{
  if (n<=0 || l<0) return;

  uint tmp=dp[n-1][l];
  if (tmp==-1) tmp=1;
  // std::cout << '\n';
  // DEBUG(n), DEBUG(l), DEBUG(I);
  // DEBUG(tmp);

  if (n<=l) {
    print_binary(I, n);
    return;
  }
  
  if (I>=tmp) {
    std::cout << 1;
    // std::cout << '\n';
    recur(n-1, l-1, I-tmp, dp);
  }
  else {
    std::cout << 0;
    // std::cout << '\n';
    recur(n-1, l, I, dp);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  uint n, l, I;  std::cin >> n >> l >> I;
  --I;
  std::vector<std::vector<uint>> dp(n+1, std::vector<uint>(l+1, -1));
  for (int i=1;i<=l;++i) dp[i][i]=1<<i;
  for (int i=1;i<=n;++i) dp[i][0]=1;

  for (int i=2;i<=n;++i) for (int j=1;j<i && j<=l;++j) {
    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
  }
  recur(n, l, I, dp);
  
  return 0;
}