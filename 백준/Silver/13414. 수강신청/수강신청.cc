// 13414

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iomanip>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int k, l;  std::cin >> k >> l;
  std::vector<int> q(l, 0);
  std::vector<bool> _q(l, true);
  std::unordered_map<int, int> mapp;
  int x;
  for (int i=0;i<l;++i) {
    std::cin >> x;
    q[i]=x;
    if (mapp.find(x)==mapp.end()) {
      q[i]=x;
      mapp[x]=i;
    }
    else {
      _q[mapp[x]]=false;
      mapp[x]=i;
    }
  }
  int cnt=0;
  for (int i=0;i<l;++i) {
    if (_q[i]) {
      std::cout << std::setw(8) << std::setfill('0') << q[i] << '\n';
      ++cnt;
    }
    if (cnt==k) return 0;
  }
  return 0;
}