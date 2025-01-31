// 14502
#include <iostream>
#include <vector>
#include <queue>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int n, m;

struct Point
{
  int r, c;
  Point(int r, int c): r(r), c(c) {}

  Point operator+(const Point& other) const {
    return Point(r+other.r, c+other.c);
  }

  bool invalid() const {
    return r<0 || c<0 || r>=n || c>=m;
  }

};

void polluted(const Point& start, const std::vector<std::vector<int>>& map, int& area, std::vector<std::vector<bool>>& done)
{

  std::queue<Point> q;
  q.push(start);
  done[start.r][start.c]=true;
  while (!q.empty()) {
    Point curr=q.front();
    q.pop();
    for (const Point& next:{curr+Point(0, -1), curr+Point(-1, 0), curr+Point(0, 1), curr+Point(1, 0)}) {
      if (next.invalid() || done[next.r][next.c]) continue;
      if (map[next.r][next.c]==0) {
        done[next.r][next.c]=true;
        ++area;
        q.push(next);
      }
    }
  }
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::vector<Point> viruses;
  int area=0;
  std::cin >> n >> m;
  std::vector<std::vector<int>> map(n, std::vector<int>(m));
  for (int i=0;i<n;++i) for (int j=0;j<m;++j) { 
    std::cin >> map[i][j];
    if (map[i][j]==2) viruses.push_back(Point(i, j));
    else if (map[i][j]==0) ++area;
  }

  area-=3;
  int safe_area=-1;
  for (int i=0;i<n*m;++i) {
    int &p=map[i/m][i%m];
    if (p==1 || p==2) continue;
    else p=1;
    for (int j=i+1;j<n*m;++j) {
      int &q=map[j/m][j%m];
      if (q==1 || q==2) continue;
      else q=1;
      for (int k=j+1;k<n*m;++k) {
        int &r=map[k/m][k%m];
        if (r==1 || r==2) continue;
        else r=1;

        std::vector<std::vector<bool>> done(map.size(), std::vector<bool>(map[0].size(), false));
        int pollute=0;
        for (const Point& virus: viruses) {
          polluted(virus, map, pollute, done);
        }
        safe_area=std::max(safe_area, area-pollute);

        r=0;
      }
      q=0;
    }
    p=0;
  }
  std::cout << safe_area;
  
  
  return 0; 
}
