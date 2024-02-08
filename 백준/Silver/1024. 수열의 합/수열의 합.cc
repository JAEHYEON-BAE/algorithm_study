#include <iostream>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, l;       std::cin >> n >> l;
        for (int i=l;i<=100;i++) {
                if (i%2==1 && n%i==0) {
                        if ((n/i-i/2)<0) {std::cout << "-1"; return 0;}
                        for (int x=n/i-i/2;x<=n/i+i/2;x++) {
                                std::cout << x << " ";
                        }
                        return 0;
                }
                if (i%2==0 && n%(i/2)==0 && (n/(i/2))%2==1) {
                        int start = n/(i/2)/2 - (i/2-1);
                        if (start < 0) {
                                std::cout << "-1"; return 0;}
                        for (int x=start;x<=start+(i-1);x++) {
                                std::cout << x << " ";
                        }
                        return 0;
                }
        }
        std::cout << "-1";
        return 0;
}