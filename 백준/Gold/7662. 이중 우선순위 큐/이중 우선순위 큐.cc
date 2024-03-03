#include <iostream>
#include <set>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int t;  std::cin >> t;
        while (t--) {
                int k;  std::cin >> k;
                std::multiset<int> Q;
                while (k--) {
                        char op; int x;
                        std::cin >> op >> x;
                        if (op=='I') {
                                Q.insert(x);
                        }
                        else if (!Q.empty()) {
                                if (x==1) {
                                        Q.erase(std::prev(Q.end()));
                                }
                                else {
                                        Q.erase(Q.begin());
                                }
                        }
                }
                if (Q.empty()) std::cout << "EMPTY\n";
                else std::cout << *(Q.rbegin()) << ' ' << *(Q.begin()) << '\n';
        }
        return 0;
}