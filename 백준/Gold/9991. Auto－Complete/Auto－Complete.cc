// 9991

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);

std::string next(const std::string& s) {
  std::string result=s;
  while (result.back()=='z') {
    result.pop_back();
  }
  if (result.size()==0) return s;
  else {
    result.back()++;
    return result;
  }
}

bool is_prefix(const std::string &a, const std::string &p) 
{
  if (a.size()<p.size()) return false;
  for (int i=0;i<p.size();++i) {
    if (a[i]!=p[i]) return false;
  }
  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int w, n;  std::cin >> w >> n;
  std::vector<std::string> dict(w);
  std::unordered_map<std::string, int> map;
  for (int i=0;i<w;++i) {
    std::cin >> dict[i];
    map[dict[i]]=i;
  }
  std::sort(dict.begin(), dict.end());

  int i;  std::string s;
  while (n--) {
    std::cin >> i >> s;
    auto idx=std::lower_bound(dict.begin(), dict.end(), s);
    if (std::distance(dict.begin(), idx)>w-i) std::cout << "-1\n";
    else {
      std::string result=*(idx+i-1);
      if (!is_prefix(result, s)) std::cout << "-1\n";
      else std::cout << 1+map[result] << '\n';
    }
  }
  return 0;
}