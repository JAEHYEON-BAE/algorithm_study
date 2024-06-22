#include <iostream>
#include <vector>
#include <stack>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::stack<int> stk;
        std::stack<int> idx;
        int x;
        for (int i=1;i<=n;++i) {
                std::cin >> x;
                while (!stk.empty() && stk.top()<=x) {
                        stk.pop();
                        idx.pop();
                }
                if (!stk.empty()) {
                        std::cout << idx.top() << ' ';
                }
                else std::cout << "0 ";
                stk.push(x);
                idx.push(i);
        }
        return 0;
}
