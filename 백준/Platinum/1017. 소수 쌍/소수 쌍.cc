#include <iostream>
#include <vector>
#include <algorithm>

bool bp_m(int node, const std::vector<std::vector<int>>& bpGraph, std::vector<bool>& done, std::vector<int>& match)
{
        for (int neighbor: bpGraph[node]) {
                if (!done[neighbor]) {
                        done[neighbor] = true;
                        if (match[neighbor]==-1 || bp_m(match[neighbor], bpGraph, done, match)) {
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

        std::vector<bool> isPrime(2000, true);
        for (int i=2;i<45;++i) {
                for (int j=i*2;j<2000;j+=i) {
                        isPrime[j]=false;
                }
        }

        int n;  std::cin >> n;
        std::vector<int> v(n);
        std::vector<std::vector<int>> bpGraph(n);
        for (int i=0;i<n;++i) {
                std::cin >> v[i];
                for (int j=0;j<i;++j) {
                        if (isPrime[v[i]+v[j]]) {
                                bpGraph[i].push_back(j);
                                bpGraph[j].push_back(i);
                        }
                }
        }
        std::vector<int> answer;
        for (int x: bpGraph[0]) {
//              std::cout << "matching 0 and " << x << "..." << std::endl;
                std::vector<int> match(n, -1);
                match[0] = x;
                match[x] = 0;
                for (int i=1;i<n;++i) {
                        if (i==x) continue;
                        std::vector<bool> done(n, false);
                        done[0] = true;
                        done[x] = true;
                        bp_m(i, bpGraph, done, match);
                }
//              std::cout << "\tMATCH RESULT: { ";
//              for (int k: match) {
//                      std::cout << k << ' ';
//              }
//              std::cout << '}' << std::endl;

                if (std::find(match.begin(), match.end(), -1)==match.end()) {
                        answer.push_back(v[x]);
                }

        }
        if (answer.size()==0) {
                std::cout << "-1";
                return 0;
        }
        std::sort(answer.begin(), answer.end());
        for (int x: answer) {
                std::cout << x << ' ';
        }
        return 0;
}