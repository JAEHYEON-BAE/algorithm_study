// 14563

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <array>

enum class NT {
  Perfect,
  Deficient,
  Abundant
};

constexpr int sum(int x)
{
  if (x==1) return 0;
  int sum=0;
  for (int i=1;i*i<=x;++i) {
    if (x%i==0) {
      sum+=i;
      if (i!=1 && i*i!=x) sum+=x/i;
    }
  }
  return sum;
}
constexpr NT classify(int x)
{
  if (x==0) return NT::Deficient;
  int _sum=sum(x);
  if (_sum==x) return NT::Perfect;
  else if (_sum<x) return NT::Deficient;
  else return NT::Abundant;
}

constexpr std::array<NT, 10'001> gen_array()
{
  std::array<NT, 10'001> result{};
  for (int i=1;i<10'001;++i) result[i]=classify(i);
  return result;
}

constexpr std::array<NT, 10'001> result=gen_array();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t, n;  std::cin >> t;
  while (t--) {
    std::cin >> n;
    NT nt=result[n];
    if (nt==NT::Perfect) std::cout << "Perfect\n";
    else if (nt==NT::Deficient) std::cout << "Deficient\n";
    else std::cout << "Abundant\n";
  }

  return 0;
}