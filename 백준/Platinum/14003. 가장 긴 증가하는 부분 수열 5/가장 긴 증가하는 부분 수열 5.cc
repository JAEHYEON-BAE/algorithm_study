#include <ios>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
vector<int> pos;
vector<int> seq;
void backtrace(int x, int y) 
{
        if (x==0) {return;}
        if (pos[x-1] == y-1) {
                seq.push_back(arr[x-1]);
                backtrace(x-1, y-1);
        }
        else {
                backtrace(x-1, y);
        }
        return;
}

int main()
{
        int n; scanf("%d", &n);
        int lis[1000001];
        int len = 0;
        int result = 0;
        for (int i=0;i<n;i++) {
                int x;
                scanf("%d", &x);
                arr.push_back(x);
                auto it = lower_bound(lis + 1, lis + len + 1, x);
                *it = x;
                if (it == lis + len + 1) {
                        len++;
                }
                pos.push_back(distance(lis, it)-1);
        }
        printf("%d\n", len);

        backtrace(n, len);

        for (auto iter = seq.end(); iter != seq.begin();) {
                printf("%d ", *--iter);
        }
        return 0;
}