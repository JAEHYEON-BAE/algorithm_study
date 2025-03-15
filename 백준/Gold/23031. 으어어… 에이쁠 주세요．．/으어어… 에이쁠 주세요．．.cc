// 23031

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

const int mv_r[4]={1, 0, -1, 0};
const int mv_c[4]={0, -1, 0, 1};

struct Zombie
{
  int r, c;
  bool down=true;

  Zombie(int r, int c): r(r), c(c) {}
};

bool move(const int &dir, std::vector<Zombie> &zombies, std::vector<std::bitset<15>> &switches, std::vector<std::bitset<15>> &light, const bool &mv, const int &n) 
{
  static std::pair<int, int> ARI={0, 0};

  int &r=ARI.first, &c=ARI.second;
  if (mv) {
    r+=mv_r[dir];
    c+=mv_c[dir];
  
    if (r<0) r=0;
    if (r>n-1) r=n-1;
    if (c<0) c=0;
    if (c>n-1) c=n-1;
  
    if (switches[r][c]) {
      for (int i=r-1;i<=r+1;++i) for (int j=c-1;j<=c+1;++j) {
        if (i>=0 && i<n && j>=0 && j<n) light[i][j]=1;
      }
    }
  }

  for (Zombie &z:zombies) {
    if (!light[r][c] && z.r==r && z.c==c) return false;
    if (z.down && z.r<n-1) ++z.r;
    else if (!z.down && z.r>0) --z.r;
    else z.down^=1;

    if (!light[r][c] && z.r==r && z.c==c) return false;
  }

  // std::cout << "\nARI: " << r << '\t' << c << std::endl;
  // std::cout << "ZOMBIES:\n";
  // for (auto z:zombies) {
  //   std::cout << z.r << '\t' << z.c << std::endl;
  // }

  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::string mv;  std::cin >> mv;

  std::vector<Zombie> zombies;
  std::vector<std::bitset<15>> light(n, std::bitset<15>(0));
  std::vector<std::bitset<15>> switches(n, std::bitset<15>(0));

  std::string line;
  for (int i=0;i<n;++i) {
    std::cin >> line;
    for (int j=0;j<n;++j) {
      if (line[j]=='Z') zombies.emplace_back(Zombie(i, j));
      else if (line[j]=='S') switches[i][j]=1; 
    }
  }

  int dir=0;
  bool result;
  for (const char &c:mv) {
    if (c=='F') result=move(dir, zombies, switches, light, 1, n);
    else {
      result=move(dir, zombies, switches, light, 0, n);
      if (c=='L') dir-=1;
      if (c=='R') dir+=1;
    }

    dir=(dir+4)%4;
    if (!result) {
      std::cout << "Aaaaaah!";
      return 0;
    }
  }
  std::cout << "Phew...";
  return 0;
}