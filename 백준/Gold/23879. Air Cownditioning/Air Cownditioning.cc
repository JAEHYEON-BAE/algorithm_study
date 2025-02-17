// 23879

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> p(n), t(n), diff(n+2, 0);
  for (int i=0;i<n;++i) std::cin >> p[i];
  for (int i=0;i<n;++i) std::cin >> t[i];

  for (int i=0;i<n;++i) diff[i+1]=p[i]-t[i];
  int cnt=0;
  for (int i=0;i<n+1;++i) {
    cnt+=std::abs(diff[i]-diff[i+1]);
  }
  std::cout << cnt/2;

  return 0;
}