// 1655

#include <iostream>
#include <queue>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>1;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  int x;
  std::priority_queue<int> pq_small;  /* smaller than median */
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq_big;  /* bigger than median */
  
  while (n--) {
    std::cin >> x;
    if (pq_small.empty() || x<=pq_small.top()) {
      pq_small.push(x);
    } else {
      pq_big.push(x);
    }

    if(pq_small.size() > pq_big.size()+1) {
      pq_big.push(pq_small.top());
      pq_small.pop();
    } else if(pq_big.size() > pq_small.size()) {
      pq_small.push(pq_big.top());
      pq_big.pop();
    }

    std::cout << pq_small.top() << '\n';
  }

  return 0; 
}
