// 3758

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

struct Info
{
  int id, tot_score=0, num=0, time=0;
  std::vector<int> scores;

  Info(int k): scores(k, 0) {}

  bool operator<(const Info &o) const
  {
    if (tot_score==o.tot_score) {
      if (num==o.num) return time<o.time;
      else return num<o.num;
    }
    else return tot_score>o.tot_score;
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int n, k, id, m; std::cin >> n >> k >> id >> m;
    --id;

    std::vector<Info> info(n, k);
    for (int i=0;i<n;++i) info[i].id=i;
    
    int i, j, s;  
    for (int t=0;t<m;++t) {
      std::cin >> i >> j >> s;
      --i, --j;
      if (info[i].scores[j]<s) {
        info[i].tot_score+=s-info[i].scores[j];
        info[i].scores[j]=s;
      }
      ++info[i].num;
      info[i].time=t;
    }

    std::sort(info.begin(), info.end());
    for (int i=0;i<n;++i) if (info[i].id==id) {
      std::cout << i+1 << '\n';
      break;
    }
  }
  return 0;
}
