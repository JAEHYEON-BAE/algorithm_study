// 22856

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

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


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  int a, b, c;
  std::vector<std::vector<int>> G(n+1, std::vector<int>(2, -1));

  int res=0;
  for (int _=0;_<n;++_) {
    read(a), read(b), read(c);
    G[a][0]=b, G[a][1]=c;
  }

  int u=1, cnt=-1;
  while (u!=-1) u=G[u][1], ++cnt;

  std::cout << 2*(n-1)-cnt;
  return 0;
}