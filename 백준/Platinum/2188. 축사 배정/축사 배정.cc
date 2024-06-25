#include <iostream>
#include <vector>
bool bp_matching(int cow, std::vector<int>& match, std::vector<bool>& done, const std::vector<std::vector<int>>& v)
{
        for (int cage: v[cow]) {
                if (!done[cage]) {
                        done[cage]=true;
                        if (match[cage]==-1 || bp_matching(match[cage], match, done, v)) {
                                match[cage] = cow;
                                return true;
                        }
                }
        }
        return false;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n, m;       std::cin >> n >> m;
        std::vector<std::vector<int>> v(n);
        std::vector<int> match(m, -1);

        for (int i=0;i<n;++i) {
                int s;  std::cin >> s;
                while (s--) {
                        int x;  std::cin >> x;
                        v[i].push_back(x-1);
                }
                std::vector<bool> done(m, false);
                bp_matching(i, match, done, v);
        }
        int result = 0;
        for (int x: match) {
                if (x!=-1) ++result;
        }
        std::cout << result;
        return 0;
}