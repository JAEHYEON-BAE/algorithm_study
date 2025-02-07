// 20191

#include <iostream>
#include <vector>
#include <string>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>1;

bool find(const std::string &s, const std::string &t, const int &n) {
  int s_idx=0, t_idx=0;
  int t_cnt=1;
  while (s_idx<s.size()) {
    if (t_idx==t.size()) {
      ++t_cnt;
      if (t_cnt>n) return false;
      t_idx=0;
    }
    if (s[s_idx]==t[t_idx]) ++s_idx;
    ++t_idx;
  }
  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s, t;
  std::cin >> s >> t;

  std::vector<bool> used(26, false);
  for (const char &c: t) used[c-'a']=true;
  for (const char &c: s) if (!used[c-'a']) {
    std::cout << -1;
    return 0;
  }

  int l=1, r=s.size();
  while (l<r) {
    int mid=(l+r)/2;
    if (find(s, t, mid)) {
      r=mid;
    } else {
      l=mid+1;
    }
  }
  std::cout << l;
 
  return 0; 
}