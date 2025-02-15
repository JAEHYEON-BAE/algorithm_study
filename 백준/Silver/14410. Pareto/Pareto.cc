// 14410

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<long double> v(n);
  long double total=0;
  for (int i=0;i<n;++i) {std::cin >> v[i]; total+=v[i];}
  std::sort(v.begin(), v.end(), std::greater<int>());
  std::pair<long double, long double> answer={0.0, 0.0};

  long double sum=0;
  long double diff=0.0;

  for (int i=0;i<n;++i) {
    sum+=v[i];
    long double a=static_cast<long double>(i+1)*100.0/n;
    long double b=sum*100.0/total;
    if (diff<b-a) {
      answer.first=a; answer.second=b;
      diff=b-a;
    } else break;
  }
  std::cout << std::fixed << std::setprecision(10) << answer.first << '\n' << answer.second;
  
  return 0; 
}