// 34117

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, p;  std::cin >> n >> p;
  std::priority_queue<int, std::vector<int>, std::greater<>> pq;

  int sum=0;
  for (int i=0;i<n;++i) {
    int x;  std::cin >> x;
    pq.push(x);
    sum+=x;
    while (!pq.empty() && sum-pq.top()>=p) {
      sum-=pq.top();
      pq.pop();
    }
    std::cout << (sum<p?-1:static_cast<int>(pq.size())) << ' ';
  }
  
  return 0;
}