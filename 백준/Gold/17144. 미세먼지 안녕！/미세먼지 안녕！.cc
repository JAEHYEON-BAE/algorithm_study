// 14938

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

void diffusion(std::vector<std::vector<int>>& a, const std::vector<std::vector<int>> b)
{
  int r=a.size(), c=a[0].size();
  for (int i=0;i<r;++i) for (int j=0;j<c;++j) {
    if (b[i][j]==-1) continue;
    int dust=b[i][j]/5;
    if (i>0   && a[i-1][j]!=-1)   
      a[i-1][j]+=dust, a[i][j]-=dust;
    if (i<r-1 && a[i+1][j]!=-1) 
      a[i+1][j]+=dust, a[i][j]-=dust;
    if (j>0   && a[i][j-1]!=-1) 
      a[i][j-1]+=dust, a[i][j]-=dust;
    if (j<c-1 && a[i][j+1]!=-1)
      a[i][j+1]+=dust, a[i][j]-=dust;
  }
}
void purify(std::vector<std::vector<int>>& a, const int &pur_r, const int &pur_c)
{
  int r=a.size(), c=a[0].size();
  int i=pur_r, j=pur_c;
  if (pur_c==0) --i;
  else --j;
  while (i!=pur_r || j!=pur_c) {
    if      (j==0 && i>0)         a[i][j]=a[i-1][j], --i;
    else if (i==0     && j<c-1)   a[i][j]=a[i][j+1], ++j;
    else if (j==c-1   && i<pur_r) a[i][j]=a[i+1][j], ++i;  
    else if (i==pur_r)            a[i][j]=a[i][j-1], --j;
    else assert(0);
  }

  i=pur_r+1, j=pur_c;
  if (pur_c==0) ++i;
  else --j;
  while (i!=pur_r+1 || j!=pur_c) {
    if      (j==0 && i<r-1)         a[i][j]=a[i+1][j], ++i;
    else if (i==r-1   && j<c-1)     a[i][j]=a[i][j+1], ++j;
    else if (j==c-1   && i>pur_r+1) a[i][j]=a[i-1][j], --i;  
    else if (i==pur_r+1)            a[i][j]=a[i][j-1], --j;
    else assert(0);
  }

}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int r, c, t;  std::cin >> r >> c >> t;
  int pur_r=-1, pur_c=-1;
  std::vector<std::vector<int>> a(r, std::vector<int>(c, 0));
  for (int i=0;i<r;++i) for (int j=0;j<c;++j) {
    std::cin >> a[i][j];
    if (a[i][j]==-1 && pur_r==-1) pur_r=i, pur_c=j;
  }

  
  
  while (t--) {
    diffusion(a, a);
    purify(a, pur_r, pur_c);
    for (int i=0;i<r;++i) for (int j=0;j<c;++j) {
      if (a[i][j]==-1 && (i!=pur_r && i!=pur_r+1 || j!=pur_c))
        a[i][j]=0;
    }
  }
  int cnt=0;
  for (int i=0;i<r;++i) {
    for (int j=0;j<c;++j) {
      if (a[i][j]!=-1) cnt+=a[i][j];
    }
  }
  std::cout << cnt;
  return 0; 
}
