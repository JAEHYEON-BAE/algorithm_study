// 2632

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <unordered_map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int p;  std::cin >> p;
  int m, n;  std::cin >> m >> n;
  std::vector<int> a(m), b(n);
  std::unordered_map<int, int> suma, sumb;
  int total=0;
  for (int i=0;i<m;++i) {
    std::cin >> a[i];
    total+=a[i];
  }
  suma[total]=1;
  total=0;
  for (int i=0;i<n;++i) {
    std::cin >> b[i];
    total+=b[i];
  }
  sumb[total]=1;

  for (int len=1;len<m;++len) {
    int sum=0;
    for (int i=0;i<len;++i) sum+=a[i];
    ++suma[sum];
    for (int i=len;i<m+len-1;++i) {
      sum=sum-a[(i-len)%m]+a[i%m];
      ++suma[sum];
    }
  }
  for (int len=1;len<n;++len) {
    int sum=0;
    for (int i=0;i<len;++i) sum+=b[i];
    ++sumb[sum];
    for (int i=len;i<n+len-1;++i) {
      sum=sum-b[(i-len)%n]+b[i%n];
      ++sumb[sum];
    }
  }

  int cnt=0;
  for (auto &x:suma) {
    if (x.first>=p) continue;
    else if (sumb.find(p-x.first)!=sumb.end()) {
      cnt+=x.second * sumb[p-x.first];
    }
  }
  if (suma.find(p)!=suma.end()) cnt+=suma[p];
  if (sumb.find(p)!=sumb.end()) cnt+=sumb[p];
  
  std::cout << cnt;

  return 0;
}