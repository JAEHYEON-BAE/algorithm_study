// 17428

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll=long long int;

ll DP(int i, ll j, std::vector<std::vector<ll>> &dp) 
{
  if (i==0) {
    if (j==0) return 1;
    else return 0;
  }
  ll &res=dp[i][j];
  if (res!=-1) return res;

  // '(' 추가하는 경우
  res=DP(i-1, j+1, dp);

  // ')' 추가하는 경우
  if (j) res+=DP(i-1, j-1, dp);

  return res;
}

void solve(int i, int j, ll k, std::vector<std::vector<ll>> &dp)
{
  if (i==0) return;
  if (k<DP(i-1, j+1, dp)) {
    std::cout << '(';
    return solve(i-1, j+1, k, dp);
  }
  else {
    std::cout << ')';
    return solve(i-1, j-1, k-DP(i-1, j+1, dp), dp);
  }
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n; ll k;  std::cin >> n >> k;

  std::vector<std::vector<ll>> dp(n+1, std::vector<ll>(n+1, -1));

  if (k>=DP(n, 0, dp)) std::cout << "-1";
  else solve(n, 0, k, dp);
  
  return 0;
}
