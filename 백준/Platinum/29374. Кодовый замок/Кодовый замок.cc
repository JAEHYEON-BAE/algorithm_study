// 29374

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  std::vector<int> a(n), b;
  for (int &x:a) std::cin >> x;
  for (int &x:a) if (x<=a.back()) b.push_back(x);
  

  std::vector<int> lis;
  for (int &x:b) {
    int pos=std::upper_bound(lis.begin(), lis.end(), x)-lis.begin();
    if (pos>=lis.size()) lis.push_back(x);
    else lis[pos]=x;
  }

  std::cout << n-lis.size();
  return 0;
}