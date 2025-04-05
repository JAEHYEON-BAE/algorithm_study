// 11003
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, l;  std::cin >> n >> l;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
  for (int i=0;i<l;++i) {
    pq.push({v[i], i});
    std::cout << pq.top().first << ' ';
  }
  for (int i=l;i<n;++i) {
    while (!pq.empty() && pq.top().second<=i-l) pq.pop();
    pq.push({v[i], i});
    std::cout << pq.top().first << ' ';
  }

 
  return 0;
}