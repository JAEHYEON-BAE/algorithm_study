// 8462

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cmath>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int sqrtn;
struct Query
{
  int idx, l, r;
  bool operator<(const Query& other) {
    if (l/sqrtn==other.l/sqrtn) return r<other.r;
    return l/sqrtn < other.l/sqrtn;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, t;  std::cin >> n >> t;
  sqrtn=std::sqrt(n);
  std::vector<int64_t> v(n);
  std::vector<Query> queries(t);
  for (int i=0;i<n;++i) std::cin >> v[i];
  for (int i=0;i<t;++i) {
    std::cin >> queries[i].l >> queries[i].r;
    queries[i].idx=i; --queries[i].l; --queries[i].r;
  }

  std::sort(queries.begin(), queries.end());

  int cnt[1'000'001];
  memset(cnt, 0, sizeof(cnt));

  int64_t power=0;
  
  auto add = [&](int64_t x) -> void {
    power+=x*(static_cast<int64_t>(2)*cnt[x]+1);
    ++cnt[x];
  };
  auto remove = [&](int64_t x) -> void {
    power+=x*(1-static_cast<int64_t>(2)*cnt[x]);
    --cnt[x];
  };

  add(v[0]);

  std::vector<int64_t> results(t);
  int s=0, e=0;
  for (const Query& q: queries) {
    while (s<q.l) remove(v[s++]);
    while (s>q.l) add(v[--s]);
    while (e<q.r) add(v[++e]);
    while (e>q.r) remove(v[e--]);

    results[q.idx] = power;
  }

  for (const int64_t& r: results) std::cout << r << '\n';

  return 0; 
}
