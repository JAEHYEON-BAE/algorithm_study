// 33148

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

#define FAIL {std::cout << "NO"; return 0;}

using ll=long long int;

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
template<typename T>
void read(T &x)
{
  static char c; x=T(0);
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}


inline bool issqr(ll x)
{
  ll tmp=std::sqrt(x);
  return tmp*tmp==x || (tmp+1)*(tmp+1)==x || (tmp-1)*(tmp-1)==x;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  read(n);
  std::map<ll, int> mcnt;
  for (int i=0;i<n*n;++i) {
    ll x;  read(x);
    ++mcnt[x];
  }

  std::vector<ll> m;
  for (auto it=mcnt.begin();it!=mcnt.end();it=std::next(it)) {
    m.push_back(it->first);
  }
  
  std::vector<ll> e;
  std::vector<int> c;
  if (!issqr(m[0])) FAIL;
  if (!issqr(mcnt[m[0]])) FAIL;
  e.push_back(std::sqrt(m[0]));
  c.push_back(std::sqrt(mcnt[m[0]]));
    
  // std::cerr << m[0] << ' ' << mcnt[m[0]] << '\t' << e[0] << ' ' << c[0] << '\n';
  mcnt[m[0]]=0;

  for (int i=1;i<m.size();++i) if (mcnt[m[i]]) {
    if (m[i]%e[0]) FAIL;
    if (mcnt[m[i]]%(c[0]<<1)) FAIL;
    e.push_back(m[i]/e[0]);
    c.push_back(mcnt[m[i]]/(c[0]<<1));
    // std::cerr << m[i] << ' ' << mcnt[m[i]] << '\t' << e[i] << ' ' << c[i] << '\n';
    
    for (int j=0;j<e.size()-1;++j) {
      ll tmp=e[j]*e.back();
      if (mcnt[tmp]<2*c[j]*c.back()) FAIL;
      mcnt[tmp]-=2*c[j]*c.back();
    }

    if (1e18/e.back()<e.back()) FAIL;
    ll tmp=e.back()*e.back();
    if (mcnt[tmp]<c.back()*c.back()) FAIL;
    mcnt[tmp]-=c.back()*c.back();

  }

  for (const auto &pair:mcnt) {
    // std::cerr << pair.first << ' ' << pair.second << '\n';
    if (pair.second) FAIL;
  }

  std::cout << "YES\n";
  for (int i=0;i<e.size();++i) {
    for (int j=0;j<c[i];++j) std::cout << e[i] << ' ';
  }
  return 0;
}

