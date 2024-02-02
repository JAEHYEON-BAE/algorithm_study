#include <iostream>
#include <vector>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<long long int> len(n-1);
        std::vector<long long int> cost(n);
        for (int i=0;i<n-1;i++) {
                std::cin >> len[i];
        }
        for (int i=0;i<n;i++) {
                std::cin >> cost[i];
        }
        int index = 0;
        long long int result = 0;

        while (index < n-1) {
                long long int tmp=0;
                for (int i=index+1;i<n;i++) {
                        tmp += len[i-1]*cost[index];
                        if (cost[i] < cost[index] || i == n-1) {
                                index = i;
                                result += tmp;
                                break;
                        }
                }
        }
        std::cout << result;
        return 0;
}