// 11689

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long long int n;  std::cin >> n;
  if (n==1) {
    std::cout << 1;
    return 0;
  }

  int sqrtn = sqrt(n) + 1;
  std::vector<bool> isPrime(sqrtn + 1, true);
  std::vector<int> primes;
  isPrime[0] = isPrime[1] = false;

  for (int i=2;i<=sqrtn;++i) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (int j=i*2;j<=sqrtn;j+=i) {
        isPrime[j] = false;
      }
    }
  }
  
  long long int result=n;

  for (int i: primes) {
    if (n%i==0) {
      result = result/i * (i-1);
      while (n>1 && n%i==0) n/=i;
    }
  }
  
  if (n>1) result=result/n*(n-1);

  std::cout << result;  
  
  return 0;  
}
