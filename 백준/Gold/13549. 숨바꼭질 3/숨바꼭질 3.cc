#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000
int main()
{
        int n, k;
        scanf("%d %d", &n, &k);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        int seconds[100010];
        fill(seconds, seconds + 100010, INF);
        seconds[n] = 0;

        pq.push({0, n});

        while (!pq.empty()) {
                int curr = pq.top().second;
                int curr_t = pq.top().first;
                pq.pop();
                for (int i=0;i<3;i++) {
                        // 0 = +1, 1 = -1, 2 = *2
                        int next; int next_t;
                        if (i==0) {next = curr+1; next_t = curr_t+1;}
                        else if (i==1) {next = curr-1; next_t = curr_t+1;}
                        else {next = curr*2; next_t = curr_t;}

                        if (next < 0 || next > 100000) {continue;}

                        if (next_t < seconds[next]) {
                                seconds[next] = next_t;
                                pq.push({next_t, next});
                        }
                }
        }
        printf("%d", seconds[k]);
        return 0;
}