#include <iostream>
#include <vector>
bool bp_m(int node, const std::vector<std::vector<int>>& bpGraph, std::vector<int>& match, std::vector<bool>& done)
{
        for (int neighbor: bpGraph[node]) {
                if (!done[neighbor]) {
                        done[neighbor] = true;
                        if (match[neighbor]==-1 || bp_m(match[neighbor], bpGraph, match, done)) {
                                match[neighbor] = node;
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
        for (int i=0;i<n;++i) {
                int x;  std::cin >> x;
                int k;
                while (x--) {
                        std::cin >> k;
                        bpGraph[i].push_back(k-1);
                }

//              std::cout << "For (" << i << "): ";
//              for (int j: bpGraph[i]) std::cout << j << ' ';
//              std::cout << std::endl;
        }
        std::vector<int> match(m, -1);
        for (int node=0;node<n;++node) {
                std::vector<bool> done(m, false);
                bp_m(node, bpGraph, match, done);
        }
        int result = m;
//      std::cout << "MATCH RESULT: ";
        for (int x: match) {
//              std::cout << x << ' ';
                if (x==-1) --result;
        }
        std::cout << result;
        return 0;
}