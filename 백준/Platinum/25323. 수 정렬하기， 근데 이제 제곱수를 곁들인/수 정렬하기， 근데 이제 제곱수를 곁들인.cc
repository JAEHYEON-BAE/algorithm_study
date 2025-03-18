// 25323

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

long long int gcd(long long int a, long long int b)
{
  if (a==1 || b==1) return 1;
  long long int tmp;
  while (b) {
    tmp=b;
    b=a%b;
    a=tmp;
  }
  return a;
}
bool is_sqr(long long int x)
{
  long long int sqr=static_cast<long long int>(std::sqrt(x));
  if (sqr*sqr==x) return 1;
  else return 0;
}
bool is_sqr(long long int a, long long int b) 
{
  long long int g=gcd(a, b);
  if (g==1) return is_sqr(a) && is_sqr(b);
  else return is_sqr(a/g, b/g);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  std::vector<long long int> a(n), v(n);
  for (int i=0;i<n;++i) {
    std::cin >> v[i];
    a[i]=v[i];
  }
  std::sort(v.begin(), v.end());
  for (int i=0;i<n;++i) {
    if (v[i]==a[i]) continue;
    else {
      if (is_sqr(v[i], a[i])) continue;
      else {
        std::cout << "NO";
        return 0;
      }
    }
  }
  std::cout << "YES";
  return 0;
}