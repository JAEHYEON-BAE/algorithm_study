#include <ios>
#include <algorithm>
int main()
{
        int n, m; scanf("%d%d", &n, &m);
        if (n==1) {printf("1"); return 0;}
        if (n==2) {printf("%d", std::min(4, (m+1)/2)); return 0;}
        if (n>=3 && m<7) {
                printf("%d", std::min(4, m)); return 0;}
        if (n>=3 && m>=7) {
                printf("%d", 4 + m-7 + 1); return 0;}
        return 0;
}
