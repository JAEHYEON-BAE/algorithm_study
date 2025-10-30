// 29942

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <unordered_map>

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
void read(std::string &s)
{
  static char c; s="";
  for (c=get();c<'!';c=get());
  for (;c>='!';c=get()) s+=c;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  read(n), read(m);
  if (n==1) {
    std::string s;  read(s);
    std::cout << "SAAB\n" << s;
    return 0;
  }
  std::unordered_map<std::string, int> s2i;
  std::vector<std::string> i2s(n);
  for (int i=0;i<n;++i) {
    std::string s;  read(s);
    s2i[s]=i;
    i2s[i]=s;
  }

  std::vector<std::vector<int>> G(n);
  for (int i=0;i<m;++i) {
    std::string sa, sb;  read(sa), read(sb);
    int a=s2i[sa], b=s2i[sb];
    G[a].push_back(b);
    G[b].push_back(a);
  }

  std::vector<int> deg(n, 0);
  std::vector<int> ends;
  std::vector<int> seq;
  for (int i=0;i<n;++i) {
    deg[i]=G[i].size();
    if (deg[i]>2) {
      std::cout << "EI SAA";
      return 0;
    }
    else if (deg[i]==1) ends.push_back(i);
    else if (deg[i]==0) seq.push_back(i); 
  }

  if (ends.size()<2 || ends.size()&1) {
    std::cout << "EI SAA";
    return 0;
  }

  int k=ends.size();
  std::vector<bool> visited(n, 0);

  for (int i=0;i<k;++i) if (!visited[ends[i]]) {
    int s=ends[i];
    visited[s]=1;
    std::queue<int> q;
    q.push(s);
    seq.push_back(s);
    while (!q.empty()) {
      int u=q.front();
      q.pop();
      for (const int &v:G[u]) if (!visited[v]) {
        visited[v]=1;
        q.push(v);
        seq.push_back(v);
      }
    }
  }

  if (seq.size()==n) {
    std::cout << "SAAB\n";
    for (const int &id:seq) std::cout << i2s[id] << ' ';
  }
  else std::cout << "EI SAA";
  return 0;
}