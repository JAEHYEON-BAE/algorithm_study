// 17134

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <array>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

constexpr long long int MOD=998'244'353;
constexpr long long int w=3;

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

  for (int i=0;i<n;++i) {
    if (i<rev[i]) std::swap(v[i], v[rev[i]]);
  }
  
  long long int i=2;
  while (i<=n) {
    long long int step=n/i;
    for (int j=0;j<n;j+=i) for (int k=0;k<(i>>1);++k) {
      long long int a=v[j|k], b=v[j|k|i>>1];
      if (a==0 && b==0) continue;
      b=b*root[step*k]%MOD;
      v[j|k]=(a+b)%MOD;
      v[j|k|i>>1]=(a-b+MOD)%MOD;
    }
    i<<=1;
  }

  if (invert) {
    long long int inv=mod_pow(n, MOD-2);
    for (auto &x:v) if (x) x=x*inv%MOD;
  }
}

std::vector<long long int> multiply(std::vector<long long int> a, std::vector<long long int> b) 
{
  int n=1;
  while (n<(a.size()+b.size())) n<<=1;
  a.resize(n);
  b.resize(n);

  rev.assign(n, 0);
  for (int i=0;i<n;++i) {
    rev[i]=rev[i>>1]>>1;
    if (i&1) rev[i]|=n>>1;
  }

  std::vector<long long int> root(n, 1), inv_root(n, 1);
  long long int x=mod_pow(w, (MOD-1)/n);
  long long int inv_x=mod_pow(x, MOD-2);

  for (int i=1;i<n;++i) {
    root[i]=root[i-1]*x%MOD;
    inv_root[i]=inv_root[i-1]*inv_x%MOD;
  }

  NTT(a, root);
  NTT(b, root);

  for (int i=0;i<n;++i) a[i]=a[i]*b[i]%MOD;

  NTT(a, inv_root, 1);
  return a;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  const int MAX=1'000'001;
  std::vector<long long int> is_odd_prime(MAX, 1);
  std::vector<long long int> is_semiprime(MAX, 0);
  is_odd_prime[0]=is_odd_prime[1]=0;
  for (int i=2;i*i<MAX;++i) {
    if (is_odd_prime[i]) for (int j=i*i;j<MAX;j+=i) {
      is_odd_prime[j]=0;
    }
  }
  for (int i=2;i*2<MAX;++i) {
    if (is_odd_prime[i]) is_semiprime[i<<1]=1;
  }

  is_odd_prime[2]=0;

  auto result=multiply(is_odd_prime, is_semiprime);

  int t;  std::cin >> t;
  while (t--) {
    int n;  std::cin >> n;
    std::cout << result[n] << '\n';
  }

  return 0;
}