// 2830
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];

  long long ans=0;
  for (int b=0;b<32;++b) {
    int ones=0;
    for (int i=0;i<n;++i) {
      if (v[i]&(1<<b)) ++ones;
    }
    ans+=(1LL<<b)*ones*(n-ones);
  }
  std::cout << ans;
 
  return 0;
}