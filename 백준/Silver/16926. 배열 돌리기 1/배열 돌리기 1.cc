#include <ios>
#include <vector>
#include <algorithm>
std::vector<std::vector<int>> rotate (const std::vector<std::vector<int>>& a, const int& n, const int& m) 
{
        std::vector<std::vector<int>> b(n+1, std::vector<int>(m+1));
        for (int i=1;i<=n;i++) {
                for (int j=1;j<=m;j++) {
                        if (i==j && i<=std::min(n, m)/2) {
                                b[i][j] = a[i][j+1];
                                b[n+1-i][j] = a[n-i][j];
                                b[i][m+1-j] = a[i+1][m+1-j];
                                b[n+1-i][m+1-j] = a[n+1-i][m-j];
                        }
                        else if (i<j && j<m+1-i && i <= n/2) {
                                b[i][j] = a[i][j+1];
                        }
                        else if (j<i && i<n+1-j && j <= m/2) {
                                b[i][j] = a[i-1][j];
                        }
                        else if (n+1-i<j && n+1-i<m+1-j && i > n/2) {
                                b[i][j] = a[i][j-1];
                        }
                        else if (m+1-j<i && m+1-j<n+1-i && j > m/2) {
                                b[i][j] = a[i+1][j];
                        }
                }
        }
        return b;
}

int main()
{
        int n, m, r; scanf("%d%d%d", &n, &m, &r);
        std::vector<std::vector<int>> a(n+1, std::vector<int>(m+1));
        for (int i=1;i<=n;i++) {
                for (int j=1;j<=m;j++) {
                        scanf("%d", &a[i][j]);
                }
        }
        while (r--) {
                a = rotate(a, n, m);
        }
        for (int i=1;i<=n;i++) {
                for (int j=1;j<=m;j++) {
                        printf("%d ", a[i][j]);
                }
                printf("\n");
        }
        return 0;
}