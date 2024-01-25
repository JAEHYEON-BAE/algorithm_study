#include <ios>
#include <vector>
int segtree[400000];
std::vector<int> a;
int build(int node, int start, int end) 
{
        if (start == end) {
                return segtree[node] = start;
        }
        int left = build(2*node, start, (start+end)/2);
        int right = build(2*node+1, (start+end)/2 + 1, end);
        return segtree[node] = (a[left] <= a[right]) ? left : right;
}

void update(int node, int start, int end, int i, int v) 
{
        if (start == end) {
                return;
        }
        if (i <= (start+end) / 2) {
                update(node*2, start, (start+end)/2, i, v);
        }
        else {
                update(node*2 + 1, (start+end)/2 + 1, end, i, v);
        }
        segtree[node] = (a[segtree[node*2]] <= a[segtree[node*2+1]]) ? segtree[node*2] : segtree[node*2+1];
        return;
}

int main()
{
        int n, m; scanf("%d", &n);
        a.resize(n);
        for (int i=0;i<n;i++) {
                scanf("%d", &a[i]);
        }
        build(1, 0, n-1);

        scanf("%d", &m);
        for (int j=0;j<m;j++) {
                int q; scanf("%d", &q);
                if (q==2) {printf("%d\n", segtree[1]+1);continue;}
                if (q==1) {
                        int i, v; scanf("%d%d", &i, &v);
                        a[i-1] = v;
                        update(1, 0, n-1, i-1, v);
                }
        }
        return 0;
}