#include <iostream>
#include <vector>
#define INF 1987654321
void dfs(const int depth, const int number, const std::vector<int>& a, const std::vector<int> op, int& max, int& min, const int& n)
{
        if (depth==n) {
                max = std::max(max, number);
                min = std::min(min, number);
                return;
        }
        if (op[0]>0) dfs(depth+1, number+a[depth], a, {op[0]-1, op[1], op[2], op[3]}, max, min, n);
        if (op[1]>0) dfs(depth+1, number-a[depth], a, {op[0], op[1]-1, op[2], op[3]}, max, min, n);
        if (op[2]>0) dfs(depth+1, number*a[depth], a, {op[0], op[1], op[2]-1, op[3]}, max, min, n);
        if (op[3]>0) dfs(depth+1, number/a[depth], a, {op[0], op[1], op[2], op[3]-1}, max, min, n);
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<int> a(n);
        std::vector<int> op(4);
        for (int i=0;i<n;++i) {
                std::cin >> a[i];
        }
        for (int i=0;i<4;++i) {
                std::cin >> op[i];
        }
        int max=-INF, min=INF;
        dfs(1, a[0], a, op, max, min, n);
        std::cout << max << "\n" << min;
        return 0;
}