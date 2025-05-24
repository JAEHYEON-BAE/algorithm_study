// 6467

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::vector<bool> is_prime(1001, 1);
  is_prime[0]=is_prime[1]=0;
  for (int i=2;i*i<1001;++i) {
    if (is_prime[i]) for (int j=i*i;j<1001;j+=i) {
      is_prime[j]=0;
    }
  }
  is_prime[1]=1;
  std::vector<int> primes;
  for (int i=1;i<1001;++i) if (is_prime[i]) primes.push_back(i);
  int n, c;
  while (std::cin >> n >> c) {
    int size=std::upper_bound(primes.begin(), primes.end(), n) - primes.begin();
    int start, end;
    if (size&1) {
      start=(size>>1)-(c-1);
      end=(size>>1)+(c-1);
    }
    else {
      start=(size>>1)-c;
      end=(size>>1)+(c-1);
    }
    start=std::max(start, 0);
    end=std::min(end, size-1);
    std::cout << n << ' ' << c << ':' << ' ';
    for (int i=start;i<=end;++i) std::cout << primes[i] << ' ';
    std::cout << '\n' << '\n';
  }
  return 0;
}