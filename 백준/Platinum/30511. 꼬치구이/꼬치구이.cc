// 30511

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

constexpr int INF=(~0u)>>1;

int di[8]={-1, -1, -1, 0, 1, 1, 1, 0};
int dj[8]={-1, 0, 1, 1, 1, 0, -1, -1};

struct HK
{
  int L, R;
  std::vector<std::vector<int>> G;
  std::vector<int> matchL, matchR, dist;

  HK(int L, int R)
    : L(L), R(R), G(L), matchL(L, -1), matchR(R, -1), dist(L)
  {}

  void add_edge(int s, int g) {
    // std::cerr << s << " ---- " << g << std::endl;
    assert(s!=-1 && g!=-1);
    G[s].push_back(g);
  }

  bool BFS() {
    // std::cerr << "BFS " << std::endl;
    std::queue<int> q;
    for (int s=0;s<L;++s) {
      if (matchL[s]==-1) dist[s]=0, q.push(s);
      else dist[s]=INF;
    }

    bool FREE=0;

    while (!q.empty()) {
      int s=q.front();  q.pop();
      for (const int &g:G[s]) {
        const int &tmp=matchR[g];
        if (tmp==-1) FREE=1;
        else if (dist[tmp]==INF) {
          dist[tmp]=1+dist[s];
          q.push(tmp);
        }
      }
    }
    return FREE;
  }

  bool DFS(int s) {
    // std::cerr << "DFS from " << s << std::endl;
    for (const int &g:G[s]) {
      int &tmp=matchR[g];
      if (tmp==-1 || (dist[tmp]==1+dist[s] && DFS(tmp))) {
        matchL[s]=g;
        tmp=s;
        return 1;
      }
    }
    dist[s]=INF;
    return 0;
  }

  int matching() {
    int res=0;
    while (BFS()) for (int s=0;s<L;++s) {
      if (matchL[s]==-1) if (DFS(s)) ++res;
    }
    return res;
  }
};


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::string> v(n);

  int cntS=0, cntG=0;
  std::vector<int> mapS(n*m, -1), mapG(n*m, -1);
  for (int i=0;i<n;++i) {
    std::cin >> v[i];
    for (int j=0;j<m;++j) {
      if (v[i][j]=='S') mapS[i*m+j]=cntS++;
      else if (v[i][j]=='G') mapG[i*m+j]=cntG++;
    }
  }
  // std::cerr << cntS << ' ' << cntG << std::endl;

  HK hk(cntS, cntG);
  for (int i=0;i<n;++i) for (int j=0;j<m;++j) if (v[i][j]!='M') {
    for (int d=0;d<8;++d) {
      int ni=i+di[d], nni=ni+di[d];
      int nj=j+dj[d], nnj=nj+dj[d];
  
      if (nni<0 || nni>=n || nnj<0 || nnj>=m) continue;
      if (v[ni][nj]==v[i][j] || v[ni][nj]=='M' || v[nni][nnj]!='M') continue;

      // std::cerr << '(' << i << ", " << j << ") ---- (" << ni << ", " << nj << ')' << std::endl;
      
      int a=i*m+j;
      int b=ni*m+nj;

      if (v[i][j]=='S') hk.add_edge(mapS[a], mapG[b]);
      else hk.add_edge(mapS[b], mapG[a]);
    }
  }

  std::cout << hk.matching();
  return 0;
}