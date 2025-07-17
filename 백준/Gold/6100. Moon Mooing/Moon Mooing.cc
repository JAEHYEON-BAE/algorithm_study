// 6100

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  long long int c, n;  std::cin >> c >> n;
  long long int a1, b1, d1;  std::cin >> a1 >> b1 >> d1;
  long long int a2, b2, d2;  std::cin >> a2 >> b2 >> d2;

  auto f1=[&](long long int x) -> long long int {
    return static_cast<long long int>(static_cast<__int128>(a1)*x/d1+b1);
  };
  auto f2=[&](long long int x) -> long long int {
    return static_cast<long long int>(static_cast<__int128>(a2)*x/d2+b2);
  };


  std::vector<long long int> v;
  v.push_back(c);

  int i=0, j=0;
  while (v.size()<n) {
    long long int n1=f1(v[i]);
    long long int n2=f2(v[j]);

    long long int next;
    if (n1<n2) {
      next=n1;
      ++i;
    }
    else if (n1>n2) {
      next=n2;
      ++j;
    }
    else {
      next=n1;
      ++i;++j;
    }
    if (next>v.back()) v.push_back(next);
  }
  std::cout << v.back();
  return 0;
}