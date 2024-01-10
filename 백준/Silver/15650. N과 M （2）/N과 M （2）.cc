#include <cstdio>
#include <vector>
using namespace std;
int n, m;
vector <int> picked;
void algorithm(int start, int x, int y)
{
        if (picked.size() == m) {
                for (int i=0;i<m;i++) {
                        printf("%d ", picked[i]);
                }
                printf("\n");
                return;
        }
        for (int i=start;i<=n;i++) {
                picked.push_back(i);
                start += i-start+1;
                algorithm(start, x-i, y-1);
                start -= i;
                picked.pop_back();
        }
}
int main()
{
        scanf("%d %d", &n, &m);
        if (n==1) {
                printf("1");
                return 0;
        }
        if (m==1) {
                for (int i=1;i<=n;i++) {printf("%d\n", i);}
                return 0;
        }
        if (n==2) {
                printf("1 2"); 
                return 0;
        }
        if (n==m) {
                for (int i=1;i<=n;i++) {printf("%d ", i);}
                return 0;
        }
        algorithm(1, n, m);
        return 0;
}