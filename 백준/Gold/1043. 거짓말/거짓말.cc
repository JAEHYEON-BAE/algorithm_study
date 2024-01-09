#include <cstdio>
#include <map>
#include <set>
using namespace std;
int n; int m;
set<int> t;
map<int, set<int>> p;
void input_parsing() 
{
        int x;
        scanf("%d %d", &n, &m);
        scanf("%d", &x);
        for (int i=0;i<x;i++) {
                int v;
                scanf(" %d", &v);
                t.insert(v);
        }
        for (int i=0;i<m;i++) {
                int k;
                scanf("%d", &k);
                for (int j=0;j<k;j++) {
                        int v;
                        scanf(" %d", &v);
                        p[i].insert(v);
                }
        }
}
int main() {
        input_parsing();
        while (!t.empty()) {
                for (set<int>:: iterator i = t.begin(); i != t.end(); ) {
                        for (map<int, set<int>>::iterator it = p.begin(); it != p.end(); ) {
                                set<int> y = it->second;
                                if (y.find(*i) != y.end()) {
                                        for (int k: y) {
                                                t.insert(k);
                                        }
                                        it = p.erase(it);
                                } else { ++it;}
                        }
                        i = t.erase(i);
                }
        }
        printf("%d", (int)p.size());
        return 0;
}