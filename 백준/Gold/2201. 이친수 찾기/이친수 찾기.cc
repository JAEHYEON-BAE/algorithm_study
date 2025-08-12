// 2201

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll=long long int;

// 길이가 n인, k번째 이친수
void DP(int n, ll k, const std::vector<ll> &fib, std::string &ans)
{
  // k번째 이친수가 몇 자리수인지 구하기
  int len=0;
  for (int i=1;i<90;++i) {
    if (k>=fib[i]) k-=fib[i];
    else {len=i; break;}
  }
  // std::cout << n << ' ' << k << "\tlen=" << len << std::endl;
  
  if (n>len && ans.empty()) {ans+='1';--n;}
  while (n>len) {ans+='0';--n;}

  // std::cout << n << ' ' << k << std::endl;
  
  if (n==0) return;
  else if (n==1) {
    if (k==0) ans+='0';
    else if (k==1) ans+='1';
    else assert(!"n is 1, but k>1");
  }
  else if (n==2) {
    if (k==0) ans+="10";
    else assert(!"n is 2, but k!=0");
  }
  else {
    ans+="10";
    DP(n-2, k, fib, ans);
  }
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  ll k;  std::cin >> k;
  // 1로 시작하는 n자리 이친수의 개수: Fibonacci(n)
  // Fibonacci(90)=약 2.80e18
  // k의 범위: 1 <= k <= 1e18

  if (k==1) {std::cout << '1';return 0;}
  else if (k==2) {std::cout << "10";return 0;}

  std::vector<ll> fib(90);
  fib[1]=2;
  fib[2]=1;
  fib[3]=2;
  for (int i=4;i<90;++i) {
    fib[i]=fib[i-1]+fib[i-2];
  }

  // Step 1. k번째 이친수가 몇 자리수인지 구하기
  int len=0;
  for (int i=0;i<90;++i) {
    if (k>=fib[i]) k-=fib[i];
    else {len=i;break;}
  }

  std::string ans;
  ans.reserve(len);
  DP(len, k, fib, ans);
  
  std::cout << ans;
  return 0;
}
