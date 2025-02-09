// 1099

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;

inline bool able(std::string word1, std::string word2)
{
  std::sort(word1.begin(), word1.end());
  std::sort(word2.begin(), word2.end());
  return word1==word2;
}
inline int cost(const std::string &word1, const std::string &word2)
{
  if (!able(word1, word2)) return -1;
  int x=0;
  for (int i=0;i<word1.size();++i) {
    if (word1[i]!=word2[i]) ++x;
  }
  return x;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string line;  int n;  
  std::cin >> line >> n;
  std::vector<std::string> words(n);
  for (int i=0;i<n;++i) std::cin >> words[i];

  std::vector<std::vector<int>> dp(line.size(), std::vector<int>(line.size(), INF));
  for (int i=0;i<line.size();++i) {
    for (int j=0;j<=i;++j) {
      std::string tmp=line.substr(j, i-j+1);
      for (const std::string &word:words) {
        int x=cost(word, tmp);
        if (x!=-1) {
          if (j==0) dp[i][j]=std::min(dp[i][j], x);
          else {
            dp[i][j]=std::min(dp[i][j], x+*std::min_element(dp[j-1].begin(), dp[j-1].end()));     
          }
          if (dp[i][j]>INF) dp[i][j]=INF;
        }
      }
    }
  }
  int answer=*std::min_element(dp[line.size()-1].begin(), dp[line.size()-1].end());

  if (answer<INF) std::cout << answer;
  else std::cout << -1;
  
  return 0; 
}