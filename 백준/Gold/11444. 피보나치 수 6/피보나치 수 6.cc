#include <cstdio>
#include <vector>
using namespace std;
#define Q 1000000007
typedef vector<vector<long long int>> matrix;
matrix multiply(const matrix &x, const matrix &y) 
{
        matrix i_y(2, vector<long long int>(2));
        i_y[0] = {y[0][0], y[1][0]};
        i_y[1] = {y[0][1], y[1][1]};

        matrix result(2, vector<long long int>(2));
        for (int i=0;i<2;i++) {
                for (int j=0;j<2;j++) {
                        result[i][j] = ((x[i][0] % Q)*(i_y[j][0] % Q)%Q + (x[i][1] % Q)*(i_y[j][1] % Q)%Q)%Q;
                }
        }
        return result;
}
matrix power(matrix x, long long int r)
{
        if (r==1) {return x;}
        if (r%2) {
                return multiply(x, power(x, r-1));
        }
        if (r==0) {return {{1, 0}, {0, 1}};}
        matrix half = power(x, r/2);
        return multiply(half, half);
}
int main()
{
        vector<long long int> dp;
        long long int n;
        scanf("%lld", &n);

//      dp.push_back(0);
//      dp.push_back(1);
//      for (long long int i=2;i<=n;i++) {
//              dp.push_back((dp[i-2]%Q + dp[i-1]%Q)%Q);
//      }
//      printf("%lld", dp[n]);

        matrix x = {{1, 1}, {1, 0}};
        matrix result = power(x, n-1);
        printf("%lld", result[0][0]);
        return 0;
}