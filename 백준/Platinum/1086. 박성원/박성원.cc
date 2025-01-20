// 1086

#include <iostream>
#include <vector>
#include <string>
#include <memory.h>

#define debug(a) std::cout << "CHECKPOINT #" << a << std::endl

int mod(const std::string& num, const int& d)
{
  int x=0;
  for (int i=0;i<num.size();++i) {
    x = (x*10+(num[i]-'0'))%d;
  }
  return x;
}

long long gcd(const long long& p, const long long& q)
{
  if (q==0) return p;
  return gcd(q, p%q);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::string> v(n);
  for (int i=0;i<n;++i)  std::cin >> v[i];
  int k;  std::cin >> k;

  std::vector<std::vector<long long>> dp(1L<<n, std::vector<long long>(k, 0));
  dp[0][0]=1; 

  int dec[51];
  dec[0] = 1%k;
  for (int i=1;i<51;++i) {
    dec[i] = dec[i-1]*10%k;
  }

  int mod_str[15];
  for (int i=0;i<n;++i) {
    mod_str[i] = mod(v[i], k);
  }


  // i-th number: dp[x] -> dp[x | (1<<i)]
  for (int curr=0;curr<(1<<n);++curr) {
    for (int i=0;i<n;++i) {
      if ((curr&(1<<i))==0) {
        int next_state = curr|(1<<i);
        for (int j=0;j<k;++j) {
          // dp[next state][next remainder] += dp[curr state][remainder] 
          dp[curr | (1<<i)][((j*dec[v[i].size()])%k + mod_str[i])%k] 
            += dp[curr][j];
        }
      }
    }
  }
  long long p=dp[(1<<n)-1][0], q=1;
  
  for (int i=1;i<=n;++i) q*=i;
  
  long long g = gcd(p, q);
  std::cout << p/g << '/' << q/g;
  
  return 0;  
}
