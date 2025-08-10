// 16367

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

struct TarjanSCC
{
  int k;
  int size;
  const std::vector<std::vector<int>> &graph;
  std::vector<int> dfs_n;
  std::vector<bool> done;
  std::vector<int> stk;
  std::vector<int> scc_group;
  int id=0;
  int scc_id=0;

  int SCC(int node) {
    dfs_n[node]=id++;
    stk.push_back(node);

    int lowlink=dfs_n[node];
    for (const int &next:graph.at(node)) {
      if (dfs_n[next]==-1) lowlink=std::min(lowlink, SCC(next));
      else if (!done[next]) lowlink=std::min(lowlink, dfs_n[next]);
    }

    if (lowlink==dfs_n[node]) {
      while (!stk.empty()) {
        int top=stk.back();
        stk.pop_back();
        done[top]=1;
        scc_group[top]=scc_id;
        if (top==node) break;
      }
      ++scc_id;
    }
    return lowlink;
  }

public:
  TarjanSCC(int k, const std::vector<std::vector<int>> &graph): k(k), graph(graph), size(1|k<<1) {
    dfs_n.assign(size, -1);
    done.assign(size, 0);
    scc_group.assign(size, -1);
    
    for (int i=1;i<size;++i) if (dfs_n[i]==-1) SCC(i);
  }

  bool valid() {
    stk.reserve(size);
    for (int i=1;i<=k;++i) {
      if (scc_group[i]==scc_group[i+k]) return 0;
    }
    return 1;
  }

  std::vector<bool> solution() {
    std::vector<bool> res(k+1);
    for (int i=1;i<=k;++i) {
      res[i]=(scc_group[i]>scc_group[i+k])?0:1;
    }
    return res;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  
  int k, n;  std::cin >> k >> n;

  // red: true, blue: false
  // 2-SAT problem

  std::vector<std::vector<int>> graph(1|k<<1);

  while (n--) {
    int tmp[3];
    for (int _=0;_<3;++_) {
      int x; char c;  std::cin >> x >> c;
      tmp[_]=x*(c=='R'?1:-1);
    }
    graph[tmp[0]>0?tmp[0]+k:-tmp[0]].push_back(tmp[1]>0?tmp[1]:-tmp[1]+k);
    graph[tmp[1]>0?tmp[1]+k:-tmp[1]].push_back(tmp[0]>0?tmp[0]:-tmp[0]+k);
    
    graph[tmp[0]>0?tmp[0]+k:-tmp[0]].push_back(tmp[2]>0?tmp[2]:-tmp[2]+k);
    graph[tmp[2]>0?tmp[2]+k:-tmp[2]].push_back(tmp[0]>0?tmp[0]:-tmp[0]+k);
    
    graph[tmp[1]>0?tmp[1]+k:-tmp[1]].push_back(tmp[2]>0?tmp[2]:-tmp[2]+k);
    graph[tmp[2]>0?tmp[2]+k:-tmp[2]].push_back(tmp[1]>0?tmp[1]:-tmp[1]+k);
  }

  TarjanSCC scc(k, graph);
  if (scc.valid()) {
    std::vector<bool> sol=scc.solution();
    for (int i=1;i<=k;++i) std::cout << (sol[i]?'R':'B');
  }
  else std::cout << "-1";
  
  return 0;
}
