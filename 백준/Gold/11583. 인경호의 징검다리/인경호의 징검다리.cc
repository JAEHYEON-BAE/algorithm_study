// 11583

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;
constexpr int INF=(~0u)>>2;

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
  
int f(int x, int d)
{
  int cnt=0;
  while (x%d==0) ++cnt, x/=d;
  return cnt;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;  read(t);
  while (t--) {
    int n, k; read(n), read(k);
    int x;  read(x);

    std::vector<int> dp2(k, INF), dp5(k, INF);
    dp2[0]=f(x, 2), dp5[0]=f(x, 5);

    for (int i=1;i<n;++i) {
      read(x);

      int a=f(x, 2), b=f(x, 5);
      std::vector<int> tmp2(k, INF), tmp5(k, INF);
      for (int j=0;j<k;++j) {
        tmp2[0]=std::min(tmp2[0], dp2[j]+a);
        tmp5[0]=std::min(tmp5[0], dp5[j]+b);

        if (j+1<k) {
          tmp2[j+1]=std::min(tmp2[j+1], dp2[j]);
          tmp5[j+1]=std::min(tmp5[j+1], dp5[j]);
        }
      }
      dp2=tmp2;
      dp5=tmp5;
    }
    std::cout << std::min(dp2[0], dp5[0]) << '\n';
  }
  return 0;
}

