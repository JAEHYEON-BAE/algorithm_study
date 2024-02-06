#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
void swap(std::vector<std::string>& v, const std::pair<int, int>& a, const std::pair<int, int>& b)
{
        char tmp;
        tmp = v[a.first][a.second];
        v[a.first][a.second] = v[b.first][b.second];
        v[b.first][b.second] = tmp;
        return;
}
int find(const std::vector<std::string>& v, const int n) 
{
        int cnt = 0;
        for (int i=0;i<n;i++) {
                int tmp_r = 1;
                int tmp_c = 1;
                char pre_r = ' ';
                char pre_c = ' ';
                for (int j=0;j<n;j++) {
                        if (v[i][j] == pre_r) {
                                ++tmp_r;
                        }
                        else {
                                pre_r = v[i][j];
                                tmp_r = 1;
                        }
                        cnt = std::max(cnt, tmp_r);

                        if (v[j][i] == pre_c) {
                                ++tmp_c;
                        }
                        else {
                                pre_c = v[j][i];
                                tmp_c = 1;
                        }
                        cnt = std::max(cnt, tmp_c);
                }
        }
        return cnt;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<std::string> v(n);
        for (int i=0;i<n;i++) { 
                std::cin >> v[i];
        }
        int result = 0;
        for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                        char curr = v[i][j];
                        if (i>0 && v[i-1][j]!=curr) {
                                swap(v, {i, j}, {i-1, j});
                                result = std::max(result, find(v, n));
                                swap(v, {i, j}, {i-1, j});
                        }
                        if (i<n-1 && v[i+1][j]!=curr) {
                                swap(v, {i, j}, {i+1, j});
                                result = std::max(result, find(v, n));
                                swap(v, {i, j}, {i+1, j});
                        }
                        if (j>0 && v[i][j-1]!=curr) {
                                swap(v, {i, j}, {i, j-1});
                                result = std::max(result, find(v, n));
                                swap(v, {i, j}, {i, j-1});
                        }
                        if (j<n-1 && v[i][j+1]!=curr) {
                                swap(v, {i, j}, {i, j+1});
                                result = std::max(result, find(v, n));
                                swap(v, {i, j}, {i, j+1});
                        }
                }
        }
        std::cout << result;
        return 0;
}