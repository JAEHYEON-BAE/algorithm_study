// 21767

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;
using ll=long long int;
using ld=long double;

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
void read(char &c)
{
  for (c=get();c==' '||c=='\n';c=get());
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

/* OUTPUT */
#define OUTPUT_BUFFER_SIZE (1<<20)

char obuf[OUTPUT_BUFFER_SIZE];
int opos=0;
inline void flush() 
{
  fwrite(obuf, 1, opos, stdout);
  opos=0;
}
inline void put(char c)
{
  if (opos==OUTPUT_BUFFER_SIZE) flush();
  obuf[opos++]=c;
}
void write(long long int x)
{
  if (x==0) return put('0');
  char tmp[20]; int len=0;
  if (x<0) {put('-');x*=-1;}
  while (x) {tmp[len++]='0'+(x%10); x/=10;}
  while (len--) put(tmp[len]);
}

int main() 
{
  int n, k;  read(n), read(k);
  ll a[4];  read(a[0]), read(a[1]), read(a[2]), read(a[3]);
  std::vector<std::vector<ll>> cards(4);
  for (int i=0;i<4;++i) cards[i].push_back(0);
  for (int i=0;i<n;++i) {
    char t; ll u;  read(t), read(u);
    cards[t-'A'].push_back(u);
  }
  for (int i=0;i<4;++i) std::sort(cards[i].begin(), cards[i].end(), std::greater<ll>());
  int it[4]={0, 0, 0, 0};
  for (int i=0;i<k;++i) {
    ld tmp[4]={(ld)cards[0][it[0]]/(ld)a[0], (ld)cards[1][it[1]]/(ld)a[1], (ld)cards[2][it[2]]/(ld)a[2], (ld)cards[3][it[3]]/(ld)a[3]};
    int t=std::max_element(tmp, tmp+4)-tmp;
    put((char)('A'+t));  put(' ');  write(cards[t][it[t]]);  put('\n');
    
    a[t]+=cards[t][it[t]];
    ++it[t];
  }

  flush();
  return 0;
}
