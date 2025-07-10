// 32178

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  // using namespace fastio;

  int n;  
  // read(n);
  std::cin >> n;
  std::vector<std::pair<long long int, int>> sum(n+1);
  sum[0]={0LL, 0};
  
  for (int i=0;i<n;++i) {
    long long int x; 
    // read(x);
    std::cin >> x;
    sum[i+1]={sum[i].first+x, i+1};
  }
  std::sort(sum.begin(), sum.end());


  long long int min=(~0uLL)>>1;
  long long int answer=min;
  int l=-1, r=-1;
  for (int i=0;i<n;++i) {
    long long int diff=std::abs(sum[i+1].first-sum[i].first);
    if (min>std::abs(diff)) {
      l=std::min(sum[i+1].second, sum[i].second)+1;
      r=std::max(sum[i+1].second, sum[i].second);
      min=std::abs(diff);
      if (sum[i+1].second>sum[i].second) answer=diff;
      else answer=-diff;
    }
  }
  std::cout << answer << '\n' << l << ' ' << r;
  
  return 0;
}