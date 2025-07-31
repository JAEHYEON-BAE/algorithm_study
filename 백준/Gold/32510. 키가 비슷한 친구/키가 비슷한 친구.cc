// 32510

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define INPUT_BUFFER_SIZE (1<<20)
/* INPUT */
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

  int t;  read(t);
  int n, k;
  for (int tc=1;tc<=t;++tc) {
    read(n), read(k);
    std::vector<int> v(n);
    std::vector<std::pair<int, int>> p(n);
    for (int i=0;i<n;++i) {
      read(p[i].first);
      p[i].second=i;
    }
    std::sort(p.begin(), p.end());

    long long int res=0LL;
    std::vector<std::pair<int, int>> dq;
    dq.reserve(n);
    
    struct Comp {
      bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) const {
      return a.second>b.second;
      }
    };
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comp> pq;

    for (const auto &[value, idx]:p) {
      pq.push({value, idx});
      while (!pq.empty()) {
        if (pq.top().first>=value-k) {
          res+=idx-pq.top().second;
          break;
        }
        pq.pop();
      }
    }

    std::cout << "Case #" << tc << '\n' << res << '\n';
  }
  
  return 0;
}