// 26224

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

struct Name 
{
  std::string first, last;

  std::string full() {
    return first+' '+last;
  }

  bool operator<(const Name& other) {
    if (last==other.last) return first<other.first;
    return last<other.last;
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<Name> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i].first >> v[i].last;
  std::sort(v.begin(), v.end());

  std::unordered_map<std::string, int> map;
  for (int i=0;i<n;++i) {
    map[v[i].full()]=i;
  }

  int q;  std::cin >> q;
  std::cin.ignore();
  std::string line;
  while (q--) {
    std::getline(std::cin, line);
    int idx=map.at(line);
    if (idx%3==0) {
      std::cout << v[idx+1].full() << '\n' << v[idx+2].full() << '\n';
    } else if (idx%3==1) {
      std::cout << v[idx-1].full() << '\n' << v[idx+1].full() << '\n';
    } else {
      std::cout << v[idx-2].full() << '\n' << v[idx-1].full() << '\n';
    }
  }  
  return 0; 
}
