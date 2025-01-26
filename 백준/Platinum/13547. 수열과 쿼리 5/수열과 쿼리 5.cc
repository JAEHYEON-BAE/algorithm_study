// 13547

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int sqrt_n;
struct Query
{
  int idx, l, r;

  bool operator<(const Query& other) const {
    if (l/sqrt_n==other.l/sqrt_n) return r<other.r;
    return l/sqrt_n<other.l/sqrt_n;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  sqrt_n = std::sqrt(n);
  
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];
  
  int m;  std::cin >> m;
  std::vector<Query> queries(m);
  
  for (int i=0;i<m;++i) {
    queries[i].idx=i;
    std::cin >> queries[i].l >> queries[i].r;
    --queries[i].l;  --queries[i].r;
  }

  std::sort(queries.begin(), queries.end());
  std::vector<int> cnt(1'000'001, 0);
  // cnt[i] = number of i s.t. s<=i<=e

  int result=0;
  auto add = [&cnt, &result](const int& x) -> void {
    if (cnt[x]++==0) ++result;
  };

  auto remove = [&cnt, &result](const int& x) -> void {
    if (--cnt[x]==0) --result;
  };

  int s=0,e=0;
  add(v[0]);
  std::vector<int> results(m);
  for (const Query& q: queries) {
    while (s<q.l) remove(v[s++]);
    while (s>q.l) add(v[--s]);
    while (e<q.r) add(v[++e]);
    while (e>q.r) remove(v[e--]);

    results[q.idx] = result;
  }
  for (int& x: results) std::cout << x << '\n';  
  return 0; 
}
