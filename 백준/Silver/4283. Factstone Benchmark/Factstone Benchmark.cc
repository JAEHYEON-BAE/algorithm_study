// 4283

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  
  std::vector<long double> log_factorial={0, 0};
  // std::cout << log_factorial[1] << '\n';
  for (int i=2;;++i) {
    long double tmp=log_factorial[i-1]+log2(i);
    if (log2(tmp)>22) break;
    log_factorial.push_back(tmp);
    // std::cout << log_factorial[i] << '\n';
  }
  

  int year;
  while (std::cin >> year) {
    if (!year) break;
    int k=1<<((year-1960)/10+2);
    // DEBUG(k);

    std::cout << std::distance(log_factorial.begin(), std::lower_bound(log_factorial.begin(), log_factorial.end(), k)) -1 << '\n';
  }

  return 0;
}