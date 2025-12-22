#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Attack
{
  int x, y;
  Attack(int x, int y): x(x), y(y) {}
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
 
  int n, a, l;  std::cin >> n >> a >> l;
  std::vector<std::vector<int>> dp(n+1, std::vector<int>(l+1, -1));
  dp[0][l]=a;

  std::vector<std::vector<char>> trace(n+1, std::vector<char>(l+1, 0));

  std::vector<Attack> v;
  v.reserve(n);
  for (int i=1;i<=n;++i) {
    int x, y; std::cin >> x >> y;
    v.push_back(Attack(x, y));

    for (int j=1;j<=l;++j) if (dp[i-1][j]!=-1) {
      int curr=dp[i-1][j];

      // LIFE
      if (y!=-1 && j-y>0) {
        if (dp[i][j-y]<curr) {
          dp[i][j-y]=curr;
          trace[i][j-y]='L';
        }
      }

      // AURA
      if (y==-1 || (x!=-1 && curr>=x)) {
        int next=std::max(0, curr-x);
        if (dp[i][j]<next) {
          dp[i][j]=next;
          trace[i][j]='A';
        }
      }
    }
  }
  
  for (int i=1;i<=l;++i) if (dp[n][i]!=-1) {
    std::cout << "YES\n";

    int curr_L=-1;
    for (int j=1;j<=l;++j) if (dp[n][j]!=-1) {
      curr_L=j;
      break;
    }
    std::string s;
    for (int i=n;i>=1;--i) {
      const char &c=trace[i][curr_L];
      s+=c;
      if (c=='L') curr_L+=v[i-1].y;
    }
    std::reverse(s.begin(), s.end());
    std::cout << s;
    return 0;
  }
  std::cout << "NO";
  return 0;
}

