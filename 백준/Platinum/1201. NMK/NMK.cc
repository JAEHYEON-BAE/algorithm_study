// 1201

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m, k;  std::cin >> n >> m >> k;

  if (m+k>n+1 || n>m*k) {
    std::cout << "-1";
    return 0;
  }
  if (m==1) {
    if (k==n) for (int i=n;i>0;--i) std::cout << i << ' ';
    else std::cout << "-1";
    return 0;
  }
  if (k==1) {
    if (m==n) for (int i=1;i<=n;++i) std::cout << i << ' ';
    else std::cout << "-1";
    return 0;
  }

  std::vector<int> boxes(m-1, 0);
  int b=0;
  for (int i=0;i<n-k;++i, b=(b+1)%(m-1)) {
    ++boxes[b];
  }

  for (int i=k;i>0;--i) std::cout << i << ' ';
  int tmp=k;
  for (const int &size:boxes) {
    for (int i=tmp+size;i>tmp;--i) std::cout << i << ' ';
    tmp+=size;
  }
  return 0;
}

