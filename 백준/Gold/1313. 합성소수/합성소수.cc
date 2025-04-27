// 1313

#include <iostream>
#include <vector>
#include <algorithm>

static constexpr int _p[]={
111,
117,
119,
171,
231,
237,
297,
319,
371,
411,
413,
417,
437,
471,
473,
531,
537,
597,
611,
671,
679,
711,
713,
717,
731,
737,
831,
837,
897,
973,
979,
1131,
1137,
1311,
1313,
1317,
1379,
1797,
1971,
3113,
3131,
3173,
3179,
4197,
4311,
4313,
4317,
4797,
6137,
6179,
7197,
7971,
31373
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  /** pre-processing
  
  std::vector<bool> is_prime(10'000'000, 1);
  is_prime[0]=is_prime[1]=0;
  for (int i=2;i*i<=10'000'000;++i) {
    if (is_prime[i]) for (int j=i<<1;j<=10'000'000;j+=i) {
      is_prime[j]=0;
    }
  }

  for (int i=100;i<=10'000'000;++i) {
    if (is_prime[i]) continue;
    std::string s=std::to_string(i);
    bool FLAG=1;
    for (int len=2;len<s.size();++len) {
      for (int start=0;start+len<=s.size();++start) {
        if (!is_prime[std::stoi(s.substr(start, len))]) {
          FLAG=0;
          break;
        }
      }
      if (!FLAG) break;
    }
    if (FLAG) std::cout << i << '\n';
  }
  
  */

  int t;  std::cin >> t;
  while (t--) {
    int n;  std::cin >> n;
    if (_p[0]>n) std::cout << -1 << '\n';
    else std::cout << *(std::upper_bound(_p, _p+53, n)-1) << '\n';
  }
  
  return 0;
}