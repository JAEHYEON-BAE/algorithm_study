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

int dr[4]={-1, 1, 0, 0};
int dc[4]={0, 0, 1, -1};

struct Shark
{
  int id, r, c, s, d, z;
  bool valid=1;
  Shark(){}
  void mv(const int &R, const int &C, std::vector<std::vector<int>> &map, std::vector<Shark> &sharks) {
    if (valid==0) return;

    if (d==0 || d==1) {
      this->s%=(R-1)<<1;
      this->r+=dr[this->d]*this->s;
      while (this->r>=R || this->r<0) {
        if (this->r>=R) {
          this->r=R-1-(this->r-R+1);
          d=1-d;
        }
        if (this->r<0) {
          this->r*=-1;
          d=1-d;
        }
      }
    }
    else {
      this->s%=(C-1)<<1;
      this->c+=dc[this->d]*this->s;
      while (this->c>=C || this->c<0) {
        if (this->c>=C) {
          this->c=C-1-(this->c-C+1);
          d=5-d;
        }
        if (this->c<0) {
          this->c*=-1;
          d=5-d;
        }
      }
    }

    if (map[r][c]!=-1) {
      if (sharks[map[r][c]].z<this->z) {
        sharks[map[r][c]].valid=0;
        map[r][c]=this->id;
      }
      else {
        this->valid=0;
        return;
      }
    }
    map[this->r][this->c]=this->id;
    return;
  }
};

void print_sh(const std::vector<Shark> &ss)
{
  for (const Shark &s:ss) if (s.valid) {
    std::cout << s.id << ':' << '\t' << s.r << ' ' << s.c << ' ' << s.s << ' ' << s.d << ' ' << s.z << '\n';
  }
  std::cout << std::endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  // using namespace fastio;
  int R, C, M;  std::cin >> R >> C >> M;
  std::vector<std::vector<int>> map(R, std::vector<int>(C, -1));
  
  std::vector<Shark> sharks(M);
  for (int i=0;i<M;++i) {
    sharks[i].id=i;
    std::cin >> sharks[i].r >> sharks[i].c >> sharks[i].s >> sharks[i].d >> sharks[i].z;
    --sharks[i].r;--sharks[i].c;--sharks[i].d;
    map[sharks[i].r][sharks[i].c]=sharks[i].id;
  }

  // print_sh(sharks);

  int tot=0;
  for (int i=0;i<C;++i) {
    for (int j=0;j<R;++j) if (map[j][i]!=-1 && sharks[map[j][i]].valid) {
      // std::cout << "CAUGHT: " << map[j][i] << '\n';
      tot+=sharks[map[j][i]].z;
      sharks[map[j][i]].valid=0;
      break;
    }

    for (auto &x:map) std::fill(x.begin(), x.end(), -1);

    for (int id=0;id<M;++id) if (sharks[id].valid) {
      sharks[id].mv(R, C, map, sharks);
    }
    // print_sh(sharks);
  }
  std::cout << tot;
  
  return 0;
}
