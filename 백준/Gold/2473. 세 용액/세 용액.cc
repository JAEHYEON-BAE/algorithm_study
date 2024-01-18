#include <ios>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
        int n, x; scanf("%d", &n);
        vector<int> v;
        for (int i=0;i<n;i++) {
                scanf("%d", &x);
                v.push_back(x);
        }

        sort(v.begin(), v.end());

        long long int answer[3];
        long long int result = 3000000001;

        for (int i=0;i<n-2;i++) {
                int left=i+1, right=n-1;

                while (left < right) {
                        long long int tmp = (long long int) v[i] + v[left] + v[right];
                        if (std::abs(tmp) < result) {
                                result = std::abs(tmp);
                                answer[0] = v[i];
                                answer[1] = v[left];
                                answer[2] = v[right];
                        }
                        if (tmp == 0) {
                                printf("%d %d %d", v[i], v[left], v[right]);
                                return 0;
                        }
                        if (tmp < 0) {
                                ++left;
                        }
                        if (tmp > 0) {
                                --right;
                        }
                }
        }
        printf("%lld %lld %lld", answer[0], answer[1], answer[2]);
        return 0;
}