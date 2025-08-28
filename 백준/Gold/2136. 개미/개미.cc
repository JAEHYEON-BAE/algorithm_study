// 2136

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

struct Ant
{
  int pos, idx;
  Ant(){}
  Ant(int p, int i): pos(p), idx(i) {}

  bool operator<(const Ant &o) const {
    return std::abs(pos)<std::abs(o.pos);
  }
};

struct Event
{
  int t;
  char side;

  Event(){}
  Event(int t, char s): t(t), side(s) {}

  bool operator<(const Event &o) const {
    return t<o.t;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, l;  read(n), read(l);
  int x, res=0;

  std::vector<Ant> ants(n);
  for (int i=0;i<n;++i) {
    read(x);
    ants[i].pos=x, ants[i].idx=i;
    res=std::max(res, x>0?l-x:-x);
  }
  std::sort(ants.begin(), ants.end());
  std::vector<int> idx(n);
  for (int i=0;i<n;++i) idx[i]=ants[i].idx;

  std::vector<Event> events(n);
  for (int i=0;i<n;++i) {
    int t=ants[i].pos>0?l-ants[i].pos:-ants[i].pos;
    char s=ants[i].pos>0?'R':'L';
    events[i].t=t; events[i].side=s;
  }
  std::sort(events.begin(), events.end());

  int L=0, R=n-1;
  int last=-1;
  for (const Event &e:events) {
    last=e.side=='L'?idx[L++]:idx[R--];
  }
  std::cout << last+1 << ' ' << res;
  return 0;
}