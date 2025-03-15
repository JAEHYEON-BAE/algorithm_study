// 28361

#include <iostream>
#include <vector>
#include <bitset>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> route_0={0}, route_1={0};
  
  // route 0:
  route_0.push_back(1);
  route_0.push_back(3);
  route_0.push_back(2);
  int curr=2;
  while (1) {
    if ((curr+1)%n==0) {
      route_0.push_back(0);
      break;
    }
    curr+=2; curr%=n;
    route_0.push_back(curr);
    if (curr==0) break;
    if ((curr+1)%n==0) {
      route_0.push_back(0);
      break;
    }
    else {
      curr+=2; curr%=n;
      route_0.push_back(curr);
      curr-=1; curr%=n;
      route_0.push_back(curr);
    }
  }

  // route_1:
  route_1.push_back(2);
  route_1.push_back(1);
  curr=1;
  while (1) {
    if ((curr+1)%n==0) {
      route_1.push_back(0);
      break;
    }
    
    curr+=2; curr%=n;
    route_1.push_back(curr);
    if (curr==0) break;
    
    if ((curr+1)%n==0) {
      route_1.push_back(0);
      break;
    }
    
    curr+=2; curr%=n;
    route_1.push_back(curr);
    curr-=1; curr%=n;
    route_1.push_back(curr);
  }

  if (route_0.size()<route_1.size()) {
    std::cout << route_0.size()-1 << '\n';
    for (int x:route_0) std::cout << x+1 << ' ';
  }
  else {
    std::cout << route_1.size()-1 << '\n';
    for (int x:route_1) std::cout << x+1 << ' ';
  }
  
  
  return 0;
}