#include <iostream>
#include <vector>
#include <algorithm>
class SegTree
{
        private:
                int n;
                std::vector<std::vector<int>> tree;

                void build(int node, int start, int end, const std::vector<int>& v)
                {
                        if (start==end) {
                                tree[node] = std::vector<int>(1, v[start]);
                        } else {
                                int mid = (start+end)/2;
                                build(node*2, start, mid, v);
                                build(node*2+1, mid+1, end, v);
                                merge(node, tree[node*2], tree[node*2+1]);
                        }
                }
                void merge(int node, const std::vector<int>& a, const std::vector<int>& b)
                {
                        tree[node].insert(tree[node].end(), a.begin(), a.end());
                        tree[node].insert(tree[node].end(), b.begin(), b.end());
                        std::sort(tree[node].begin(), tree[node].end());
                }
                int _query(int node, int start, int end, const int& i, const int& j, const int& k)
                {
                        if (i>end || j<start) return 0;
                        if (i<=start && end<=j) {
                                return (tree[node].end() - std::upper_bound(tree[node].begin(), tree[node].end(), k));
                        }
                        int mid = (start+end)/2;
                        return _query(node*2, start, mid, i, j, k) + _query(node*2+1, mid+1, end, i, j, k);
                }


        public:
                SegTree(const std::vector<int>& v) 
                {
                        n = v.size();
                        tree.resize(4*n);
                        build(1, 0, n-1, v);
                }
                int query(int i, int j, int k)
                {
                        return _query(1, 0, n-1, i, j, k);
                }
};


int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n;  std::cin >> n;
        std::vector<int> v(n);
        for (int i=0;i<n;++i) {
                std::cin >> v[i];
        }
        SegTree st(v);
        int m;  std::cin >> m;
        while (m--) {
                int i, j, k;
                std::cin >> i >> j >> k;
                std::cout << st.query(i-1, j-1, k) << '\n';
        }
        return 0;
}