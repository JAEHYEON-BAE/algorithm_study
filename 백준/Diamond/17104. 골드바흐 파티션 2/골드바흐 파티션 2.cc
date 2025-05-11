// 17104

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

static constexpr long long int MOD=998'244'353; 
static constexpr long long int w=3;

long long int mod_pow(long long int a, long long int r)
{
  long long int tmp=1LL;
  while (r>0) {
    if (r&1) tmp=tmp*a%MOD;
    a=a*a%MOD;
    r>>=1;
  }
  return tmp;
}

static std::vector<int> rev;

void NTT(std::vector<long long int> &v, const std::vector<long long int> &root, bool invert=0)
{
  long long int n=v.size();
  long long int i=2;
  while (i<=n) {
    long long int step=n/i;
    for (int j=0;j<n;j+=i) {
      for (int k=0;k<(i>>1);++k) {
        long long int a=v[j|k], b=v[j|k|i>>1];
        if (a==0 && b==0) continue;
        b=b*root[step*k]%MOD;
        v[j|k]=(a+b)%MOD;
        v[j|k|i>>1]=(a-b+MOD)%MOD;
      }
    }
    i<<=1;
  }

  if (invert) {
    long long int inv=mod_pow(n, MOD-2);
    for (int i=0;i<n;++i) if (v[i]) v[i]=v[i]*inv%MOD;
  }
}

std::vector<long long int> multiply(std::vector<long long int> a)
{
  int n=1;
  while (n<(a.size()<<1)) n<<=1;
  a.resize(n);

  rev.assign(n, 0);
  for (int i=0;i<n;++i) {
    rev[i]=rev[i>>1]>>1;
    if (i&1) rev[i]|=n>>1;
    if (i<rev[i]) {
      std::swap(a[i], a[rev[i]]);
    }
  }

  std::vector<long long int> root(n, 1), inv_root(n, 1);
  long long int x=mod_pow(w, (MOD-1)/n);
  long long int inv_x=mod_pow(x, MOD-2);
  for (int i=1;i<n;++i) {
    root[i]=root[i-1]*x%MOD;
    inv_root[i]=inv_root[i-1]*inv_x%MOD;
  }
  
  NTT(a, root);
  
  
  for (int i=0;i<n;++i) a[i]=a[i]*a[i]%MOD;
  for (int i=0;i<n;++i) if (i<rev[i]) std::swap(a[i], a[rev[i]]);
  NTT(a, inv_root, 1);
  return a;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::vector<long long int> is_prime(1'000'001, 1);
  is_prime[0]=is_prime[1]=0;
  for (int i=2;i*i<1'000'001;++i) {
    if (is_prime[i]) for (int j=i<<1;j<1'000'001;j+=i) {
      is_prime[j]=0;
    }
  }
  auto result=multiply(is_prime);
  
  int t;  std::cin >> t;
  int n;
  while (t--) {
    std::cin >> n;
    if (is_prime[n>>1]) std::cout << 1+(result[n]>>1) << '\n';
    else std::cout << (result[n]>>1) << '\n';
  }
  return 0;
}