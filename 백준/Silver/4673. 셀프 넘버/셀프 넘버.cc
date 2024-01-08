#include <vector>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <string>

using namespace std;

vector<int> v;

void d(int i) {
        stringstream ss;
        ss << i;
        string str = ss.str();

        int result = i;

        for (int n = 0; n < str.length(); n++) {
                int j = 0;
                stringstream sss(string(1, str[n]));
                sss >> j;
                result += j;
        }

        if (result <= 10000) {
                if (find(v.begin(), v.end(), result) == v.end()) {
                        v.push_back(result);
                }
                d(result);
        } else return;
}

int main() {

        for (int i = 1; i <= 10000; i++) {
                if (find(v.begin(), v.end(), i) == v.end()) {
                        d(i);
                }
        }

        for (int i = 1; i <= 10000; i++) {
                if (find(v.begin(), v.end(), i) == v.end()) {
                        printf("%d\n", i);
                }
        }
}