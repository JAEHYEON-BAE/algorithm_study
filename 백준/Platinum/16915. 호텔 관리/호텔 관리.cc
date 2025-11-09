// 16915

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

struct SCC
{
  int size;
  const std::vector<std::vector<int>> &G;
  int idx=0;
  int scc_id=0;
  std::vector<int> index, stk, scc_comp;
  std::vector<bool> done;

  SCC(int size, const std::vector<std::vector<int>> &G): size(size), G(G) {
    index.assign(size, -1);
    done.assign(size, 0);
    scc_comp.assign(size, -1);

    for (int i=0;i<size;++i) if (index[i]==-1) {
      DFS(i);
    }
  }

  int DFS(int u) {
    index[u]=idx++;
    int lowlink=index[u];
    stk.push_back(u);

    for (const int &v:G[u]) {
      if (index[v]==-1) lowlink=std::min(lowlink, DFS(v));
      else if (!done[v]) lowlink=std::min(lowlink, index[v]);
    }

    if (lowlink==index[u]) {
      while (!stk.empty()) {
        int top=stk.back();
        stk.pop_back();
        done[top]=1;
        scc_comp[top]=scc_id;
        if (top==u) break;
      }
      ++scc_id;
    }
    return lowlink;
  }

  int result(int m) const {
    for (int i=0;i<m;++i) if (scc_comp[i]==scc_comp[i+m]) return 0;
    return 1;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<bool> on(n);
  for (int i=0;i<n;++i) {
    int x;  std::cin >> x;
    on[i]=x;
  }
  std::vector<std::vector<int>> swt(n, std::vector<int>(2, -1));

  for (int i=0;i<m;++i) {
    int k;  std::cin >> k;
    for (int j=0;j<k;++j) {
      int x;  std::cin >> x; 
      --x;
      if (swt[x][0]==-1) swt[x][0]=i;
      else if (swt[x][1]==-1) swt[x][1]=i;
      else assert(!"INVALID INPUT");
    }
  }
  std::vector<std::vector<int>> G(m<<1);
  for (int i=0;i<n;++i) {
    int a=swt[i][0], b=swt[i][1];
    int na=a+m, nb=b+m;
    if (on[i]) {
      G[a].push_back(b);
      G[b].push_back(a);
      G[na].push_back(nb);
      G[nb].push_back(na);
    }
    else {
      G[a].push_back(nb);
      G[na].push_back(b);
      G[b].push_back(na);
      G[nb].push_back(a);
    }
  }

  SCC scc(m<<1, G);
  std::cout << scc.result(m);
  return 0;
}