#include <iostream>
#include <vector>
int find(const int x, std::vector<int>& roots) 
{
        if (roots[x]==x) return x;
        return roots[x]=find(roots[x], roots);
}
void uni(int x, int y, std::vector<int>& roots)
{
        x = find(x, roots);
        y = find(y, roots);
        roots[x] = y;
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;       std::cin >> n >> m;
        std::vector<int> roots(n+1);
        for (int i=0;i<=n;++i) {
                roots[i]=i;
        }
        while (m--) {
                int x, a, b;
                std::cin >> x >> a >> b;
                if (x==0) uni(a, b, roots);
                if (x==1) std::cout << ((find(a, roots)==find(b, roots))? "YES\n" : "NO\n");
        }
        return 0;
}