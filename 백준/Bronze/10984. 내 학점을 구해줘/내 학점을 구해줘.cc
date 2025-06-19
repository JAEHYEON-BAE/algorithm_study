// 10984

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int n;  std::cin >> n;
    long double tot=0.0L;
    int num=0;
    for (int i=0;i<n;++i) {
      int c; long double g;
      std::cin >> c >> g;
      num+=c;
      tot+=g*c;
    }
    std::cout << num << ' ' << std::fixed << std::setprecision(2) << tot/static_cast<long double>(num) << '\n';
  }
  

  return 0;
}
