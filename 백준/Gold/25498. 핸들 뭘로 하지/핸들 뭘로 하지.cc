// 25498

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::string s;  std::cin >> s;
  std::vector<std::vector<int>> map(n);
  
  for (int i=0;i<n-1;++i) {
    int u, v;  std::cin >> u >> v;
    --u;  --v;
    map[u].push_back(v);
    map[v].push_back(u);
  }

  std::queue<int> q;
  std::vector<bool> visited(n, 0);

  q.push(0);
  visited[0]=1;

  std::string result="";
  
  while (!q.empty()) {
    char max='a'-1;
    int tmp;
    while (!q.empty()) {
      int curr=q.front(); q.pop();
      if (s[curr]>max) {
        max=s[curr];
        tmp=curr;
      }
      else if (s[curr]==max) {
        map[tmp].insert(map[tmp].end(), map[curr].begin(), map[curr].end());
      }
    }
    result.push_back(max);
    for (int &next:map[tmp]) if (!visited[next]) {
      visited[next]=1;
      q.push(next);
    }
  }
  std::cout << result;
  return 0;
}