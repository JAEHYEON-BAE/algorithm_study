// 15553
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  std::vector<int> cost(n, 0);
  int prev;  std::cin >> prev;
  for (int i=1;i<n;++i) {
    int x;  std::cin >> x;
    cost[i]=x-prev-1;
    prev=x;
  }
  std::sort(cost.begin(), cost.end());
  int ans=n;
  for (int i=1;i<=n-k;++i) {
    ans+=cost[i];
  }
  std::cout << ans;
  return 0;
}