#include <ios>
int main() 
{
        int n, k, w, v;
        scanf("%d %d", &n, &k);
        int kns[100010] = {};
        for (int i=1;i<=n;i++) {
                scanf("%d %d", &w, &v);
                for (int j=k; j>=w; j--) {
                        if (kns[j-w] + v > kns[j]) {
                                kns[j] = kns[j-w] + v;
                        }
                }
        }
        printf("%d", kns[k]);
}