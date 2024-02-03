#include <iostream>
#include <vector>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n; std::cin >> n;
        if (n==1) {
                std::cout << "A";
                return 0;
        }
        std::vector<int> v(n);
        for (int i=0;i<n;i++) {
                std::cin >> v[i];
        }

        if (n==2 && v[1]!=v[0]) {
                std::cout << "A";
                return 0;
        }

        if (v[1]==v[0]) {
                for (int x: v) {
                        if (x!=v[0]) {
                                std::cout << "B";
                                return 0;
                        }
                }
                std::cout << v[0];
                return 0;
        }

        if ((v[2]-v[1])%(v[1]-v[0]) != 0) {
                std::cout << "B";
                return 0;
        }

        int a = (v[2]-v[1])/(v[1]-v[0]);
        int b = v[1] - a*v[0];

        for (int i=1;i<n;i++) {
                if (v[i] != a*v[i-1]+b) {
                        std::cout << "B";
                        return 0;
                }
        }
        std::cout << a*v[n-1]+b;
        return 0;
}