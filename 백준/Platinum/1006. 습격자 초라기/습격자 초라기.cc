// 1006

#include <iostream>
#include <vector>
#include <algorithm>

inline int min(const int& a, const int& b) 
{
  return std::min(a, b);
}

inline int min(const int& a, const int& b, const int& c) 
{
  return std::min(a, std::min(b, c));
}

inline int min(const int& a, const int& b, const int& c, const int& d)
{
  return std::min(std::min(a, b), std::min(c, d));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  const int INF = (~0u)>>2;

  int t, w, n;  std::cin >> t;
  std::vector<int> v;
    
  auto solve = [&v, &w, &n](std::vector<std::vector<int>>& _dp, const int range) -> int {

    // std::cout << '\n';
    // for (int i=0;i<5;++i) {
    //   std::cout << "_dp[0][" << i << "] = " << _dp[0][i] << std::endl;
    // }

    for (int i=1;i<range;++i) {
      _dp[i][0] = 2+*std::min_element(_dp[i-1].begin(), _dp[i-1].end());
      if (v[i]+v[n+i]<=w) _dp[i][4] = _dp[i][0]-1;
      
      if (v[i]+v[i-1]<=w) {
        _dp[i][1] = 1+std::min(_dp[i-1][0], _dp[i-1][2]);
      } 
      if (v[n+i]+v[n+i-1]<=w) {
        _dp[i][2] = 1+std::min(_dp[i-1][0], _dp[i-1][1]);

        if (v[i]+v[i-1]<=w) {
          _dp[i][3] = _dp[i-1][0];
        }
      }
      // std::cout << "\n_dp[" << i << "][0] = " << _dp[i][0] << std::endl;
      // std::cout << "_dp[" << i << "][1] = " << _dp[i][1] << std::endl;
      // std::cout << "_dp[" << i << "][2] = " << _dp[i][2] << std::endl;
      // std::cout << "_dp[" << i << "][3] = " << _dp[i][3] << std::endl;
      // std::cout << "_dp[" << i << "][4] = " << _dp[i][4] << std::endl;

      for (int j=0;j<5;++j) {
        if (_dp[i][j]>INF) {
          _dp[i][j] = INF;
        }
      }
    }
    return *std::min_element(_dp[range-1].begin(), _dp[range-1].end());
  };
  while (t--) {
    std::cin >> n >> w;
    v.resize(n<<1);
    for (int i=0;i<v.size();++i) std::cin >> v[i];

    if (n==1) {
      if (v[0]+v[1]<=w) std::cout << '1';
      else std::cout << '2';
      std::cout << '\n';
      continue;
    }


    int tmp = INF;

    // std::cout << "CHECKPOINT #1: tmp = " << tmp << std::endl;
    
    std::vector<std::vector<int>> _dp(n, std::vector<int>(5, INF));
    
    _dp[0][0] = 2;  if (v[0]+v[n]<=w)  _dp[0][4]=1;
    tmp = std::min(tmp, solve(_dp, n));

    for (auto &r: _dp) r.assign(5, INF);

    // std::cout << "CHECKPOINT #2: tmp = " << tmp << std::endl;

    if (v[0]+v[n-1]<=w) {
      _dp[0][1] = 2;
      solve(_dp, n-1);
      if (v[n*2-1]+v[n*2-2]<=w) _dp[n-1][2]=std::min(_dp[n-2][0], _dp[n-2][1]);
      else {
        _dp[n-1][0] = 1+*std::min_element(_dp[n-2].begin(), _dp[n-2].end());
      }
      tmp = std::min(tmp, std::min(_dp[n-1][0], _dp[n-1][2]));      
    }

    for (auto &r: _dp) r.assign(5, INF);

    // std::cout << "CHECKPOINT #3: tmp = " << tmp << std::endl;


    if (v[n]+v[n*2-1]<=w) {
      _dp[0][2] = 2;
      solve(_dp, n-1);
      if (v[n-1]+v[n-2]<=w) _dp[n-1][1]=std::min(_dp[n-2][0], _dp[n-2][2]);
      else {
        _dp[n-1][0] = 1+*std::min_element(_dp[n-2].begin(), _dp[n-2].end());
      }
      tmp = std::min(tmp, std::min(_dp[n-1][0], _dp[n-1][1])); 
    }

    for (auto &r: _dp) r.assign(5, INF);

    // std::cout << "CHECKPOINT #4: tmp = " << tmp << std::endl;


    if (v[0]+v[n-1]<=w && v[n]+v[n*2-1]<=w) {
      _dp[0][3] = 2;
      tmp = std::min(tmp, solve(_dp, n-1));
    }

    std::cout << tmp << '\n';
  }
}
