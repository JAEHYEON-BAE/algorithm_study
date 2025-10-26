// 8693

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

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
void write(int x)
{
  if (x==0) return put('0');
  char tmp[11]; int len=0;
  if (x<0) {put('-');x*=-1;}
  while (x) {tmp[len++]='0'+(x%10); x/=10;}
  while (len--) put(tmp[len]);
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) read(v[i][j]);

  int m;  read(m);
  std::vector<std::vector<int>> d(n, std::vector<int>(n, 0));
  for (int _=0;_<m;++_) {
    int c1, r1, c2, r2;  read(c1), read(r1), read(c2), read(r2);
    --r1, --c1, --r2, --c2;
    // std::cout << r1 << ' ' << c1 << '\t' << r2 << ' ' << c2 << '\n';

    ++d[r1][c1];
    if (c2+1<n) --d[r1][c2+1];
    if (r2+1<n) --d[r2+1][c1]; 
    if (r2+1<n && c2+1<n) ++d[r2+1][c2+1];
  }

  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    if (i) d[i][j]+=d[i-1][j];
    if (j) d[i][j]+=d[i][j-1];
    if (i && j) d[i][j]-=d[i-1][j-1];
    
    if (d[i][j]&1) d[i][j]=1;
    else d[i][j]=0;
    // std::cout << d[i][j] << ' ';
  }

  for (int i=0;i<n;++i) {
    for (int j=0;j<n;++j) write(v[i][j]^d[i][j]), put(' ');
    put('\n');
  }
  flush();
  return 0;
}