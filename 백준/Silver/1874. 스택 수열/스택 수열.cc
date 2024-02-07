#include <iostream>
#include <stack>
#include <string>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::stack<int> stk;
        int num = 0;
        std::string result;
        stk.push(0);
        while (n--) {
                int x;  std::cin >> x;
                if (x>stk.top()) {
                        for (int i=num+1;i<=x;i++) {
                                result += '+';
                                stk.push(i);
                        }
                        num = x;
                        result += '-';
                        stk.pop();
                }
                else if (x==stk.top()) {
                        result += '-';
                        stk.pop();
                }
                else {
                        std::cout << "NO";
                        return 0;
                }
        }
        for (char c: result) {
                std::cout << c << "\n";
        }
        return 0;
}