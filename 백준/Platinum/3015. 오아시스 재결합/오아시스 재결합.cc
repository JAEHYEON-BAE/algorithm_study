#include <ios>
#include <stack>
#include <vector>

int main() 
{
        int n; scanf("%d", &n);

        if (n==1) {printf("1"); return 0;}

        long long ppl[500001];
        std::vector<long long> stack;
        for (int i=0;i<n;i++) {
                scanf("%lld", &ppl[i]);
        }

        std::stack<long long> s; 
        long long same_cnt[500001] = {};
        long long result = 0;
        for (int i = 0; i < n; i++) {
                while (!s.empty() && ppl[s.top()] <= ppl[i]) {
                        if (ppl[s.top()] == ppl[i]) {
                                same_cnt[i] += same_cnt[s.top()] + 1;
                        }
                        result += 1 + same_cnt[s.top()];
                        s.pop();

                }
                if (!s.empty()) {result += 1;}
                s.push(i);
        }

        printf("%lld", result);
        return 0;
}