// 1231

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int c, d, m;  std::cin >> c >> d >> m;

  std::vector<std::vector<int>> v(c, std::vector<int>(d));
  for (int i=0;i<c;++i) for (int j=0;j<d;++j) {
    std::cin >> v[i][j];
  }

  int res=m;

  for (int t=0;t<d-1;++t) {
    int cash=res;

    // best[w]: t일에서 t+1일로 갈 때, 현금 w원으로 만들 수 있는 최대의 금액
    std::vector<int> best(cash+1, 0);

    for (int w=1;w<=cash;++w) {
      best[w]=best[w-1]+1;

      for (int i=0;i<c;++i) {
        int buy=v[i][t];
        if (w>=buy) best[w]=std::max(best[w], best[w-buy]+v[i][t+1]);
      }
    }

    res=best[cash];
  }
  std::cout << res;
  return 0;
}

