#include <ios>
#include <vector>
#include <algorithm>
int main()
{
        int n; scanf("%d", &n);
        std::vector<std::vector<int>> p;
        while (n--) {
                int y, a, b; scanf("%d%d%d", &y, &a, &b);
                p.push_back({y, a, b});
        }
        std::sort(p.begin(), p.end(), [](const std::vector<int>& a, const std::vector<int>& b) {return a[0] < b[0];});
        int result = 0;
        int v[10000] = {};
        for (std::vector<int> x: p) {
                result += x[0]*2 - (v[x[1]] + v[x[2]-1]);
                for (int i=x[1]; i<x[2]; i++) {
                        v[i] = x[0];
                }
        }
        printf("%d", result);
        return 0;
}