// 17925

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl


bool Compare(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
{
  if (a.second==b.second) return a.first<b.first;
  return a.second>b.second;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::string word;
  int x;

  std::vector<std::pair<std::string, int>> categories(n);
  std::vector<std::unordered_set<std::string>> mapp(n);
  for (int i=0;i<n;++i) {
    std::cin >> categories[i].first >> x;
    categories[i].second=0;
    while (x--) {
      std::cin >> word;
      mapp[i].insert(word);
    }
  }
  while (std::cin >> word) {
    for (int i=0;i<n;++i) {
      if (mapp[i].find(word)!=mapp[i].end()) {
        ++categories[i].second;
      }
    }
  }
  std::sort(categories.begin(), categories.end(), Compare);

  int max=categories[0].second;
  for (auto x: categories) {
    if (x.second<max) return 0;
    std::cout << x.first << '\n';
  }
  return 0;
}