#include <iostream>
#include <vector>
#include <stack>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::stack<int> stk;
        std::stack<int> index;
        std::vector<int> v(n, 1000001);
        int i=0;
        while (n--) {
                int x;  std::cin >> x;
                while (!stk.empty() && stk.top()<x) {
                        v[index.top()] = x;
                        stk.pop();
                        index.pop();
                }
                index.push(i++);
                stk.push(x);
        }
        for (int& i: v) {
                if (i==1000001) std::cout << "-1 ";
                else std::cout << i << ' ';
        }
        return 0;
}