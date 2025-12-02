// 4008

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
using i128=__int128;

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
template <typename T>
void read(T &x)
{
  static char c; x=T(0);
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}

struct Line
{
  ll m, k;
  Line() {}
  Line(ll m, ll k): m(m), k(k) {}

  inline ll f(ll x) const {
    return m*x+k;
  }
};

struct CHT
{
  int pos=0;
  std::vector<Line> lines;

  CHT() {}

  void insert(ll m, ll k) {
    while (lines.size()>=2) {
      Line &a=lines[lines.size()-2];
      Line &b=lines.back();

      i128 x=(i128)(a.k-b.k)*(m-b.m);
      i128 y=(i128)(b.k-k)*(b.m-a.m);
      if (x>=y) lines.pop_back();
      else break;
    }
    lines.push_back(Line(m, k));
  }
  ll query(ll x) {
    while (pos+1<lines.size() && lines[pos].f(x)<=lines[pos+1].f(x)) ++pos;
    return lines[pos].f(x);
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n; ll a, b, c;
  read(n), read(a), read(b), read(c);
  std::vector<ll> x(n+1), S(n+1, 0);
  for (int i=1;i<=n;++i) {
    read(x[i]);
    S[i]+=S[i-1]+x[i];
  }

  CHT cht;
  cht.insert(0, 0);
  ll dp=0ll;
  for (int i=1;i<=n;++i) {
    dp=a*S[i]*S[i]+b*S[i]+c+cht.query(S[i]);
    cht.insert(-2ll*a*S[i], dp+a*S[i]*S[i]-b*S[i]);
  }
  std::cout << dp;
  
  return 0;
}