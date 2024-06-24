#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1'987'654'321
class SegTree
{
        private:
                int n;
                std::vector<std::pair<int, int>> tree; // (min, max)

                void build(int node, int start, int end, const std::vector<int>& v)
                {
                        if (start==end) {
                                tree[node] = {v[start], v[start]};
                                return;
                        } else {
                                int mid = (start+end)/2;
                                build(node*2, start, mid, v);
                                build(node*2+1, mid+1, end, v);
                                tree[node].first = std::min(tree[node*2].first, tree[node*2+1].first);
                                tree[node].second= std::max(tree[node*2].second, tree[node*2+1].second);
                        }
                }
                std::pair<int, int> search(int node, int start, int end, const int l, const int r)
                {
                        if (r<start || end<l) {
                                return {MAX, 0};
                        }
                        if (l<=start && end<=r) {
                                return tree[node];
                        } else {
                                int mid = (start+end)/2;
                                std::pair<int, int> left = search(node*2, start, mid, l, r);
                                std::pair<int, int> right = search(node*2+1, mid+1, end, l, r);
                                return {std::min(left.first, right.first), std::max(left.second, right.second)};
                        }
                }

        public:
                SegTree(int n, const std::vector<int>& v)
                {
                        this->n = n;
                        tree.resize(n*4);
                        build(1, 0, n-1, v);
                }
                void query(int a, int b)
                {
                        auto [min, max] = search(1, 0, n-1, a, b);
                        std::cout << min << ' ' << max << '\n';
                }
};

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n, m;       std::cin >> n >> m;
        std::vector<int> v(n);
        for (int i=0;i<n;++i) {
                std::cin >> v[i];
        }
        SegTree st(n, v);

        while (m--) {
                int a, b;
                std::cin >> a >> b;
                st.query(a-1, b-1);
        }
        return 0;
}