// 24528

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <type_traits>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
constexpr ll MOD=998'244'353;

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
void read(ll &x)
{
  static char c; x=0;
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}
void read(char &c)
{
  for (c=get();c==' '||c=='\n';c=get());
}
void read(std::string &s, int size=0)
{
  static char c; s="";
  if (size) s.reserve(size);
  for (c=get();c<'!';c=get());
  for (;c>='!';c=get()) s+=c;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  // dp{i+1}=dp{i} + (dp{i}-dp{prev(c)-1})
  int n;  read(n);
  ll dp=1;
  std::vector<ll> prev(26, 0LL);
  for (int i=0;i<n;++i) {
    char c;  ll v;
    read(c), read(v);
    ll tmp=v*dp%MOD-(v-1LL)*prev[c-'a']%MOD;
    tmp=(tmp+MOD)%MOD;
    dp=(v+1LL)*dp%MOD-v*prev[c-'a']%MOD;
    dp=(dp+MOD)%MOD;
    prev[c-'a']=tmp;
  }
  std::cout << (dp-1+MOD)%MOD;
  return 0;
}