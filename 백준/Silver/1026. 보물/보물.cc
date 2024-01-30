#include <ios>
#include <vector>
#include <algorithm>
int main()
{
        int n; scanf("%d", &n);
        std::vector<int> a;
        for (int i=0;i<n;i++) {
                int x; scanf("%d", &x);
                a.push_back(x);
        }
        std::vector<int> b;
        for (int i=0;i<n;i++) {
                int x; scanf("%d", &x);
                b.push_back(x);
        }

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end(), std::greater<int>());

        long long int result = 0;
        for (int i=0;i<n;i++) {
                result += a[i]*b[i];
        }
        printf("%lld", result);
        return 0;
}