#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
unordered_map<int, unordered_map<int, int>> graph;
int result_distance;
set<int> visited;
int result_node;

void dfs(int node, int distance) 
{
        if (visited.find(node) != visited.end()) {return;}
        visited.insert(node);
        if (result_distance < distance) {result_distance = distance; result_node = node;}
        for (const auto& x : graph[node]) {
                dfs(x.first, x.second + distance);
        }
}
int main() 
{
        int n;
        scanf("%d", &n);
        for (int i=0;i<n-1;i++) {
                int a, b, c;
                scanf("%d %d %d", &a, &b, &c);
                if (graph.find(a) == graph.end()) {graph[a] = {};}
                if (graph.find(b) == graph.end()) {graph[b] = {};}
                graph[a][b] = c; graph[b][a] = c;
        }

        dfs(1, 0);
        result_distance = 0;
        visited.clear();
        dfs(result_node, 0);
        printf("%d", result_distance);
}