#include <iostream>
int count(int n)
{
        int cnt=0;
        for (;n!=0;cnt++) {
                n&=(n-1);
        }
        return cnt;
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n, k; std::cin >> n >> k;
        for (int i=0;;i++) {
                if (count(i+n)<=k) {
                        std::cout << i;
                        return 0;
                }
        }
        std::cout << -1;
        return 0;
}