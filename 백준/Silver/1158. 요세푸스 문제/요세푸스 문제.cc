#include <ios>
#include <queue>
int main()
{
        int n, k; scanf("%d%d", &n, &k);
        printf("<");
        std::queue<int> q;
        for (int i=1;i<=n;i++) {
                q.push(i);
        }
        for (int i=1;i<=n;i++) {
                for (int j=0;j<k;j++) {
                        int x = q.front();
                        q.pop();
                        if (j<k-1) {
                                q.push(x);
                                continue;
                        }
                        if (i==n) {printf("%d", x); continue;}
                        printf("%d, ", x);
                }
        }
        printf(">");
        return 0;
}