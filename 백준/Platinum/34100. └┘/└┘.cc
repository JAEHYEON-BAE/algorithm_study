// 34100

#include <iostream>
#include <algorithm>
#include <vector>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

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
void read(std::string &s, int size=0)
{
  static char c; s="";
  if (size) s.reserve(size);
  for (c=get();c<'!';c=get());
  for (;c>='!';c=get()) s+=c;
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
inline void write(const std::string &s)
{
  for (const char& c:s) put(c);
}
inline void write(const char *s)
{
  while (*s) put(*s++);
}
inline void write(const char &c) 
{
  put(c);
}

bool s(int k, std::vector<std::string> &v, const int &m) 
{
  if (k==0) {
    for (int i=0;i<m;++i) if (v[k][i]=='.') return false;
    return true;
  }
  for (int i=0;i<m;++i) if (v[k][i]=='.') {

    if (v[k][i+1]!='.') return false;
    
    if (v[k-1][i]!='.') {
      if (v[k-1][i+1]!='.') return false;
      v[k][i]=v[k][i+1]=v[k-1][i+1]='b';
    }
    else {
      int j=i;
      while (j>0 && v[k-1][j-1]=='.') --j;
      if ((i-j)&1) {
        if (v[k-1][i+1]!='.') return false;
        v[k][i]=v[k][i+1]=v[k-1][i+1]='b';
      }
      else {
        v[k][i]=v[k][i+1]=v[k-1][i]='a';
      }
    }
  }
  return s(k-1, v, m);
}


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;  read(t);
  while (t--) {
    int n, m;  read(n), read(m);
    std::vector<std::string> v(n);
    for (auto &s:v) read(s, m);

    if (s(n-1, v, m)) for (const auto &s:v) write(s), write('\n');
    else write("-1\n");
  }
  flush();
  return 0;
}
