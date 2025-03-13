// 31910

#include <iostream>
#include <vector>
#include <bitset>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

long long int DFS(int node, int depth, std::vector<long long int> &dp, const std::bitset<900> &map, const int &n)
{
  if (depth==0) return map[node];
  if (dp[node]!=-1) return dp[node];
  int r=node/n, c=node%n;
  long long int down=-1, right=-1;
  if (r<n-1) down=DFS(node+n, depth-1, dp, map, n);
  if (c<n-1) right=DFS(node+1, depth-1, dp, map, n);

  long long int tmp=0;
  if (map[node]) tmp=1LL<<depth;
  return dp[node]=(tmp)+std::max(down, right);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::bitset<900> map;
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    int x; std::cin >> x;
    map[i*n+j]=x;
  }

  std::vector<long long int> dp(n*n, -1);
  std::cout << DFS(0, n+n-2, dp, map, n);
   
  return 0;
}