#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
map<int, map<int, int>> tree;
set<int> visited;
int result_distance;
int result_node;
int next_node;
void input_parsing()
{
        int v;
        scanf("%d", &v);
        for (int i=0;i<v;i++) {
                int node;
                map<int, int> vert;
                scanf("%d", &node);
                for (;;) {
                        int x; int y;
                        scanf(" %d", &x);
                        if (x == -1) break;
                        scanf(" %d", &y);
                        vert[x] = y;
                }
                tree[node] = vert;
        }
}
void dfs(int node, int distance)
{
        if (visited.count(node) > 0) {return;}
        visited.insert(node);
        if (result_distance < distance) {result_distance = distance; result_node = node;} 
        for (pair<int, int> neighbor : tree[node]) {
                dfs(neighbor.first, neighbor.second + distance);
        }
}
int main() 
{
        input_parsing();
        dfs(1, 0);
        result_distance = 0;
        visited = {};
        dfs(result_node, 0);
        printf("%d", result_distance);
        return 0;
}