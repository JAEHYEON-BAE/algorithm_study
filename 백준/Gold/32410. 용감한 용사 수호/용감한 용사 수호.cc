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

  int n, m, x, y;  std::cin >> n >> m >> x >> y;
  std::vector<std::vector<int>> dp(m+1, std::vector<int>(301, -1));
  dp[0][x]=y;
  for (int i=0;i<n;++i) {
    int dx, dy;  std::cin >> dx >> dy;
    for (int j=m;j>=1;--j) for (int k=300;k>=0;--k) if (dp[j-1][k]!=-1) {
      int new_dx=std::min(k+dx, 300);
      int new_dy=std::min(dp[j-1][k]+dy, 300);
      // std::cerr << j << ' ' << k << '\t' << new_dx << ' ' << new_dy << '\n';
      dp[j][new_dx]=std::max(dp[j][new_dx], new_dy);
    }
  }

  int k;  std::cin >> k;
  std::vector<std::vector<int>> cnt(301, std::vector<int>(301, 0));
  auto sum=cnt;
  
  for (int i=0;i<k;++i) {
    int p, q;  std::cin >> p >> q;
    ++cnt[p][q];
  }
  
  for (int i=1;i<=300;++i) for (int j=1;j<=300;++j) {
    sum[i][j]=cnt[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
  }

  int res=0;
  for (int dx=0;dx<=300;++dx) {
    int dy=dp[m][dx];
    if (dy==-1) continue;
    res=std::max(res, sum[dx][dy]);
  }
  std::cout << res;
  
  return 0;
}