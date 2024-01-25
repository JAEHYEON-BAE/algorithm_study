#include <iostream>
#include <vector>
#include <queue>
int main()
{
        auto comp = [](const std::vector<int>& a, const std::vector<int>& b) {
                if (a[1] == b[1]) {return a[2] > b[2];}
                return a[1] > b[1];
        };
        int n; scanf("%d", &n);
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(comp)> pq(comp);
        std::vector<int> room(n+1);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> endtime;
        for (int i=0;i<n;i++) {
                int x, s, e;
                scanf("%d%d%d", &x, &s, &e);
                pq.push({x, s, e});
        }

        int i=0;
        while (!pq.empty()) {
                // v[0] = lecture number, v[1] = start time, v[2] = end time
                std::vector<int> v = pq.top();
                pq.pop();
                if (endtime.empty()) {
                        ++i;
                        room[v[0]] = i;
                        endtime.push({v[2], i});
                        continue;
                }
                // k.first = end time, k.second = classroom number
                std::pair<int, int> k = endtime.top();
                if (k.first <= v[1]) {
                        room[v[0]] = k.second;
                        endtime.pop();
                        endtime.push({v[2], k.second});
                }
                else {
                        ++i;
                        room[v[0]] = i;
                        endtime.push({v[2], i});
                }
        }

        printf("%d\n", i);
        for (int i=1;i<=n;i++) {
                printf("%d\n", room[i]);
        }
        return 0;
}