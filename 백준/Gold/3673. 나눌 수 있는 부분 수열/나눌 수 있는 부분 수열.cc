// 3673

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int c;  std::cin >> c;
  while (c--) {
    int d, n;  std::cin >> d >> n;
    std::vector<int> v(n);
    std::cin >> v[0];
    v[0]%=d;
    for (int i=1;i<n;++i) {
      int x;  std::cin >> x;
      v[i]=(v[i-1]+x)%d;
    }
    std::vector<long long int> mod(d, 0);
    for (int i=0;i<n;++i) {
      ++mod[v[i]];
    }

    long long int cnt=mod[0];
    if (mod[0]>1) cnt+=(mod[0]-1)*mod[0]/2LL;
    
    for (int i=1;i<d;++i) {
      if (mod[i]>1) {
        cnt+=(mod[i]-1)*mod[i]/2LL;
      }
    }
    std::cout << cnt << '\n';
  }
  
  return 0;
}