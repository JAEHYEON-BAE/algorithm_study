#include <ios>
#include <set>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;
set<vector<int>> result;
int n, m;
array<int, 8> a;
void algorithm(vector<int> v, set<int> s)
{
        if (v.size() == m) {
                result.insert(v);
                return;
        }
        for (int i=0;i<n;i++) {
                if (s.find(i) != s.end()) {continue;}
                v.push_back(a[i]);
                s.insert(i);
                algorithm(v, s);
                s.erase(i);
                v.pop_back();
        }
}
int main()
{
        scanf("%d %d", &n, &m);
        for (int i=0;i<n;i++) {
                scanf("%d ", &a[i]);
        }
        vector<int> v; set<int> s;
        algorithm(v, s);


        for (vector<int> x : result) {
                for (int y : x) {
                        printf("%d ", y);
                }
                printf("\n");
        }
        return 0;
}