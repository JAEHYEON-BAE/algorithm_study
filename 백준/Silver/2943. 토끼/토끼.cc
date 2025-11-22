// 2943

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

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
template <typename T>
void write(T x)
{
  if (x==0) return put('0');
  char tmp[20]; int len=0;
  if (x<0) {put('-');x*=-1;}
  while (x) {tmp[len++]='0'+(x%10); x/=10;}
  while (len--) put(tmp[len]);
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  read(n), read(m);
  int k=static_cast<int>(std::sqrt(n));
  int r=n%k;

  std::vector<ll> cup((n+k-1)/k, 0);
  std::vector<ll> box(n, 0);
  while (m--) {
    int s, a;  read(s), read(a);
    --a;
    
    ll ans=0;
    while (a%k && s) {
      // std::cerr << "STEP 1: box[" << a << "]\n";
      ans+=++box[a];
      ++a, --s;
    }

    while (s>=k) {
      // std::cerr << "STEP 2: " << a << " - cup[" << a/k << "]\n";
      assert(a%k==0);
      ans+=++cup[a/k];
      a+=k;
      s-=k;
    }

    if (s) {
      if (a+s==n) {
        // std::cerr << "STEP 3: cup[" << a/k << "]\n";
        ans+=++cup[a/k];
      }
      else {
        while (s) {
          // std::cerr << "STEP 3: box[" << a << "]\n";
          ans+=++box[a];
          ++a, --s;
        }
      }
    }

    // std::cerr << ans << '\n';
    write(ans);
    put('\n');
  }
  flush();
  return 0;
}