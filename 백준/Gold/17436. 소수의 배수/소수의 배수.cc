// 17436

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  long long int m;  std::cin >> n >> m;
  std::vector<int> p(n);
  long long int cnt=0;
  for (int i=0;i<n;++i) std::cin >> p[i];
  for (int used=1;used<(1<<n);++used) {
    long long int tmp=1LL;
    int x=0;
    for (int i=0;i<n;++i) {
      if (used&(1<<i)) {
        tmp*=p[i]; ++x;
      }
    }
    if (x&1) cnt+=m/tmp;
    else cnt-=m/tmp;
  }
  std::cout << cnt;
  return 0;
}