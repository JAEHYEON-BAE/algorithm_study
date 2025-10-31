// 13263

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;
using ll=long long int;
constexpr ll INF=(~0uLL)>>1;

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
  static char c; x=0;
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}

struct Line
{
  ll m, c;
  Line() {}
  Line(ll m, ll c): m(m), c(c) {}
  ll value(const ll &x) const {
    return m*x+c;
  }
};

ll inter(const Line &a, const Line &b) 
{
  ll p=b.c-a.c;
  ll q=a.m-b.m;
  if (q<0) p*=-1, q*=-1;
  return p/q+(p%q?1:0);
}

struct CHT
{
  std::deque<Line> dq;

  void add_line(const Line &l) {
    while (dq.size()>1) {
      Line &l1=dq[dq.size()-2];
      Line &l2=dq[dq.size()-1];
      if (inter(l, l2)<=inter(l1, l2)) dq.pop_back();
      else break;
    }
    dq.push_back(l);
  }
  ll query(const ll &x) {
    while (dq.size()>1 && dq[0].value(x)>=dq[1].value(x)) dq.pop_front();
    return dq[0].value(x);
  }
};


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  std::vector<ll> a(n, 0), b(n, 0);
  for (ll &x:a) read(x);
  for (ll &x:b) read(x);

  std::vector<ll> dp(n);
  dp[0]=0;
  // for (int i=1;i<n;++i) {
  //   ll &tmp=dp[i];
  //   for (int j=0;j<i;++j) {
  //     tmp=std::min(tmp, dp[j]+a[i]*b[j]);
  //   }
  // }
  // std::cout << dp[n-1];
  CHT cht;
  cht.add_line(Line(b[0], dp[0]));
  for (int i=1;i<n;++i) {
    dp[i]=cht.query(a[i]);
    cht.add_line(Line(b[i], dp[i]));
  }
  std::cout << dp[n-1];
  return 0;
}