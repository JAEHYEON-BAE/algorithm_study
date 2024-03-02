#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
void dfs(const std::pair<int, int>& node, const std::vector<std::string>& map, std::vector<bool>& visited, int count, int& result, const std::vector<int>& dr, const std::vector<int>& dc)
{
        result = std::max(result, count);

        auto [r, c] = node;
        int max_r = map.size();
        int max_c = map[0].size();

        visited[map[r][c]-'A'] = true;
        for (int i=0;i<(int)dr.size();++i) {
                int next_r = r+dr[i], next_c = c+dc[i];
                if (next_r<0 || next_c<0 || next_r >= max_r || next_c >= max_c) continue;
                if (visited[map[next_r][next_c]-'A']) continue;
                dfs(std::make_pair(next_r, next_c), map, visited, count+1, result, dr, dc);
        }
        visited[map[r][c]-'A'] = false;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int r, c;       std::cin >> r >> c;
        std::vector<std::string> map(r);
        for (int i=0;i<r;++i) {
                std::cin >> map[i];
        }
        int result=0;
        std::vector<int> dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
        std::vector<bool> visited(26, false);
        visited[map[0][0]-'A'] = true;
        dfs(std::make_pair(0, 0), map, visited, 1, result, dr, dc);
        std::cout << result;
        return 0;
}