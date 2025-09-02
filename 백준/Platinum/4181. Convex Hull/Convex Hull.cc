// 4181

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

/* OUTPUT */
#define OUTPUT_BUFFER_SIZE (1<<20)

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
struct FASTIO_FLUSHER
{
  ~FASTIO_FLUSHER() {flush();}
} fastio_flusher;

struct Point
{
  int x, y;
  Point() {}
  Point(int x, int y): x(x), y(y) {}

  bool operator<(const Point &o) const {
    return x<o.x || (x==o.x && y<o.y);
  }
  bool operator==(const Point &o) const {
    return x==o.x && y==o.y;
  }
};

inline int CCW(const Point &a, const Point &b, const Point &c)
{
  long long int t=1LL*(b.x-a.x)*(c.y-a.y) - 1LL*(b.y-a.y)*(c.x-a.x);
  return t?t>0?1:-1:0;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n; read(n);
  std::vector<Point> points;
  for (int i=0;i<n;++i) {
    int x, y; char c;  read(x), read(y), c=get();
    if (c=='Y') points.push_back(Point(x, y));
  }

  auto min=std::min_element(points.begin(), points.end());
  std::swap(points[0], *min);
  
  std::sort(points.begin()+1, points.end(), 
    [&points] (const Point &a, const Point &b) {
      int ccw=CCW(points[0], a, b);
      
      if (ccw==0) {
        // ERROR: 가까운 점이 먼저임을 보장하지 않음
        // hull의 위쪽 껍질인 경우, 먼 점이 먼저임
        return a.x<b.x || (a.x==b.x && a.y<b.y);
      }
      else return ccw>0;
    });

  int m=points.size();
  int idx=m;
  for (int i=m-1;;--i) {
    if (CCW(points[0], points[i], points[i-1])) break;
    else idx=i;
  }

  if (idx<m) std::reverse(points.begin()+idx-1, points.end());

  write(m), put('\n');
  for (const Point &p:points) {
    write(p.x), put(' '), write(p.y), put('\n');
  }
 
  return 0;
}