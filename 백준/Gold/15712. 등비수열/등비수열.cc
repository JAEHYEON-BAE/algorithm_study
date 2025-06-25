// 15712

#include <iostream>
#include <vector>
#include <algorithm>

long long int POWER(long long int a, long long int r, const long long int &mod)
{
  long long int tmp=1;
  a%=mod;
  while (r) {
    if (r&1) {tmp*=a; tmp%=mod;}
    a*=a; a%=mod;
    r>>=1;
  }
  return tmp;
}

long long int SUM(long long int a, long long int r, long long int n, const long long int &mod)
{
  if (n==1) return a%mod;
  if (n&1) return (SUM(a, r, n-1, mod)+a*POWER(r, n-1, mod)%mod)%mod;
  else return SUM(a, r, n>>1, mod)*(1+POWER(r, n>>1, mod)%mod)%mod;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  long long int a, r, n, mod;
  std::cin >> a >> r >> n >> mod;
  if (r==1) {std::cout << a*n%mod; return 0;}
  std::cout << SUM(a, r, n, mod);

  return 0;
}
