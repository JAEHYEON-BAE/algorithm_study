// 11866

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  std::vector<bool> used(n, 0);
  std::vector<int> result;

  int idx=0;
  while (result.size()<n) {
    for (int d=0;d<k-1;++d) {
      idx=(idx+1)%n;
      while (used[idx]) idx=(idx+1)%n;
    }
    result.push_back(idx);
    used[idx]=1;
    idx=(idx+1)%n;
    if (result.size()==n) break;
    while (used[idx]) idx=(idx+1)%n;
  }
  std::cout << '<';
  for (int i=0;i<n-1;++i) {
    std::cout << result[i]+1 << ',' << ' ';
  }
  std::cout << result[n-1]+1 << '>';
  return 0;
}