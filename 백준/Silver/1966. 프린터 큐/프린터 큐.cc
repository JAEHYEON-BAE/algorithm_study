#include <ios>
#include <deque>
int main()
{
        int t; scanf("%d", &t);
        while (t--) {
                int n, m; scanf("%d%d", &n, &m);
                int imp[101];
                std::deque<int> dq;
                for (int i=0;i<n;i++) {
                        scanf("%d", &imp[i]);
                        dq.push_back(i);
                }
                int result = 1;
                int order[101];
                while (!dq.empty()) {
                        int curr = dq.front();
                        bool most = true;
                        for (int x: dq) {
                                if (imp[x] > imp[curr]) {
                                        dq.pop_front();
                                        dq.push_back(curr);
                                        most = false;
                                        break;
                                }
                        }
                        if (most) {
                                dq.pop_front();
                                order[curr] = result;
                                ++result;
                        }
                }
                printf("%d\n", order[m]);
        }
        return 0;
}