#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define YY first.first
#define XX first.second

int n, m;
vector<vector<int>> board;
int algorithm() 
{
        // 0 = up, 1 = down, 2 = left, 3 = right
        int y[4] = {-1, 1, 0, 0};
        int x[4] = {0, 0, -1, 1};
        pair<pair<int, int>, int> start = {{0, 0}, 0};
        int distances[1001][1001][2];
        memset(distances, 0, sizeof(distances));

        distances[0][0][0] = 1;

        queue<pair<pair<int, int>, int>> q;
        q.push(start);
        while (!q.empty()) {
                pair<pair<int, int>, int> curr = q.front();
                q.pop();
                if (curr.YY == n-1 && curr.XX == m-1) {
                        return distances[n-1][m-1][curr.second];}
                for (int i=0;i<4;i++) {
                        pair<pair<int, int>, int> next;
                        next.YY = curr.YY + y[i]; next.XX = curr.XX + x[i];
                        next.second = curr.second;
                        if (next.YY < 0 || next.YY >= n || next.XX < 0 || next.XX >= m) {
                                // out of box
                                continue;}
                        if (distances[next.YY][next.XX][next.second] > 0) {
                                // already visited
                                continue;}
                        if (board[next.YY][next.XX] == 0) {
                                // go: the board has no wall
                                distances[next.YY][next.XX][next.second] = distances[curr.YY][curr.XX][curr.second] + 1;
                                q.push(next);
                        }
                        else if (next.second == 0) {
                                // go: the board has wall and break it
                                next.second = 1;
                                distances[next.YY][next.XX][next.second] = distances[curr.YY][curr.XX][curr.second] + 1;
                                q.push(next);
                        }
                        else {
                                // can't go: the board has wall, and no more chance to break
                                continue;}
                }
        }
        return -1;
}
int main() 
{
        scanf("%d %d", &n, &m);
        board.resize(n, vector<int>(m, 0));
        for (int i=0;i<n;i++) {
                for (int j=0;j<m;j++) {
                        int x; scanf("%1d", &x);
                        board[i][j] = x;
                }
        }
        printf("%d", algorithm());
}