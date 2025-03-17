// 2698

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_set>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int solve(int n, int k, bool b, std::vector<std::vector<std::vector<int>>> &dp)
{
  if (n<=k) return 0;
  if (k<0) return 0;
  if (dp[n][k][b]!=-1) return dp[n][k][b];
  
  if (b) return dp[n][k][1]=solve(n-1, k, 0, dp)+solve(n-1, k-1, 1, dp);
  else return dp[n][k][0]=solve(n-1, k, 0, dp)+solve(n-1, k, 1, dp);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::vector<std::vector<std::vector<int>>> dp(101, std::vector<std::vector<int>>(101, std::vector<int>(2, -1)));
  dp[1][0][0]=1;
  dp[1][0][1]=1;
  int t;  std::cin >> t;
  while (t--) {
    int n, k;  std::cin >> n >> k;
    std::cout << solve(n, k, 0, dp)+solve(n, k, 1, dp) << '\n';
  }
  
  return 0;
}