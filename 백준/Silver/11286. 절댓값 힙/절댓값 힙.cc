#include <iostream>
#include <queue>
#include <cmath>
struct Compare
{
        bool operator ()(const int& a, const int& b) {
                int abs_a = std::abs(a);
                int abs_b = std::abs(b);
                if (abs_a == abs_b) {return a > b;}
                return (abs_a > abs_b);
        }
};

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;

        std::priority_queue<int, std::vector<int>, Compare> pq;
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