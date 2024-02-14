#include <iostream>
#include <vector>
#include <algorithm>
#define p 1000000007
long long int power(const int a, const int b)
{
        if (b==0) return 1;
        if (b==1) return a%p;
        long long int tmp=power(a, b/2)%p;
        if (b%2==0) return (tmp*tmp)%p;
        else return (((tmp*tmp)%p)*a)%p;
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<int> v(n);
        for (int i=0;i<n;++i) {
                std::cin >> v[i];
        }
        std::sort(v.begin(), v.end());
        long long int result=0;
        for (int i=0;i<n;++i) {
                result += (v[i] - v[n-1-i])*(power(2, i)-1)%p;
                result %= p;
        }
        std::cout << result;
        return 0;
}