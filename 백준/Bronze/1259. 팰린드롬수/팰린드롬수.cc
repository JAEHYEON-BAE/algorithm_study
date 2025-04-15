// 1039
#include <iostream>
#include <vector>

bool is_palin(const std::string &s)
{
  int n=s.size();
  for (int i=0;i<(n>>1);++i) {
    if (s[i]!=s[n-i-1]) return 0;
  }
  return 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  while (1) {
    std::string n;  std::cin >> n;
    if (n=="0") break;
    std::cout << (is_palin(n)?"yes\n":"no\n");
  }

  return 0;
}