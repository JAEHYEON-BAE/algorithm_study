#include <iostream>
#include <set>
#include <string>
#include <vector>
struct Compare 
{
        bool operator() (const std::pair<int, int>& a, const std::pair<int, int>& b) const
        {
                if (a.second == b.second) return a.first>b.first;
                return a.second>b.second;
        }
};

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<int> PL(100000, 0);
        std::multiset<std::pair<int, int>, Compare> problems;
        while (n--) {
                int num, level;
                std::cin >> num >> level;
                PL[num] = level;
                problems.insert({num, level});
        }
        int m;  std::cin >> m;
        while (m--) {
                std::string inst;
                std::cin >> inst;
                if (inst=="add") {
                        int P, L;
                        std::cin >> P >> L;
                        PL[P] = L;
                        problems.insert({P, L});
                }
                else if (inst=="recommend") {
                        int x;  std::cin >> x;
                        if (x==1) std::cout << (*(problems.begin())).first << '\n';
                        else std::cout << (*(std::prev(problems.end()))).first << '\n';
                }
                else {
                        int P;  std::cin >> P;
                        problems.erase({P, PL[P]});
                }
        }
        return 0;
}