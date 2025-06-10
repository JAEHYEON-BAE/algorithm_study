// 2162

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int ccw(const int &x1, const int &y1, const int &x2, const int &y2, const int &x3, const int &y3) 
{
  int tmp=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
  if (tmp==0) return tmp;
  return (tmp>0)?1:-1;
}
struct Line 
{
  int x1, y1, x2, y2;
  Line(){}

  bool crossing(const Line &o) const {
    // 끝점이 만나는 경우 true
    if ((x1==o.x1 && y1==o.y1) || (x2==o.x1 && y2==o.y1) || (x1==o.x2 && y1==o.y2) || (x2==o.x2 && y2==o.y2)) return 1;

    int d1=ccw(x1, y1, x2, y2, o.x1, o.y1);
    int d2=ccw(x1, y1, x2, y2, o.x2, o.y2);
    int d3=ccw(o.x1, o.y1, o.x2, o.y2, x1, y1);
    int d4=ccw(o.x1, o.y1, o.x2, o.y2, x2, y2);
    
    // 두 선분이 일직선상인 경우
    if (d1==0 && d2==0 && d3==0 && d4==0) {

      int max_x=std::max(x1, x2);
      int min_x=std::min(x1, x2);
      int o_max_x=std::max(o.x1, o.x2);
      int o_min_x=std::min(o.x1, o.x2);
      
      int max_y=std::max(y1, y2);
      int min_y=std::min(y1, y2);
      int o_max_y=std::max(o.y1, o.y2);
      int o_min_y=std::min(o.y1, o.y2);

      return (max_x>=o_min_x && min_x<=o_max_x && max_y>=o_min_y && min_y<=o_max_y);
    }

    return (d1!=d2 && d3!=d4);
  }
};

int find(int x, std::vector<int> &root) 
{
  if (x==root[x]) return x;
  return root[x]=find(root[x], root);
}
bool unite(int x, int y, std::vector<int> &root, std::vector<int> &rank, std::vector<int> &size, int &groups)
{
  x=find(x, root);
  y=find(y, root);
  if (x==y) return 0;

  if (rank[x]==rank[y]) {
    root[x]=y;  ++rank[y];  size[y]+=size[x];
  }
  else if (rank[x]<rank[y]) {root[x]=y;  size[y]+=size[x];}
  else {root[y]=x;  size[x]+=size[y];}

  --groups;
  return 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  // using namespace fastio;
  int n;  std::cin >> n;
  std::vector<Line> v(n);
  
  std::vector<int> root(n), rank(n, 0), size(n, 1);
  int groups=n;

  for (int i=0;i<n;++i) {
    root[i]=i;
    std::cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
    for (int j=0;j<i;++j) if (v[i].crossing(v[j])) {
      unite(i, j, root, rank, size, groups);
    }
  }

  std::cout << groups << '\n' << *std::max_element(size.begin(), size.end());
    
  
  return 0;
}
