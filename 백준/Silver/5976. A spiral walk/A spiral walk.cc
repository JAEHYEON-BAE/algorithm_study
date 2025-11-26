// 5967

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

constexpr int dr[4]={0, 1, 0, -1};
constexpr int dc[4]={1, 0, -1, 0};

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

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));

  int r=0, c=0, id=1;
  v[r][c]=id;
  for (int d=0;d<4;++d, d%=4) {
    bool FLAG=1;
    while (1) {
      int nr=r+dr[d];
      int nc=c+dc[d];
      if (nr<0 || nr>=n || nc<0 || nc>=n || v[nr][nc]!=0) break;

      FLAG=0;
      v[nr][nc]=++id;
      r=nr, c=nc;
    }
    if (FLAG) break;
  }

  for (const auto &r:v) {
    for (const int &x:r) write(x), put(' ');
    put('\n');
  }
  flush();
  return 0;
}