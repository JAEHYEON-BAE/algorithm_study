// 31649

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF = (~0u) >> 2;

long long int DFS(int node, const std::string &s, const std::vector<long long int> &v, const int &n)
{
  int left=(n+node-1)%n, right=(node+1)%n;
  if (s[left]=='R' && s[right]=='L') return 0;
  else if (s[node]=='L') return v[node]+DFS(left, s, v, n);
  else if (s[node]=='R') return v[node]+DFS(right, s, v, n);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n; long long int m;  std::cin >> n >> m;
  std::string s;  std::cin >> s;
  long long int total=0;
  std::vector<long long int> v(n);
  for (int i=0;i<n;++i) {std::cin >> v[i]; total+=v[i];}
  
  std::vector<int> leaves;
  for (int curr=0;curr<n;++curr) {
    int left=(n+curr-1)%n, right=(curr+1)%n;
    if (s[left]=='L' && s[right]=='R') leaves.push_back(curr);
  }
  for (int leaf:leaves) {
    long long int tmp=DFS(leaf, s, v, n);
    total-=std::min(tmp, m);
  }
  std::cout << total;
  
  return 0;
}