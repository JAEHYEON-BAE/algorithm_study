// 3089

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <unordered_map>

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
void read(std::string &s, int size=0)
{
  static char c; s="";
  if (size) s.reserve(size);
  for (c=get();c<'!';c=get());
  for (;c>='!';c=get()) s+=c;
}


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  read(n), read(m);
  int x, y;
  std::unordered_map<int, std::set<int>> x_axis, y_axis;
  for (int i=0;i<n;++i) {
    read(x), read(y);
    x_axis[x].insert(y);
    y_axis[y].insert(x);
  }
  std::string s;  read(s, m);
  int curr_x=0, curr_y=0;
  for (const char &c:s) {
    if (c=='U') {
      curr_y=*x_axis[curr_x].upper_bound(curr_y);
    }
    else if (c=='D') {
      curr_y=*(--x_axis[curr_x].lower_bound(curr_y));
    }
    else if (c=='R') {
      curr_x=*y_axis[curr_y].upper_bound(curr_x);
    }
    else {
      curr_x=*(--y_axis[curr_y].lower_bound(curr_x));
    }

    // x_axis[curr_x].erase(curr_y);
    // y_axis[curr_y].erase(curr_x);
    // std::cout << curr_x << ' ' << curr_y << '\n';
  }
  std::cout << curr_x << ' ' << curr_y;
  return 0;
}