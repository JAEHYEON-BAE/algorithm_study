// 10958

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n; long long int m;
  std::cin >> n >> m;
  std::vector<long long int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];
  std::sort(v.begin(), v.end());
  while (!v.empty() && v.back()>m) v.pop_back();
  n=v.size();

  int left_size=n>>1, right_size=(n+1)>>1;
  std::vector<long long int> left_sum(1<<left_size), right_sum(1<<right_size);
  
  for (int bit=0;bit<(1<<left_size);++bit) {
    long long int sum=0;
    for (int i=0;i<left_size;++i) if (bit&(1<<i)) sum+=v[i];
    left_sum[bit]=sum;
  }
  std::sort(left_sum.begin(), left_sum.end());
  
  for (int bit=0;bit<(1<<right_size);++bit) {
    long long int sum=0;
    for (int i=0;i<right_size;++i) if (bit&(1<<i)) sum+=v[i+left_size];
    right_sum[bit]=sum;
  }
  std::sort(right_sum.begin(), right_sum.end());

  long long int cnt=0LL;
  for (const long long int &l:left_sum) {
    long long int pos=std::upper_bound(right_sum.begin(), right_sum.end(), m-l) - right_sum.begin();
    cnt+=pos;
  }

  std::cout << cnt;
  return 0;
}