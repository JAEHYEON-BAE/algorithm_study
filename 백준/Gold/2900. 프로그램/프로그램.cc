#include <ios>
#include <vector>
#include <unordered_map>
std::vector<int> a;
void something(int n, int jump, int cnt) {
        int i=0;
        while (i<n) {
                a[i] += cnt;
                i += jump;
        }
        return;
}
int main()
{
        int n, k; scanf("%d%d", &n, &k);
        std::unordered_map<int, int> map;
        std::vector<long long int> v(n, 0);
        a.resize(n);
        while (k--) {
                int x; scanf("%d", &x);
                if (map.find(x) == map.end()) {map[x] = 0;}
                ++map[x];
        }
        for (std::pair<int, int> p: map) {
                something(n, p.first, p.second);
        }

        v[0] = (long long int) a[0];
        for (int i=1;i<n;i++) {
                v[i] = v[i-1]+a[i];
        }

        int q; scanf("%d", &q);
        while (q--) {
                int l, r; scanf("%d%d", &l, &r);
                printf("%lld\n", v[r] - v[l] + (long long int)a[l]);
        }
        return 0;
}