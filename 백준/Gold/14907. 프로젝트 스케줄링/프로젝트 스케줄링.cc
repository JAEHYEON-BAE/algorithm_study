// 1766

#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>1;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string line;
  std::vector<std::vector<int>> parents(26);
  std::vector<std::vector<int>> children(26);
  std::vector<int> in_degree(26, 0);
  std::vector<int> times(26);
  while (std::getline(std::cin, line)) {
    std::stringstream ss(line);
    std::string word;
    int k=0;
    int work;
    int time;
    while (ss>>word) {
      if (k==0) work=word[0]-'A';
      else if (k==1) time=std::stoi(word);
      else if (k==2) {
        for (int i=0;i<word.size();++i) {
          parents[work].emplace_back(word[i]-'A');
          children[word[i]-'A'].push_back(work);
          ++in_degree[work];
        }
      }
      ++k;
    }    
    times[work]=time;
  }
  std::queue<int> q;
  std::vector<int> dp(26, 0);
  for (int i=0;i<26;++i) {
    if (in_degree[i]==0) {
      q.push(i);
      dp[i]=times[i];
    }
  }
  while (!q.empty()) {
    int curr=q.front();
    q.pop();
    for (const int &parent: parents[curr]) {
      dp[curr]=std::max(dp[curr], dp[parent]+times[curr]);
    }
    for (const int &child: children[curr]) {
      if (--in_degree[child]==0) {
        q.push(child);
      }
    }
  }
  std::cout << *std::max_element(dp.begin(), dp.end());

  return 0; 
}
