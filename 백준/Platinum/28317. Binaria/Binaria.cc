// 28317

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_set>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
constexpr ll MOD=1'000'003;

/* INPUT */
#define INPUT_BUFFER_SIZE (1<<20)

char get()
{
  static char buf[INPUT_BUFFER_SIZE], *S=buf, *T=buf;
  if (S==T) {
    T=(S=buf)+fread(buf, 1, INPUT_BUFFER_SIZE, stdin);
    if (S==T) return EOF;
  }
  return *S++;
}
void read(int &x)
{
  static char c; x=0;
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}


std::vector<ll> fact;
void init(int k)
{
  fact.resize(k+1);
  fact[0]=1LL;
  for (ll i=1;i<=k;++i) {
    fact[i]=fact[i-1]*i%MOD;
  }
}

ll mod_exp(ll a, int r) 
{
  ll tmp=1;
  while (r) {
    if (r&1) tmp=tmp*a%MOD;
    a=a*a%MOD;
    r>>=1;
  }
  return tmp;
}

inline ll mod_inv(int x) 
{
  return mod_exp(x, MOD-2);
}

ll combination(ll n, ll r) 
{
  ll a=fact[n];
  ll b=mod_inv(fact[n-r]*fact[r]%MOD);
  return a*b%MOD;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  read(n), read(k);
  init(k);

  int m=n-k+1;
  std::vector<int> a(m);
  // d[i]:= a[i+1]-a[i],  
  // d[i] = S[i+k]-S[i],  
  // S[i+k] = S[i]+d[i]
  std::vector<int> d(m-1);
  for (int i=0;i<m;++i) {
    read(a[i]);
    if (a[i]>k) {std::cout << '0'; return 0;}
    if (i) {
      d[i-1]=a[i]-a[i-1];
      if (d[i-1]<-1 || d[i-1]>1) {std::cout << '0'; return 0;}
    }
  }

  ll free=0;
  ll one=0;
  
  for (int i=0;i<k;++i) {
    int cur=0, min=0, max=0;
    for (int j=i;j<m-1;j+=k) {
      cur+=d[j];
      min=std::min(min, cur);
      max=std::max(max, cur);
      if (min<-1 || max>1) {std::cout << '0'; return 0;}
    }
    bool _0=min==0;
    bool _1=max==0;

    if (_0 && _1) ++free;
    else if (_1) ++one;
    else if (!_0) {std::cout << '0'; return 0;}
  }

  if (a[0]<one || free+one<a[0]) {std::cout << '0'; return 0;}
  // answer = Combination(free, a[0]-one)
  std::cout << combination(free, a[0]-one);
  return 0;
}