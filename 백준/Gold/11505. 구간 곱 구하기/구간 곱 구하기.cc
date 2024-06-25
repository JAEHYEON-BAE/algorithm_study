#include <iostream>
#include <vector>
#include <set>

#define M 1'000'000'007
long long int mod_inverse(int int_x)
{
        long long int res = 1;
        long long int x = static_cast<long long int>(int_x);
        x %= M;
        int y = M-2;
        while (y>0) {
                if (y&1)        res = (res*x)%M;
                y >>= 1;
                x = (x*x)%M;
        }
        return res%M;
}

class SegTree
{
        private:
                int n;
                std::vector<long long int> tree;

                void _build(int node, int start, int end, const std::vector<int>& v)
                {
                        if (start==end) {
                                tree[node] = v[start] % M;
                                return;
                        }
                        int mid = (start+end)/2;
                        _build(node*2, start, mid, v);
                        _build(node*2+1, mid+1, end, v);
                        tree[node] = (tree[node*2]%M) * (tree[node*2+1]%M) % M;
                        return;
                }

                void _update(int node, int start, int end, const int target, const int diff)
                {
                        if (target<start || end<target) return;
                        tree[node] = tree[node]*diff % M;
                        if (start!=end) {
                                int mid = (start+end)/2;
                                _update(node*2, start, mid, target, diff);
                                _update(node*2+1, mid+1, end, target, diff);
                        }
                        return;
                }

                long long int _search(int node, int start, int end, const int l, const int r)
                {
                        if (r<start || end<l) return 1;

                        if (l<=start && end<=r) {
                                return tree[node];
                        }
                        int mid = (start+end)/2;
                        return _search(node*2, start, mid, l, r) * _search(node*2+1, mid+1, end, l, r) % M;
                }


        public:
                SegTree(int n, const std::vector<int>& v)
                {
                        this->n = n;
                        tree.resize(n*4);
                        _build(1, 0, n-1, v);
                }
                void update(int target, int from, int to)
                {
                        long long int diff = (mod_inverse(from) * to) % M;
//                      std::cout << "\tDIFF = " << diff << std::endl;
                        _update(1, 0, n-1, target, static_cast<int>(diff));
                }
                void search(int l, int r)
                {
                        std::cout << _search(1, 0, n-1, l, r) << '\n';
                }
};

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<int> v(n);
        for (int i=0;i<n;++i) {
                std::cin >> v[i];
        }
        SegTree st(n, v);

        std::set<int> zeros;

        for (int i=0;i<m+k;++i) {
                int a, b, c;    std::cin >> a >> b >> c;
                if (a==1) {
//                      std::cout << "QUERY(1): target(" << b-1 << "), from(" << v[b-1] << ") to(" << c << ')' << std::endl;
                        if (c!=0) {
                                st.update(b-1, v[b-1], c);
                                v[b-1] = c;
                                auto it = zeros.find(b-1);
                                if (it!=zeros.end()) {
                                        zeros.erase(it);
                                }
                        } else {
                                zeros.insert(b-1);
                        }

                } else if (a==2) {
//                      std::cout << "QUERY(2): search (" << b-1 << ", " << c-1 << ')' << std::endl;
                        auto it = zeros.lower_bound(b-1);
                        if (it!=zeros.end() && (*it)<=c-1)      std::cout << '0' << '\n';
                        else    st.search(b-1, c-1);
                }
        }
        return 0;
}