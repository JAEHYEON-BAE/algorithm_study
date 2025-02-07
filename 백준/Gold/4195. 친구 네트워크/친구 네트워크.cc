// 4195

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>1;

int find(int x, std::vector<int> &root) 
{
  if (x==root[x]) return x;
  return root[x]=find(root[x], root);
}

bool unite(int x, int y, std::vector<int> &root, std::vector<int> &rank, std::vector<int> &size)
{
  int root_x=find(x, root), root_y=find(y, root);
  if (root_x==root_y) return false;

  if (rank[root_x]<rank[root_y]) {
    root[root_x]=root_y;
    size[root_y]+=size[root_x];
  }
  else if (rank[root_x]>rank[root_y]) {
    root[root_y]=root_x;
    size[root_x]+=size[root_y];
  }
  else {
    root[root_x]=root_y;
    ++rank[root_y];
    size[root_y]+=size[root_x];
  }
  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int tc, f;  std::cin >> tc;
  std::string a, b;
  while (tc--) {
    std::cin >> f;
    std::unordered_map<std::string, int> map;
    std::vector<int> rank(f*2, 0), root(f*2), size(f*2, 1);
    int idx=-1;
    for (int i=0;i<f;++i) {
      std::cin >> a >> b;
      if (map.find(a)==map.end()) {
        map[a]=++idx;
        root[map[a]]=map[a];
      }
      if (map.find(b)==map.end()) {
        map[b]=++idx;
        root[map[b]]=map[b];
      }
      unite(map[a], map[b], root, rank, size);
      std::cout << size[find(map[a], root)] << '\n';
    }
            
  }

  return 0; 
}