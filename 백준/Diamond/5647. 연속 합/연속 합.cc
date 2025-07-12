// 15659

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

inline long long int mod_mul(long long int a, long long int b, const long long int &MOD)
{
  a%=MOD;b%=MOD;
  return static_cast<long long int>(static_cast<__int128>(a)*static_cast<__int128>(b)%static_cast<__int128>(MOD));
}

long long int mod_exp(long long int a, long long int r, const long long int &MOD)
{
  a%=MOD;
  long long int result=1LL;
  while (r) {
    if (r&1) result=mod_mul(result, a, MOD);
    a=mod_mul(a, a, MOD);
    r>>=1;
  }
  return result;
}

constexpr long long int bases[7]={2, 3, 5, 7, 11, 13, 17};
bool miller_rabin(long long int n)
{
  if (n==1) return 0;
  else if (n==2 || n==3 || n==5) return 1;
  else if (!(n&1)) return 0;

  long long int u=n-1; int t=0;
  while (!(u&1)) u>>=1, ++t;

  if (n<2047) {
    long long int base=2;
    long long int prev, curr=mod_exp(base, u, n);
    if (curr==1 || curr==n-1) return 1;
    for (int k=0;k<t;++k) {
      prev=curr;
      curr=mod_mul(prev, prev, n);
      if (curr==1 && prev!=1 && prev!=n-1) return 0;
    }
    if (curr!=1) return 0;
    return 1;
  }
  else {
    for (int i=0;i<7;++i) {
      long long int base=bases[i];
      long long int prev, curr=mod_exp(base, u, n);
      if (curr==1 || curr==n-1) continue;
      for (int k=0;k<t;++k) {
        prev=curr;
        curr=mod_mul(prev, prev, n);
        if (curr==1 && prev!=1 && prev!=n-1) return 0;
      }
      if (curr!=1) return 0;
    }
    return 1;
  }
}

long long int GCD(long long int a, long long int b)
{
  if (a<b) std::swap(a, b);
  while (b) {
    long long int tmp=a%b;
    a=b;
    b=tmp;
  }
  return a;
}

long long int pollard_rho(long long int n)
{
  if (!(n&1)) return 2;

  long long int x=rand()%(n-2)+2;
  long long int y=x;
  long long int c=rand()%(n-3)+1;

  auto f=[&n, &c](long long int v) -> long long int {
    return static_cast<long long int>((static_cast<__int128>(v)*v+c)%n);
  };

  long long int d=1;
  while (d==1) {
    x=f(x);
    y=f(f(y));
    d=GCD(std::abs(x-y), n);
    if (d==n) return pollard_rho(n);
  }
  return (miller_rabin(d)?d:pollard_rho(d));
}

long long int cnt_factors(long long int n)
{
  long long int result=1LL;
  while (n>1) {
    if (miller_rabin(n)) {
      result*=3;
      break;
    }
    long long int d=pollard_rho(n);
    long long int cnt=0LL;
    while (!(n%d)) n/=d, ++cnt;
    cnt<<=1;
    ++cnt;
    result*=cnt;
  }
  return result;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);


  /** BOJ 5647 - 누적 합
    * 연속하는 p(p>0)개의 정수의 합이 바로 다음에 연속하는 q개의 정수의 합과 일치하는 경우가 있다. 예를 들어, 9+10+11+12=13+14+15(p=4, q=3)이고, 4+5+6+7+8=9+10+11(p=5, q=3)이다. q가 주어졌을 때, 가능한 p의 개수를 구하는 프로그램을 작성하시오.
    *
    *
    * 두 번째 수열의 시작 수를 정수 x>0이라고 하자
    *     첫 번째 수열의 합은 p(2x-p-1)이고, 
    *     두 번째 수열의 합은 q(2x+q-1)이다.
    * q가 주어졌을 때, 이 두 수열의 합이 같은 정수 x가 존재하도록 하는 정수 p>0의 개수를 구하는 것이 문제의 요구사항이다.
    * 
    * 위의 수식을 전개하면 다음과 같다.
    *   2x=(p^2+q^2)/(p-q) + 1
    * 
    * 이때 p>q는 자명하므로, 정수 k>0에 대해 p=q+k라 하면, 위의 수식을 다음과 같이 표현할 수 있다.
    *   2x=k+1 + (2q^2)/k
    *
    * 만약 k가 홀수이면 (2q^2)/k가 짝수여야 하고. k가 q^2의 약수이기만 하면 위의 수식을 만족하는 x가 존재한다.
    *     따라서, q^2의 홀수인 약수 k에 대해, p=q+k인 경우가 가능하다.
    * 
    * 만약 k가 짝수이면, k=2t로 대입하여 다음과 같이 표현할 수 있다.
    *   2x=2t+1 + (q^2)/t
    * 이때는 (q^2)/t가 홀수인 경우, p=q+2t인 경우가 가능하다.
    *   다르게 표현하면, q^2의 홀수인 약수 i에 대해, t=(q^2)/i 라 하면 
    *   p=q+2(q^2)/i인 경우가 가능하다.
    *
    *
    * 정리하면, q^2가 홀수인 약수 d를 가진다고 할 때, p는 다음의 두 가지가 가능하다.
    *     p=q+d 또는 p=q+2(q^2)/d
    *
    * 이때 d==2(q^2)/d이려면 d^2==2(q^2)이어야 하므로 이와 같은 경우는 존재하지 않는다.
    * 따라서, 가능한 p의 개수는, q^2의 홀수인 약수의 개수의 두 배 이다.
    *     만약 q가 홀수인 소수라면 가능한 p의 개수는 항상 6이다.
    * 
    * Q.E.D.
    */

  long long int n;
  while (std::cin >> n) {
    if (!n) break;
    while (!(n&1)) n>>=1;
    std::cout << (cnt_factors(n)<<1) << '\n';
  }
  return 0;
}