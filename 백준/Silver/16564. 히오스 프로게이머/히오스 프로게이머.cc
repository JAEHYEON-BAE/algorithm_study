// 16564

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];
  std::sort(v.begin(), v.end());
  
  int min=v[0];
  for (int i=1;i<n;++i) {
    if ((v[i]-min)*i>k) {
      std::cout << min+k/i;
      return 0;
    }
    k-=(v[i]-min)*i;
    min=v[i];
  } 
  std::cout << min+k/n;
  return 0;
}