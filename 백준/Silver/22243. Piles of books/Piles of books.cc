// 22243

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> height(n*n);
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) std::cin >> height[i*n+j];
  
  int cnt=n*n;
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    int h=height[i*n+j];
    if (h==0) {
      --cnt;  continue;
    }
    if (i==0 || i==n-1 || j==0 || j==n-1) continue;
    bool x_prev=true, x_post=true, y_prev=true, y_post=true;
    for (int k=0;k<i;++k) {
      if (height[k*n+j]>=h) {x_prev=false; break;}
    }
    if (x_prev) continue;
    for (int k=i+1;k<n;++k) {
      if (height[k*n+j]>=h) {x_post=false; break;}
    }
    if (x_post) continue;
    for (int k=0;k<j;++k) {
      if (height[i*n+k]>=h) {y_prev=false; break;}
    }
    if (y_prev) continue;
    for (int k=j+1;k<n;++k) {
      if (height[i*n+k]>=h) {y_post=false; break;}
    }
    if (y_post) continue;

    --cnt;
  }
  std::cout << cnt;
 
  return 0;
}