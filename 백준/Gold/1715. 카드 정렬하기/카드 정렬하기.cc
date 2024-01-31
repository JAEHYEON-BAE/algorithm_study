#include <iostream>
#include <queue>
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
int merge(const int& n, const int& result)
{
        if (n==1) return result;
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        pq.push(x+y);
        return merge(n-1, result+x+y);
}


int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n;  std::cin >> n;
        for (int i=0;i<n;i++) {
                int x;  std::cin >> x;
                pq.push(x);
        }
        if (n==1) {std::cout << 0; return 0;}
        std::cout << merge(n, 0);
        return 0;
}