#include <iostream>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, k;       std::cin >> n >> k;
        int q=k, r=0;
        int pre_a=0;
        while (n--) {
                int a;  std::cin >> a;
                if (k/a == 0) break;
                int c=a;
                if (pre_a) c = a/pre_a;
                r += q%c;
                q = q/c;
                pre_a = a;
        }
        std::cout << q+r;
        return 0;
}