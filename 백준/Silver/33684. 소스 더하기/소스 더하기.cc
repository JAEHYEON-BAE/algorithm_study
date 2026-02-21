// 33684

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

  int n, k; read(n), read(k);
  std::vector<int> a(n);
  for (int &x:a) read(x);
  std::sort(a.begin(), a.end());

  if (a.back()>k) {
    std::cout << '0';
    return 0;
  }
  int base=a[0];
  if (base<=0) {
    std::cout << "-1";
    return 0;
  }
  long long int cnt=0;
  for (int i=1;i<n;++i) {
    cnt+=(k-a[i])/base;
  }
  ++cnt;
  std::cout << cnt;
  return 0;
}
