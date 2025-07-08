// 15678

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, d;  std::cin >> n >> d;
  std::vector<long long int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];

  // dp[i]=max(0, dp[j])+v[i] for i-d <= j < i

  std::deque<int> dq;
  std::vector<long long int> dp(n, 0);
  long long int max=v[0];

  dp[0]=v[0];
  dq.push_back(0);
  max=std::max(max, dp[0]);
  for (int i=1;i<n;++i) {
    while (!dq.empty() && dq.front()<i-d) dq.pop_front();
    dp[i]=std::max(dp[dq.front()], 0LL)+v[i];
    while (!dq.empty() && dp[dq.back()]<=dp[i]) dq.pop_back();
    dq.push_back(i);

    max=std::max(max, dp[i]);
  }
  std::cout << max;
  return 0;
}