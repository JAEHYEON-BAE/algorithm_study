#include <iostream>
#include <vector>

#define INF 1'987'654'321

class SegTree
{
        private:
                int n;
                std::vector<int> tree;
                std::vector<int> v;

                void _build(int node, int start, int end)
                {
                        if (start==end) {
                                tree[node] = start;
                                return;
                        }
                        int mid = (start+end)/2;

                        _build(node*2, start, mid);
                        _build(node*2+1, mid+1, end);

                        int left = v[tree[node*2]];
                        int right = v[tree[node*2+1]];

                        if (left<right) tree[node] = tree[node*2];
                        else if (left==right) tree[node] = std::min(tree[node*2], tree[node*2+1]);
                        else    tree[node] = tree[node*2+1];
                        return;
                }
                void _update(int node, int start, int end, const int target, const int c)
                {
//                      std::cout << "\tCalling _update(" << node << ", " << start << ", " << end << ", " << target << ", " << c << ", v)" << std::endl;
                        if (start==end) {
                                v[target] = c;
                                tree[node] = start;
                                return;
                        } else if (target<start || end<target) {
                                return;
                        } else {
                                int mid = (start+end)/2;
                                if (start<=target && target<=mid) {
                                        _update(node*2, start, mid, target, c);
                                } else {
                                        _update(node*2+1, mid+1, end, target, c);
                                }
                                int left = v[tree[node*2]];
                                int right = v[tree[node*2+1]];

                                if (left<right) tree[node] = tree[node*2];
                                else if (left==right) tree[node] = std::min(tree[node*2], tree[node*2+1]);
                                else    tree[node] = tree[node*2+1];
                                return;
                        }


                }
                int _search(int node, int start, int end, const int l, const int r)
                {
                        if (r<start || end<l) return INF;
                        if (l<=start && end<=r) return tree[node];
                        int mid = (start+end)/2;
                        int left = _search(node*2, start, mid, l, r);
                        int right = _search(node*2+1, mid+1, end, l, r);

                        if (left==INF)  return right;
                        else if (right==INF)    return left;

                        if (v[left]<v[right])   return left;
                        else if (v[left]==v[right])     return std::min(left, right);
                        else return right;
                }


        public:
                SegTree(const std::vector<int>& v, const int& n)
                {
                        this->n = n;
                        this->v = v;
                        tree.resize(n*4);
                        _build(1, 0, n-1);
                }
                void update(int target, int c) 
                {
                        _update(1, 0, n-1, target, c);
                }
                void search(int l, int r)
                {
                        std::cout << _search(1, 0, n-1, l, r) + 1 << '\n';
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
        SegTree st(v, n);
        int m;  std::cin >> m;
        while (m--) {
                int a, b, c;    std::cin >> a >> b >> c;
                if (a==1)       {
//                      std::cout << "QUERY(" << a << "): change v[" << b << "](" << v[b-1] << ") to (" << c << ')' << std::endl;
                        st.update(b-1, c);
                } else {
//                      std::cout << "QUERY(" << a << "): search (" << b << ", " << c << ')' << std::endl;
                        st.search(b-1, c-1);
                }
        }
        return 0;
}