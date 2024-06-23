#include <iostream>
#include <vector>
bool bp_m(int student, const std::vector<std::vector<int>>& bpGraph, std::vector<int>& match, std::vector<bool>& done) 
{
        for (int notebook: bpGraph[student]) {
                if (!done[notebook]) {
                        done[notebook] = true;
                        if (match[notebook]==-1 || bp_m(match[notebook], bpGraph, match, done)) {
                                match[notebook] = student;
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
        std::vector<std::vector<int>> bpGraph(n);
        while (m--) {
                int a, b;       std::cin >> a >> b;
                bpGraph[a-1].push_back(b-1);
        }

        std::vector<int> match(n, -1);
        for (int i=0;i<n;++i) {
                std::vector<bool> done(n, false);
                bp_m(i, bpGraph, match, done);
        }

        int result = n;
        for (int x: match) if (x==-1) --result;
        std::cout << result;
        return 0;
}