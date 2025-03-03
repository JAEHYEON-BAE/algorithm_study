// 1796

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string str;  std::cin >> str;
  int n=static_cast<int>(str.size());
  std::vector<std::vector<int>> position(27);
  for (int i=0;i<n;++i) {
    position[static_cast<int>(str[i]-'a')+1].push_back(i);
  }
  std::vector<std::vector<int>> dp(27, std::vector<int>(2, INF));
  dp[0][0]=0;
  int pos_l=0, pos_r=0;
  for (int i=1;i<27;++i) {
    if (position[i].empty()) {
      dp[i][0]=dp[i-1][0];
      dp[i][1]=dp[i-1][1];
      continue;
    }
    int dist=abs(position[i].front()-position[i].back());
    int size=static_cast<int>(position[i].size());

    dp[i][0]=std::min(
      dp[i-1][0]+size+dist+abs(position[i].back()-pos_l),
      dp[i-1][1]+size+dist+abs(position[i].back()-pos_r)
    );
    dp[i][1]=std::min(
      dp[i-1][0]+size+dist+abs(position[i].front()-pos_l),
      dp[i-1][1]+size+dist+abs(position[i].front()-pos_r)
    );
    pos_l=position[i].front();
    pos_r=position[i].back();
  }
  std::cout << std::min(dp[26][0], dp[26][1]);
  
  return 0;
}