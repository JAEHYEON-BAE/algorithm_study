#include <iostream>
#include <queue>
#include <string>

void BFS(int n)
{
        std::queue<std::pair<int, std::string>> q;
        q.push({1, "1"});
        std::vector<bool> visited(n, false);
        visited[1] = true;
        while (!q.empty()) {
                std::pair<int, std::string> current = q.front();
//              std::cout << "While Loop: current(" << current.first << ", \"" << current.second << "\")" << std::endl;
                if (current.first==0) {
                        std::cout << current.second << '\n';
                        return;
                }
                if (current.second.size()>100) {
                        std::cout << "BRAK\n";
                        return;
                }

                q.pop();

                int plus_zero = (current.first*10)%n;
                int plus_one = (current.first*10+1)%n;

                if (!visited[plus_zero])        {
                        q.push({plus_zero, current.second+"0"});
                        visited[plus_zero] = true;
                }
                if (!visited[plus_one]) {
                        q.push({plus_one, current.second+"1"});
                        visited[plus_one] = true;
                }
        }
        std::cout << "BRAK\n";
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int t;  std::cin >> t;
        while (t--) {
                int n;  std::cin >> n;
                BFS(n);
        }
        return 0;
}