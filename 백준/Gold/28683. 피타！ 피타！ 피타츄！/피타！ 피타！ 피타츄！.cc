// 11664

#include <iostream>
#include <vector>
#include <cmath>

inline bool is_square(const long long& n) {
  long long root = static_cast<long long>(std::sqrt(n));
  return root*root==n;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long long n;  std::cin >> n;

  if (is_square(n)) {
    std::cout << -1;
    return 0;
  }
  long long cnt = 0L;

  // a^2+n=b^2  =>  n=(b-a)(b+a)
  // n=d1*d2    =>  b=(d1+d2)/2, a=|d1-d2|/2
  for (long long d1=1;d1*d1<=n;++d1) {
    if (n%d1==0) {
      long long d2 = n/d1;
      if ((d1+d2)%2==0) ++cnt;
    }
  }

  for (long long i=1;i*i<=n/2;++i) {
    if (is_square(n-i*i)) ++cnt;
  }
  std::cout << cnt;
}

