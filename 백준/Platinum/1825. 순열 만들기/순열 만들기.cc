// 1825

#include <iostream>
#include <vector>
#include <algorithm>

void sol1(const int& n, const int& m, const int& k, std::vector<int>& front)
{
  int x = std::min(k, n-m+1);
  for (int i=n-x+1;i<=n;++i) {
    front.push_back(i);
  }
  if (n-x<=0) return;
  sol1(n-x, m-1, k, front);
}

void sol2(const int& n, const int& s, const int& m, const int& k, std::vector<int>& back)
{
  int x = std::min(m, n-s+1-k+1);
  for (int i=s+x-1;i>=s;--i) {
    back.push_back(i);
  }
  if (s+x>n) return;
  sol2(n, s+x, m, k-1, back);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m, k;  std::cin >> n >> m >> k;

  if (m+k>n+1 || static_cast<long long>(m)*k<static_cast<long long>(n)) {
    std::cout << -1;
    return 0;
  }

  std::vector<int> front, back;
  sol1(n, m, k, front);
  sol2(n, 1, m, k, back);

  for (int i=n-1;i>=0;--i) {
    std::cout << front[i] << ' ';
  }
  std::cout << '\n';
  for (int i=n-1;i>=0;--i) {
    std::cout << back[i] << ' ';
  }
}

