// 1377

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

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
  std::vector<int> v(n);
  for (int &i:v) read(i);

  auto cpy=v;
  std::sort(cpy.begin(), cpy.end());
  std::vector<int> map(1'000'001, -1);
  int id=0;
  for (const int &i:cpy) {
    if (map[i]!=-1) ++id;
    else map[i]=id++;
  }

  std::vector<int> cnt(1'000'001, 0);
  for (int &i:v) {
    ++cnt[i];
    if (cnt[i]==1) i=map[i];
    else i=map[i]+cnt[i]-1;
  }

  int res=0;
  for (int i=0;i<n;++i) {
    res=std::max(res, i-v[i]);
  }
  std::cout << res+1;
  return 0;
}

