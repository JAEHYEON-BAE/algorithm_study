#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::ostream& operator<<(std::ostream& os, __int128 value) 
{
        if (value == 0) return os << "0";
        bool isNegative = value < (__int128)0;
        if (isNegative) value = -value;

        std::string result;
        while (value > 0) {
                result.push_back('0' + static_cast<char>(value % 10));
                value /= 10;
        }
        if (isNegative) result.push_back('-');
        std::reverse(result.begin(), result.end());
        os << result;
        return os;
}

class SegTree
{
        private:
                int n;
                std::vector<__int128> tree;

                void build(int node, int start, int end, const std::vector<long long int>& v)
                {
                        if (start==end) tree[node] = (__int128)v[start];
                        else {
                                int mid = (start+end)/2;
                                build(node*2, start, mid, v);
                                build(node*2+1, mid+1, end, v);
                                tree[node] = tree[node*2] + tree[node*2+1];
                        }
                }

                __int128 _sum(int node, int start, int end, const int& l, const int& r)
                {
//                      std::cout << "\tGETTING SUM: node(" << node << "), range(" << start << ", " << end << "), target(" << l << ", " << r << ')' << std::endl;
                        if (l>end || r<start) return 0;
                        if (l<=start && end <= r) return tree[node];
                        int mid = (start+end)/2;
                        return _sum(node*2, start, mid, l, r) + _sum(node*2+1, mid+1, end, l, r);
                }

                void update(int node, int start, int end, const int& target, const __int128& dx)
                {
//                      std::cout << "\tUPDATING: node(" << node << "), range(" << start << ", " << end << "), target(" << target << "), dx(" << dx << ')' << std::endl;
                        if (start<=target && target<=end) {

                                tree[node] += dx;
                                if (start!=end) {
                                        int mid = (start+end)/2;
                                        update(node*2, start, mid, target, dx);
                                        update(node*2+1, mid+1, end, target, dx);
                                }
                        }
                }

        public:
                SegTree(int n, const std::vector<long long int>& v)
                {
                        this->n = n;
                        tree.resize(n*4);
                        build(1, 0, n-1, v);
                }
                void sum(const int l, const int r)
                {
                        std::cout << _sum(1, 0, n-1, l, r) << '\n';
                }
                void change(const int target, const __int128& dx)
                {
                        update(1, 0, n-1, target, dx);
                }
                /*
                void printTree()
                {
                        for (int i=1;i<n*4;++i) {
                                std::cout << "| NODE(" << i << "): " << tree[i] << '\t' << '|' << std::endl;
                        }
                }
                */
};

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<long long int> v(n);
        for (int i=0;i<n;++i) std::cin >> v[i];

        SegTree st(n, v);

        for (int i=0;i<m+k;++i) {
//              st.printTree();
                long long int a, b, c;
                std::cin >> a >> b >> c;
//              std::cout << "QUERY: (" << a << ", " << b << ", " << c << ")" << std::endl;
                if (a==1) {
                        st.change(b-1, c-v[b-1]);
                        v[b-1] = c;
                } else if (a==2) {
                        st.sum(b-1, c-1);
                }
        }
        return 0;
}