// 17779

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::vector<int>> a(n, std::vector<int>(n));
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    std::cin >> a[i][j];
  }

  int result=INF;
  for (int r=1;r<n-1;++r) for (int c=0;c<n-2;++c) {
    for (int d1=1;r-d1>=0 && c+d1<n;++d1) for (int d2=1;r+d2<n && c+d2<n && r-d1+d2>=0 && c+d1+d2<n;++d2) {
      int _1=0, _2=0, _3=0, _4=0, _5=0;
      for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
        if (i>=r-d1 && i<=r+d2 && j>=c && j<=c+d1+d2 && i+j>=r+c && i-j<=r-c && i+j<=r+c+2*d2 && i-j>=r-c-2*d1) _5+=a[i][j];
        else if (i<r && j<=c+d1 && i+j<r+c) _1+=a[i][j];
        else if (i<=r-d1+d2 && j>c+d1 && i-j<r-c-2*d1) _2+=a[i][j];
        else if (i>=r && j<c+d2 && i-j>r-c) _3+=a[i][j];
        else _4+=a[i][j];
      }

      int max=std::max({_1, _2, _3, _4, _5});
      int min=std::min({_1, _2, _3, _4, _5});

      result=std::min(result, max-min);
    }
  }
  std::cout << result;
  
  return 0;
}