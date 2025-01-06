// 11400 

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<int> discover, low;
std::set<std::pair<int, int>> bridges;
int counter = 0;

void dfs(int curr, int parent) {
  discover[curr] = low[curr] = ++counter;

  for (int next : graph[curr]) {
    if (next == parent)
      continue;

    if (!discover[next]) {
      dfs(next, curr);
      low[curr] = std::min(low[curr], low[next]);
      if (low[next] > discover[curr]) {
        bridges.insert({std::min(curr, next), std::max(curr, next)});
      }
    } else {
      low[curr] = std::min(low[curr], discover[next]);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int v, e;
  std::cin >> v >> e;

  graph.resize(v + 1);
  discover.assign(v + 1, 0);
  low.assign(v + 1, 0);

  while (e--) {
    int a, b;
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs(1, 0);

  std::cout << bridges.size() << '\n';
  for (const auto &bridge : bridges) {
    std::cout << bridge.first << ' ' << bridge.second << '\n';
  }

  return 0;
}
