// 1410

#include <iostream>
#include <vector>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int s, n, m;  std::cin >> s >> n >> m;
  int u=0;
  for (int i=0;i<n+m;++i) {
    int x;  std::cin >> x;
    if (x) {
      ++u;
      if (u>s) s<<=1;
    }
    else {
      --u;
    }
  }
  std::cout << s;
  
  return 0;
}

