// 11525

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  // Euler phi function
  std::vector<int> phi(10'001);
  for (int i=0;i<10'001;++i) phi[i]=i;
  for (int i=2;i<10'001;++i) {
    if (phi[i]==i) for (int j=i;j<10'001;j+=i) {
      phi[j]-=phi[j]/i;
    }
  }
  std::vector<int> prefix_sum(10'001);
  prefix_sum[2]=phi[2];
  for (int i=3;i<10'001;++i) {
    prefix_sum[i]=prefix_sum[i-1]+phi[i];
  }
  
  while (t--) {
    int k, n;  std::cin >> k >> n;
    std::cout << k << ' ' << 2+prefix_sum[n] << '\n';
  }
  return 0;
}