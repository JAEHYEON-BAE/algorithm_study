// 9326

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

std::vector<int> primes;
std::vector<std::pair<int, int>> factorize(int n)
{
  std::vector<std::pair<int, int>> factors;
  for (const int &p:primes) {
    if (n<p) break;
    if (n%p==0) {
      int cnt=0;
      while (n%p==0) n/=p, ++cnt;
      factors.push_back(std::make_pair(p, cnt));
    }
  }
  if (n>1) factors.push_back(std::make_pair(n, 1));
  return factors;
}

int power(int a, int r)
{
  int tmp=1;
  while (r) {
    if (r&1) tmp*=a;
    a*=a;
    r>>=1;
  }
  return tmp;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::vector<bool> is_prime(40'000, 1);
  is_prime[0]=is_prime[1]=0;
  for (int i=2;i*i<40'000;++i) if (is_prime[i]) {
    for (int j=i*i;j<40'000;j+=i) is_prime[j]=0;
  }
  for (int i=0;i<40'000;++i) if (is_prime[i]) primes.push_back(i);


  int t;  std::cin >> t;
  while (t--) {
    int c;  std::cin >> c;
    std::vector<int> result;

    std::vector<std::pair<int, int>> factors=factorize(c);
    for (const auto &[p, cnt]:factors) {
      // std::cout << p << ' ' << cnt << '\n';
      int i=1;
      while (i<=cnt) {
        if (cnt&i) result.push_back(power(p, i));
        i<<=1;
      }
    }
    std::sort(result.begin(), result.end());
    for (const int &x:result) std::cout << x << ' ';
    std::cout << '\n';
  }

  return 0;
}

