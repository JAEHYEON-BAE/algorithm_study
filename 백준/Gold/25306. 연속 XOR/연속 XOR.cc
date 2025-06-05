// 25306

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

inline long long int cnt(long long int n)
{
  if (n%4==0) return n;
  else if (n%4==1) return 1;
  else if (n%4==2) return n+1;
  else return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  long long int a, b;  std::cin >> a >> b;
  std::cout << (cnt(b) ^ cnt(a-1));
  return 0;
}