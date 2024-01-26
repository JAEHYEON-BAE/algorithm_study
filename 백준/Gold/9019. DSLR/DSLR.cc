#include <ios>
#include <queue>
#include <vector>
#include <string>
inline int d(int x)
{
        return (2*x)%10000;
}
inline int s(int x)
{
        if (x==0) return 9999;
        return x-1;
}
inline int l(int x)
{
        int d1, d2, d3, d4;
        d4 = x%10; d3 = (x%100)/10; d2 = (x%1000)/100; d1 = (x/1000);
        return ((d2*10 + d3)*10 + d4)*10 + d1;
}
inline int r(int x)
{
        int d1, d2, d3, d4;
        d4 = x%10; d3 = (x%100)/10; d2 = (x%1000)/100; d1 = (x/1000);
        return ((d4*10 + d1)*10 + d2)*10 + d3;
}

int main()
{
        int t; scanf("%d", &t);
        while (t--) {
                int a, b; scanf("%d%d", &a, &b);
                std::queue<int> q;
                std::vector<bool> visited(10000, false);
                std::vector<std::string> path(10000);
                q.push(a);
                visited[a] = true;
                path[a] = "";
                while (!q.empty()) {
                        int curr = q.front();
                        if (curr == b) {printf("%s\n", path[curr].c_str()); break;}
                        q.pop();
                        for (int i=0;i<4;i++) {
                                // 0: D, 1: S, 2: L, 3: R
                                if (i==0) {
                                        int next = d(curr); 
                                        if (!visited[next]) {
                                                q.push(next); visited[next] = true; path[next] = path[curr] + "D";}
                                }
                                if (i==1) {
                                        int next = s(curr); 
                                        if (!visited[next]) {
                                                q.push(next); visited[next] = true; path[next] = path[curr] + "S";}
                                }
                                if (i==2) {
                                        int next = l(curr); 
                                        if (!visited[next]) {
                                                q.push(next); visited[next] = true; path[next] = path[curr] + "L";}
                                }
                                if (i==3) {
                                        int next = r(curr); 
                                        if (!visited[next]) {
                                                q.push(next); visited[next] = true; path[next] = path[curr] + "R";}
                                }
                        }
                }
        }
}