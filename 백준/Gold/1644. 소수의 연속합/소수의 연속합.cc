#include <ios>
#include <vector>
using namespace std;
int main()
{
        int n; scanf("%d", &n);
        if (n==1) {printf("0"); return 0;}
        vector<int> prime;
        for (int i=2;i<=n;i++) {
                bool isPrime = true;
                for (int j=2;j*j<=i;j++) {
                        if (i%j == 0) {isPrime = false; break;}
                }
                if (isPrime) {prime.push_back(i);}
        }

        int size=prime.size();
        int result=0, start=0, end=0, sum=0;

        while (end <= size) {
                if (sum >= n) {
                        sum -= prime[start++];
                }
                if (sum < n) {
                        sum += prime[end++];
                }
                if (sum == n) {result++;}
        }
        printf("%d", result);
        return 0;
}