#include <ios>
#include <algorithm>
int main()
{
        int n, m; scanf("%d%d", &n, &m);
        int six=1001, one=1001;
        while (m--) {
                int x, y; scanf("%d%d", &x, &y);
                six = std::min(six, x);
                one = std::min(one, y);
        }
        if (one*6 < six) {
                printf("%d", one*n);
                return 0;
        }
        int result = six*(n/6) + std::min(one*(n%6), six);
        printf("%d", result);
        return 0;
}