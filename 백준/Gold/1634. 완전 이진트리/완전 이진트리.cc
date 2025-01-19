// 1634

#include <iostream>
#include <vector>
#include <algorithm>

int dnq(const int& k, const std::vector<int>& t1, const std::vector<int>& t2, int depth, int start, int end, int l, int r) 
{
  if (depth==k) return t1[l]==t2[start];
  int mid = (start+end)/2;
  int c = (l+r)/2;
  return std::max(
    dnq(k, t1, t2, depth+1, start, mid, l, c)
    +dnq(k, t1, t2, depth+1, mid+1, end, c+1, r),
    dnq(k, t1, t2, depth+1, mid+1, end, l, c)
    +dnq(k, t1, t2, depth+1, start, mid, c+1, r)
  );
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int k;  std::cin >> k;
  int n = 1<<(k-1);
  std::vector<int> t1(n), t2(n);
  for (int i=0;i<n;++i) std::cin >> t1[i];
  for (int i=0;i<n;++i) std::cin >> t2[i];

  std::cout << dnq(k, t1, t2, 1, 0, n-1, 0, n-1);  
  return 0;  
}
