// 1430

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

struct Line
{
  int sx, sy, dx, dy;
  Line() {}
  Line(int sx, int sy, int dx, int dy): sx(sx), sy(sy), dx(dx), dy(dy) {}
};

bool meet(Line a, Line b) 
{
  bool ta=a.sy==a.dy;
  bool tb=b.sy==b.dy;
  if (ta==tb) {
    if (ta) return a.sy==b.sy && a.dx>=b.sx && b.dx>=a.sx;
    else return a.sx==b.sx && a.dy>=b.sy && b.dy>=a.sy;
  }
  else {
    if (tb) std::swap(a, b);
    return a.sx<=b.sx && b.sx<=a.dx && b.sy<=a.sy && a.sy<=b.dy;
  }
}
bool meet(Line a, int x, int y) 
{
  bool t=a.sy==a.dy;
  if (t) return y==a.sy && a.sx<=x && x<=a.dx;
  else return x==a.sx && a.sy<=y && y<=a.dy;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int m, n, k;  std::cin >> m >> n >> k;
  std::vector<Line> lines(k);
  std::vector<std::vector<int>> G(k+2);
  int _;
  for (int i=0;i<k;++i) {
    Line &l=lines[i];
    std::cin >> _;
    std::cin >> l.sx >> l.sy >> l.dx >> l.dy;
    if (l.sx>l.dx) std::swap(l.sx, l.dx);
    if (l.sy>l.dy) std::swap(l.sy, l.dy);

    for (int j=0;j<i;++j) if (meet(l, lines[j])) {
      G[i].push_back(j);
      G[j].push_back(i);
    }
  }
  int sx, sy, dx, dy;  std::cin >> sx >> sy >> dx >> dy;
  for (int i=0;i<k;++i) {
    const Line &l=lines[i];
    if (meet(l, sx, sy)) G[k].push_back(i);
    if (meet(l, dx, dy)) G[i].push_back(k+1);
  }

  std::queue<int> q;
  std::vector<int> dist(k+2, -1);
  q.push(k);  dist[k]=0;
  while (!q.empty()) {
    int u=q.front();
    q.pop();
    for (const int &v:G[u]) if (dist[v]==-1) {
      dist[v]=1+dist[u];
      q.push(v);
    }
  }
  
  std::cout << dist[k+1]-1;
  return 0;
}
