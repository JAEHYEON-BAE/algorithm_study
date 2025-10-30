// 3988

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

  int n, k;  read(n), read(k);
  std::vector<int> v(n);
  for (int &x:v) read(x);
  std::sort(v.begin(), v.end());

  auto CMP=[&v](const int &a, const int &b) {
    return v[a+1]-v[a]>v[b+1]-v[b];
  };
  std::priority_queue<int, std::vector<int>, decltype(CMP)> pq(CMP);

  int l=n-k;
  for (int i=0;i<l-1;++i) pq.push(i);
  int M=v[l-1]-v[0], m=v[pq.top()+1]-v[pq.top()];

  int answer=M+m;
  
  for (int i=1;i<k+1;++i) {
    M=v[i+l-1]-v[i];
    pq.push(i+l-2);
    while (pq.top()<i) pq.pop();
    m=v[pq.top()+1]-v[pq.top()];
    answer=std::min(answer, M+m);
  }
  std::cout << answer;
  
  return 0;
}