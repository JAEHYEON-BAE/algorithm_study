#include <ios>
#include <algorithm>
int main()
{
        int n, m; scanf("%d%d", &n, &m);
        char c[50][50];
        for (int i=0;i<n;i++) {
                scanf("%s", c[i]);
        }

        int answer = 1;
        for (int i=0;i<n;i++) {
                for (int j=0;j<m;j++) {
                        for (int k=1; i+k<n && j+k<m; k++) {
                                if (c[i][j] == c[i+k][j] && c[i][j] == c[i][j+k] && c[i][j] == c[i+k][j+k]) {
                                        answer = std::max(answer, k+1);
                                }
                        }
                }
        }
        printf("%d", answer*answer);
        return 0;
}