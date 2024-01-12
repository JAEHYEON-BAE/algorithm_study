#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1000000000 
int n, m;
int graph[101][101];
void floyd()
{
        vector<vector<int>> distances(101, vector<int>(101, 0));
        for (int i=1;i<=n;i++) {
                for (int j=1;j<=n;j++) {
                        if (i==j) {distances[i][i] = 0;}
                        else {distances[i][j] = graph[i][j];}
                }
        }
        for (int k=1;k<=n;k++) {
                for (int u=1;u<=n;u++) {
                        for (int v=1;v<=n;v++) {
                                distances[u][v] = min(distances[u][v], distances[u][k] + distances[k][v]);
                        }
                }
        }
        for (int i=1;i<=n;i++) {
                for (int j=1;j<=n;j++) {
                        if (distances[i][j] == INF) {distances[i][j] = 0;}
                        printf("%d ", distances[i][j]);
                }
                printf("\n");
        }
}
int main() 
{
        for (int i=1;i<=100;i++) {
                for (int j=1;j<=100;j++) {
                        graph[i][j] = INF;
                }
        }
        scanf("%d", &n);
        scanf("%d", &m);
        for (int i=0;i<m;i++) {
                int a, b, c;
                scanf("%d %d %d", &a, &b, &c);
                graph[a][b] = min(graph[a][b], c);
        }

        floyd();
        return 0;
}