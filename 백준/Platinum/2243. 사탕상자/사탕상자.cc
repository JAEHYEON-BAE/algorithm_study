#include <iostream>
#include <vector>

#define MAX 4'000'000

void update(std::vector<int>& tree, int node, int start, int end, const int taste, const int dx)
{
//      std::cout << "\tUPDATING... NODE(" << node << "), range(" << start << ", " << end << "), taste(" << taste << ") for dx(" << dx << ')' << std::endl;
        if (taste<start || end<taste) return;
        tree[node] += dx;
        if (start!=end) {
                int mid = (start+end)/2;
                update(tree, node*2, start, mid, taste, dx);
                update(tree, node*2+1, mid+1, end, taste, dx);
        }
}
int search(const std::vector<int>& tree, int node, int start, int end, const int target)
{
        if (start == end) {
                return start;
        }

        int left = tree[node*2];
        int mid = (start+end)/2;
        if (target<=left) {
                return search(tree, node*2, start, mid, target);
        } else {
                return search(tree, node*2+1, mid+1, end, target-left);
        }
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n;  std::cin >> n;

        std::vector<int> tree(MAX, 0);


        while (n--) {
                int a;  std::cin >> a;
                if (a==1) {
                        int b;  std::cin >> b;
//                      std::cout << "QUERY: SEARCH(" << b << ')' << std::endl;
                        int taste = search(tree, 1, 0, 1'000'000, b);
                        std::cout << taste << '\n';
                        update(tree, 1, 0, 1'000'000, taste, -1);
                } else if (a==2) {
                        int b, c;
                        std::cin >> b >> c;
//                      std::cout << "QUERY: UPDATE(" << b << ", " << c << ')' << std::endl;
                        update(tree, 1, 0, 1'000'000, b, c);
                }
        }
        return 0;
}