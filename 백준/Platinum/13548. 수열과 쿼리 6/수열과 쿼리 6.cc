// 13548

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
  std::vector<int> cnt(100'001, 0);
  // cnt[i] = number of i s.t. s<=i<=e
  std::vector<int> table(100'001, 0);  
  // table[i] = number of X s.t. cnt[X]==i

  int max=0;
  auto add = [&cnt, &table, &max](const int& x) -> void {
    if (cnt[x]!=0) --table[cnt[x]];
    ++table[++cnt[x]];
    max=std::max(max, cnt[x]);
  };

  auto remove = [&cnt, &table, &max](const int& x) -> void {
    --table[cnt[x]];
    if (cnt[x]==max && table[cnt[x]]==0) --max;
    ++table[--cnt[x]];
  };

  int s=0,e=0;
  add(v[0]);
  std::vector<int> result(m);
  for (const Query& q: queries) {
    while (s<q.l) remove(v[s++]);
    while (s>q.l) add(v[--s]);
    while (e<q.r) add(v[++e]);
    while (e>q.r) remove(v[e--]);

    result[q.idx] = max;
  }
  for (int& x: result) std::cout << x << '\n';  
  return 0; 
}
