// 17135

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_set>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m, d;  std::cin >> n >> m >> d;
  std::bitset<225> map;
  for (int i=0;i<n;++i) for (int j=0;j<m;++j) {
    bool x;  std::cin >> x;
    map[i*m+j]=x;
  }
  std::vector<bool> archer(m);
  std::fill(archer.begin(), archer.begin()+3, 1);

  std::bitset<225> empty;
  for (int i=0;i<n*m;++i) {
    empty.set(i);
  }
  
  int max=0;
  
  do {
    // std::cout << "Archer:\t"; for (bool b:archer) std::cout << b << ' '; std::cout << std::endl;
    
    std::bitset<225> map_cpy=map;
    int cnt=0;
    std::bitset<225> kill;

    while ((map_cpy&empty)!=0) {
      // std::cout << "KILL " << cnt << " opps total\n";
      // for (int i=0;i<n;++i) {
      //   for (int j=0;j<m;++j) std::cout << map_cpy[i*m+j] << ' ';
      //   std::cout << '\n';
      // }
      // std::cout << std::endl;

      std::unordered_set<int> target;
      for (int k=0;k<m;++k) if (archer[k]) {
        bool FLAG=0;
        for (int dist=1;dist<=d;++dist) {
          for (int c=std::max(0, k-dist+1);c<=std::min(m-1, k);++c) {
            int r=n+k-dist-c;
            if (r<0 || r>=n*m) continue;
            if (map_cpy[r*m+c]) {
              target.insert(r*m+c);FLAG=1;
              // std::cout << "KILL " << r << ' ' <<  c << std::endl;
              break;
            }
          }
          if (FLAG) break;
          for (int c=k;c<=std::min(m-1, k+dist-1);++c) {
            int r=c-k+n-dist;
            if (r<0 || r>=n*m) continue;
            if (map_cpy[r*m+c]) {
              target.insert(r*m+c);FLAG=1;
              // std::cout << "KILL " << r << ' ' <<  c << std::endl;
              break;
            }
          }
          if (FLAG) break;
        }
      }
      for (int x:target) map_cpy.reset(x), ++cnt;

      map_cpy<<=m;
    }
    // std::cout << "Kill " << cnt << " opps.\n" << std::endl;
    
    max=std::max(max, cnt);
  } while (std::prev_permutation(archer.begin(), archer.end()));

  std::cout << max;
  
  return 0;
}