#include <iostream>
#include <queue>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::priority_queue<int> pq;
        while (n--) {
                int x;  std::cin >> x;
                if (x) pq.push(x);
                else if (!pq.empty()) {
                        std::cout << pq.top() << "\n";
                        pq.pop();
                }
                else {
                        std::cout << "0\n";
                }
        }
        return 0;
}