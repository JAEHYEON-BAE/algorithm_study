// 10773

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
void read(long long int &x)
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

  int k; read(k);
  std::vector<long long int> stk;
  stk.reserve(k);

  long long int tot=0LL;
  while (k--) {
    long long int x;  read(x);
    if (x) {
      stk.push_back(x);
      tot+=x;
    }
    else {
      tot-=stk.back();
      stk.pop_back();
    }
  }
  std::cout << tot;
  
  return 0;
}