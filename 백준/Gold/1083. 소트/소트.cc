// 1083

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, s;  std::cin >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];
  std::cin >> s;

  for (int pos=0;pos<n && s>0;++pos) {
    int max = pos;

    for (int i=pos;i<=std::min(n-1, pos+s);++i) {
      if (v[max]<v[i]) max = i;
    }
    for (int i=max;i>pos;--i) {
      std::swap(v[i], v[i-1]);
      --s;
    }
  }


  for (const int& x: v) std::cout << x << ' ';
}
