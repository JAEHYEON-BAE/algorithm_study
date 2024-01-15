#include <ios>
#include <algorithm>
using namespace std;
int main()
{
        int n; scanf("%d", &n);
        int lis[1000001];
        int len = 0;
        for (;n>0;n--) {
                int x; scanf("%d", &x);
                auto iter = lower_bound(lis+1, lis+len+1, x);
                *iter = x;
                if (iter == lis+len+1) {
                        len++;
                }
        }
        printf("%d", len);
}