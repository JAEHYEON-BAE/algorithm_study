#include <ios>
#include <vector>
using namespace std;
int palin[2001][2001] = {};
int main()
{
        int n, m; scanf("%d", &n);
        int v[2000];
        for (int i=0;i<n;i++) {
                scanf("%d", &v[i]);
        }

        scanf("%d", &m);
        for (int i=0;i<m;i++) {
                int s, e;
                scanf("%d%d", &s, &e);
                int ar_s = s;
                int ar_e = e;
                bool ispalin = true;
                while (s<e) {
                        if (palin[s][e] == 1) {ispalin = true; break;}
                        if (palin[s][e] == -1) {ispalin = false; break;}
                        if (v[s-1] != v[e-1]) {ispalin = false; break;}
                        ++s; --e;
                }
                if (ispalin) {printf("1\n"); palin[ar_s][ar_e] = 1;}
                else {printf("0\n"); palin[ar_s][ar_e] = -1;}
        }
}