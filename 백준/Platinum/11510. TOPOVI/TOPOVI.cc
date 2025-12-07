// 11510

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

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
template<typename T>
void write(T x)
{
  if (x==0) return put('0');
  char tmp[20]; int len=0;
  if (x<0) {put('-');x*=-1;}
  while (x) {tmp[len++]='0'+(x%10); x/=10;}
  while (len--) put(tmp[len]);
}

namespace std
{
  template <>
  struct hash<std::pair<int, int>> {
    size_t operator()(const std::pair<int, int> &p) const {
      return static_cast<ll>(p.first)*1'000'000'009+static_cast<ll>(p.second);
    }
  };
}

struct Board
{
  ll n;
  ll rzero, czero, match=0;
  std::unordered_map<int, int> rr, cc, rcnt, ccnt;

  Board(ll n): n(n), rzero(n), czero(n), match(0) {}

  void update(int r, int c, int x) {
    int oldr=rr[r], oldc=cc[c];
    int newr=oldr^x, newc=oldc^x;

    if (oldr==0) --rzero;
    else {
      match-=ccnt[oldr];
      --rcnt[oldr];
    }
    if (oldc==0) --czero;
    else {
      match-=rcnt[oldc];
      --ccnt[oldc];
    }

    rr[r]=newr, cc[c]=newc;
    if (newr==0) ++rzero;
    else {
      match+=ccnt[newr];
      ++rcnt[newr];
    }
    if (newc==0) ++czero;
    else {
      match+=rcnt[newc];
      ++ccnt[newc];
    }
    // std::cerr << rzero << ' ' << czero << '\t' << match << std::endl;
  }

  ll cnt() const {
    return n*n-(rzero*czero+match);
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  ll n; int k, p;  read(n), read(k), read(p);
  std::unordered_map<std::pair<int, int>, int> map;

  Board B(n);
  int match=0;
  for (int i=0;i<k;++i) {
    int r, c, x;  read(r), read(c), read(x);
    --r, --c;
    map[{r, c}]=x;

    B.update(r, c, x);
  }
  
  while (p--) {
    int r1, c1, r2, c2;
    read(r1), read(c1), read(r2), read(c2);
    --r1, --c1, --r2, --c2;
    int x=map[{r1, c1}];
    
    B.update(r1, c1, x);
    B.update(r2, c2, x);
    write(B.cnt()), put('\n');
    
    map.erase({r1, c1});
    map[{r2, c2}]=x;
  }
  flush();
  return 0;
}
