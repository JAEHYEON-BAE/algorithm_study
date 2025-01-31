// 5639
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

void print(std::vector<int>::iterator left, std::vector<int>::iterator right) 
{
  if (left>=right) return;
  std::vector<int>::iterator mid = std::upper_bound(left+1, right, *left);
  print(left+1, mid);
  print(mid, right);
  std::cout << *left << '\n';
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int x;
  std::vector<int> v;
  while (std::cin >> x) v.push_back(x);
  print(v.begin(), v.end());  
  return 0; 
}
