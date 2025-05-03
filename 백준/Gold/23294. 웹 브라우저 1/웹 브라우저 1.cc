// 23294

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <stack>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, q, c;  std::cin >> n >> q >> c;
  std::vector<int> cap(n);
  for (int i=0;i<n;++i) std::cin >> cap[i];

  std::deque<int> bwd, fwd;
  int size=0;
  int curr=-1;
  while (q--) {
    assert(size<=c);
    char cmd;  std::cin >> cmd;
    if (cmd=='A') {
      int x;  std::cin >> x;
      --x;
      
      while (!fwd.empty()) {
        assert(0<=fwd.back() && fwd.back()<n);
        
        size-=cap[fwd.back()];
        fwd.pop_back();
      }
      if (curr!=-1) {
        assert(0<=curr && curr<n);
        bwd.push_back(curr);
      }
      curr=x;
      
      assert(0<=curr && curr<n);
      size+=cap[curr];

      while (size>c) {
        assert(0<=bwd.front() && bwd.front()<n);
        size-=cap[bwd.front()];
        bwd.pop_front();
      }
    }
    else if (cmd=='B') {
      if (bwd.empty() || curr<0) continue;
      assert(0<=curr && curr<n);
      fwd.push_back(curr);
      curr=bwd.back();
      bwd.pop_back();
    }
    else if (cmd=='F') {
      if (fwd.empty() || curr<0) continue;
      assert(0<=curr && curr<n);
      bwd.push_back(curr);
      curr=fwd.back();
      fwd.pop_back();
    }
    else if (cmd=='C') {
      std::stack<int> tmp;

      while (!bwd.empty()) {
        int k=bwd.back();
        if (tmp.empty() || tmp.top()!=k) {
          assert(0<=k && k<n);
          tmp.push(k);
          size+=cap[k];
        }
        bwd.pop_back();
        size-=cap[k];
      }

      while (!tmp.empty()) {
        assert(0<=tmp.top() && tmp.top()<n);
        bwd.push_back(tmp.top());
        tmp.pop();
      }
    }
    // std::cout << "BWD:\t";
    // for (auto x:bwd) std::cout << x << ' ';
    // std::cout << std::endl;
    // std::cout << "CURR:\t" << curr << '\n';
    // std::cout << "FWD:\t";
    // for (auto x:fwd) std::cout << x << ' ';
    // std::cout << std::endl;
    // std::cout << "SIZE:\t" << size << '\n' << '\n';
  }
  std::cout << 1+curr << '\n';
  if (bwd.empty()) std::cout << -1;
  else while (!bwd.empty()) {
    int k=1+bwd.back(); bwd.pop_back();
    std::cout << k << ' ';
  }
  std::cout << '\n';
  if (fwd.empty()) std::cout << -1;
  else while (!fwd.empty()) {
    int k=1+fwd.back(); fwd.pop_back();
    std::cout << k << ' ';
  }
  std::cout << '\n';
  
  return 0;
}