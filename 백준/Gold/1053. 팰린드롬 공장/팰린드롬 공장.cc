// 1053

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory.h>

int solve(const int left, const int right, std::vector<std::vector<int>> &dp, std::string& str)
{
  if (dp[left][right]!=-1) return dp[left][right];
  if (left>=right) return 0;

  dp[left][right] = std::min({1+solve(left+1, right, dp, str), 1+solve(left, right-1, dp, str), (str[left]!=str[right]) + solve(left+1, right-1, dp, str)});
  
  return dp[left][right];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string str;  std::cin >> str;
  size_t n = str.size();
  
  std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
  int result = solve(0, n-1, dp, str);

  for (int i=0;i<n;++i) for (int j=i+1;j<n;++j) {
    dp.assign(n, std::vector<int>(n, -1));
    std::swap(str[i], str[j]);
    result = std::min(result, 1+solve(0, n-1, dp, str));
    std::swap(str[i], str[j]);
  }  
  std::cout << result;
  
  return 0;  
}
