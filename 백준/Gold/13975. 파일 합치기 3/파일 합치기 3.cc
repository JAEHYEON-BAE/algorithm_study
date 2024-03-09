#include <iostream>
#include <queue>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int t;  std::cin >> t;
        while (t--) {
                int k;  std::cin >> k;
                long long int cnt=0;
                std::priority_queue<long long int, std::vector<long long int>, std::greater<long long int>> pq;
                for (int i=0;i<k;++i) {
                        long long int x;        std::cin >> x;
                        pq.push(x);
                }
                while (pq.size()>1) {
                        long long int a = pq.top();
                        pq.pop();
                        long long int b = pq.top();
                        pq.pop();
                        cnt += a+b;
                        pq.push(a+b);
                }
                std::cout << cnt << '\n';
        }
        return 0;
}