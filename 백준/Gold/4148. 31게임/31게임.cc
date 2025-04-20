// 15835

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

static int8_t dp[32][15625];

int encode(const int (&card)[6])
{
  int result=0;
  for (int i=0;i<6;++i) {
    result=result*5+card[i];
  }
  return result;
}

bool solve(int sum, int (&card)[6])
{
  int mask=encode(card);
  if (dp[sum][mask]!=-1) return dp[sum][mask];

  for (int i=0;i<6;++i) {
    // 고른 수: i+1
    if (card[i]==0 || sum+i+1>31) continue;
    --card[i];
    bool tmp=solve(sum+i+1, card);
    ++card[i];
    if (!tmp) return dp[sum][mask]=1;
  }
  return dp[sum][mask]=0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  for (int i=0;i<32;++i) for (int j=0;j<15625;++j) {
    if (i==31) dp[i][j]=0;
    else dp[i][j]=-1;
  }
  

  std::string line;
  while (std::cin >> line) {
    std::cout << line << ' ';
    int sum=0;
    int card[6]={4, 4, 4, 4, 4, 4};
    for (const char &c:line) {
      sum+=(c-'0');
      --card[c-'1'];
    }
    assert(sum<=31);

    bool result=solve(sum, card);
    if (line.size()&1) std::cout << (result?'B':'A') << '\n';
    else std::cout << (result?'A':'B') << '\n';
  }
  
  return 0;
}