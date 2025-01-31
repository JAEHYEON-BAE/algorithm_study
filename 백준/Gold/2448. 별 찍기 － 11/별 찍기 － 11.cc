// 2448
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

void star(int height, int mid, std::vector<std::vector<char>> &result, int k)
{
  if (k==0) { 
    result[height][mid]='*';
    result[height+1][mid-1]='*';
    result[height+1][mid+1]='*';
    result[height+2][mid-2]='*';
    result[height+2][mid-1]='*';
    result[height+2][mid]  ='*';
    result[height+2][mid+1]='*';
    result[height+2][mid+2]='*';
  }
  else { 
    star(height, mid, result, k-1);
    star(height+3*(1<<k-1), mid-3*(1<<k-1), result, k-1);
    star(height+3*(1<<k-1), mid+3*(1<<k-1), result, k-1);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::vector<char>> result(n, std::vector<char>(2*n-1, ' '));
  int k=0;
  n/=3;
  while (n>1) {
    n>>=1; ++k;
  }
  star(0, 3*(1<<k)-1, result, k);
  for (const auto& cv: result) {
    for (const char &c: cv) {
      std::cout << c;
    }
    std::cout << '\n';
  }

 
  return 0; 
}
