// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <stack>

#ifndef FASTIO_HPP
#define FASTIO_HPP

#include <cstdio>
#include <string>
#include <cmath>
#include <type_traits>

namespace fastio
{
  #define INPUT_BUFFER_SIZE 100'000
  #define OUTPUT_BUFFER_SIZE 1'000'000
  
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
  void read(long long int &x)
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
  void read(long double &ld) 
  {
    static char c; ld=0.0L;
    bool MINUS_FLAG=0;
    for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
    if (c=='-') {MINUS_FLAG=1;c=get();}
    for (;c>='0'&&c<='9';c=get()) ld=ld*10+(c-'0');
    if (c=='.') {
      long double t=1.0L;
      for (c=get();c>='0'&&c<='9';c=get()) {
        t/=10;
        ld+=t*(c-'0');
      }
    }
    if (MINUS_FLAG) ld*=-1.0L;
  }
  void readline(std::string &s, int size=0)
  {
    static char c; s="";
    if (size) s.reserve(size);
    for (c=get();c!='\n'&&c!=EOF;c=get()) s+=c;
  }

  /* OUTPUT */
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
  void write(size_t x)
  {
    if (x==0) return put('0');
    char tmp[12]; int len=0;
    while (x) {tmp[len++]='0'+(x%10); x/=10;}
    while (len--) put(tmp[len]);
  }
  void write(long long int x)
  {
    if (x==0) return put('0');
    char tmp[20]; int len=0;
    if (x<0) {put('-');x*=-1;}
    while (x) {tmp[len++]='0'+(x%10); x/=10;}
    while (len--) put(tmp[len]);
  }
  void write(long double x, size_t precision=3)
  {
    if (x<0) {put('-');x*=-1.0L;}
    if (precision==0) {
      return write(static_cast<long long int>(std::round(x)));
    }
    long long int int_part=static_cast<long long int>(x);
    write(int_part);
    x-=int_part;
    put('.');
    x=std::round(x*std::pow(10, precision));
    if (x==0) for (size_t i=0;i<precision;++i) put('0');
    else write(static_cast<long long int>(x));
  }
  inline void write(const std::string &s)
  {
    for (const char& c:s) put(c);
  }
  inline void write(const char &c) 
  {
    put(c);
  }
  template <typename T>
  inline typename std::enable_if<std::is_same<T, long double>::value>::type writeln(T x, size_t precision=3)
  {
    write(x, precision);
    put('\n');
  }
  template <typename T>
  inline typename std::enable_if<!std::is_same<T, long double>::value>::type writeln(T x)
  {
    write(x);
    put('\n');
  }
  struct FASTIO_FLUSHER
  {
    ~FASTIO_FLUSHER() {flush();}
  } fastio_flusher;
}

#endif

int Tarjans(int node, const std::vector<std::vector<int>> &graph, std::vector<int> &d, std::vector<int> &SCC_id, int &scc_n, std::stack<int> &stk, int &id, std::vector<bool> &done)
{

  d[node]=++id;
  stk.push(node);

  int low_link=d[node];
  for (const int &next:graph.at(node)) {
    if (!d[next]) low_link=std::min(low_link, Tarjans(next, graph, d, SCC_id, scc_n, stk, id, done));
    else if (!done[next]) low_link=std::min(low_link, d[next]);
  }

  if (low_link==d[node]) {
    
    while (!stk.empty()) {
      int top=stk.top();
      stk.pop();
      SCC_id[top]=scc_n;
      done[top]=1;

      if (top==node) break;
    }

    ++scc_n;
  }
  return low_link;
}


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;
  int t;  read(t);
  while (t--) {
    int n, m;  read(n), read(m);
    if (m==0) {writeln(n); continue;}

    std::vector<std::vector<int>> graph(n);
    for (int i=0;i<m;++i) {
      int a, b; read(a), read(b);
      --a;--b;
      graph[a].push_back(b);
    }
    std::vector<int> SCC_id(n, -1);
    std::vector<int> d(n, 0);
    int scc_n=0;
    std::stack<int> stack;
    int id=0;
    std::vector<bool> done(n, false);
    for (int i=0;i<n;++i) if (!d[i]) {
      Tarjans(i, graph, d, SCC_id, scc_n, stack, id, done);
    }

    if (scc_n==1) {writeln('0'); continue;}

    std::vector<int> in_degree(scc_n, 0), out_degree(scc_n, 0);
    
    for (int u=0;u<n;++u) for (const int &v:graph.at(u)) {
      if (SCC_id[u]==SCC_id[v]) continue;
      ++in_degree[SCC_id[v]];
      ++out_degree[SCC_id[u]];
    }

    int sink=0, source=0;
    for (int i=0;i<scc_n;++i) {
      if (in_degree[i]==0) ++source;
      if (out_degree[i]==0) ++sink;
    }

    writeln(std::max(source, sink));
  }
 
  return 0;
}
