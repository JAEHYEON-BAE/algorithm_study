// 2887

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

#include <cmath>
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

namespace tools
{
  static constexpr int INF=(~0u)>>2;
  static constexpr int nINF=(1<<31);
  static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};
  
  template <typename T>
  inline void print_v(const std::vector<std::vector<T>> &v)
  {
    for (auto x:v) {
      for (auto y:x) std::cout << y << ' ';
      std::cout << '\n';
    }
    std::cout << std::endl;
    return;
  }
  template <typename T, size_t N>
  inline void print_v(const T (&v)[N][N])
  {
    for (int i=0;i<N;++i) {
      for (int j=0;j<N;++j) std::cout << v[i][j] << ' ';
      std::cout << '\n';
    }
    std::cout << std::endl;
  }
}

struct Edge
{
  int u, v, cost;
  Edge() {}
  Edge(int u, int v, int cost): u(u), v(v) {}
  bool operator<(const Edge &other) const {
    return cost<other.cost;
  }
};

int find(int x, std::vector<int> &root)
{
  if (x==root[x]) return x;
  return root[x]=find(root[x], root);
}

bool unite(int x, int y, std::vector<int> &root, std::vector<int> &rank)
{
  int root_x=find(x, root);
  int root_y=find(y, root);
  if (root_x==root_y) return 0;

  if (rank[root_x]==rank[root_y]) {
    root[root_x]=root_y;
    ++rank[root_y];
  }
  else if (rank[root_x]<rank[root_y]) root[root_x]=root_y;
  else root[root_y]=root_x;

  return 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;
  int n, m;  read(n), read(m);
  std::vector<Edge> edges(m);
  for (int i=0;i<m;++i) {
    read(edges[i].u), read(edges[i].v), read(edges[i].cost);
  }
  std::sort(edges.begin(), edges.end());

  std::vector<int> root(n), rank(n, 0);
  for (int i=0;i<n;++i) root[i]=i;

  int tot=0;
  int max=0;
  for (const Edge &e:edges) {
    if (unite(e.u, e.v, root, rank)) {
      tot+=e.cost;
      max=std::max(max, e.cost);
    }
  }

  write(tot-max);

  return 0;
}
