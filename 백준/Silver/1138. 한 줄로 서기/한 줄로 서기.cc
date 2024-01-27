#include <ios>
#include <vector>
int main()
{
        int n; scanf("%d", &n);
        std::vector<int> v(n+1, 0);
        for (int i=1;i<=n;i++) {
                int x; scanf("%d", &x);
                int k=0;
                for (int j=1;j<=x+1;++j) {
                        if (v[j] != 0) ++x; 
                        ++k;
                }
                v[k] = i;
        }
        for (int i=1;i<=n;i++) {
                printf("%d ", v[i]);
        }
        return 0;
}