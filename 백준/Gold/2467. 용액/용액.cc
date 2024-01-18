#include <ios>
#include <vector>
#include <cstdlib>
using namespace std;
#define INF 2000000000

int main()
{
        int n; scanf("%d", &n);
        int x;
        vector<int> v;
        for (int i=0;i<n;i++) {
                scanf("%d", &x);
                v.push_back(x);
        }

        int left = 0;
        int right = n-1;
        int a=v[left], b=v[right];
        int result = abs(a + b);

        while (right > left) {
                int tmp = v[left] + v[right];
                if (abs(tmp) < result) {
                        result = abs(tmp);
                        a = v[left];
                        b = v[right];
                }
                if (tmp < 0) {
                        ++left;
                }
                if (tmp > 0) {
                        --right;
                }
                if (tmp == 0) {
                        break;
                }
        }

        printf("%d %d", a, b);
        return 0;
}