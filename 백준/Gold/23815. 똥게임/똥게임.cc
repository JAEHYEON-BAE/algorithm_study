// 23815

#include <iostream>
#include <vector>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

inline int op(const int &x, const std::string &a)
{
  int tmp;
  if (a[0]=='+') tmp=(a[1]-'0')+x;
  else if (a[0]=='*') tmp=(a[1]-'0')*x;
  else if (a[0]=='-') tmp=x-(a[1]-'0');
  else tmp=x/(a[1]-'0');
  return tmp;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  int dp[2]={1, 1};
  for (int i=0;i<n;++i) {
    std::string a, b;  std::cin >> a >> b;

    if (dp[1]>0) dp[1]=std::max(dp[0], std::max(op(dp[1], a), op(dp[1], b)));
    else dp[1]=dp[0];

    if (dp[0]>0) dp[0]=std::max(op(dp[0], a), op(dp[0], b));
    else dp[0]=0;
    
    if (dp[0]<=0 && dp[1]<=0) {
      std::cout << "ddong game";
      return 0;
    }
  }
  std::cout << std::max(dp[0], dp[1]);
  
  
  return 0;
}