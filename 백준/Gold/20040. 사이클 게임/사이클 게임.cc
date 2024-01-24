#include <ios>
#include <vector>
std::vector<int> parent;
int find(int x)
{
        if (parent[x] != x) {
                parent[x] = find(parent[x]);
        }
        return parent[x];
}
int main()
{
        int n, m; scanf("%d%d", &n, &m);
        parent.resize(n);
        for (int i=0;i<n;i++) {
                parent[i] = i;
        }
        int cnt=0;
        for (int i=0;i<m;i++) {
                int a, b;
                scanf("%d%d", &a, &b);
                ++cnt;
                a = find(a);
                b = find(b);
                if (a==b) {printf("%d", cnt); return 0;}
                parent[a] = b;
        }
        printf("0");
        return 0;
}