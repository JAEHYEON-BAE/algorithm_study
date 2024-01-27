#include <iostream>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n; std::string str;
        std::cin >> n >> str;

        bool map[200][200];
        int curr[2] = {100, 100};
        int move[2] = {1, 0};
        int min_x=100, max_x=100, min_y=100, max_y=100;
        map[100][100] = true;
        for (char c: str) {
                if (c=='F') {
                        curr[0] += move[0];
                        curr[1] += move[1];
                }
                else if (c=='R') {
                        if (move[0]==1 && move[1]==0) {move[0]=0; move[1]=-1;}
                        else if (move[0]==0 && move[1]==-1) {move[0]=-1; move[1]=0;}
                        else if (move[0]==-1 && move[1]==0) {move[0]=0; move[1]=1;}
                        else if (move[0]==0 && move[1]==1) {move[0]=1; move[1]=0;}
                }
                else if (c=='L') {
                        if (move[0]==1 && move[1]==0) {move[0]=0; move[1]=1;}
                        else if (move[0]==0 && move[1]==1) {move[0]=-1; move[1]=0;}
                        else if (move[0]==-1 && move[1]==0) {move[0]=0; move[1]=-1;}
                        else if (move[0]==0 && move[1]==-1) {move[0]=1; move[1]=0;}
                }
                map[curr[0]][curr[1]] = true;
                min_y = std::min(min_y, curr[0]);
                max_y = std::max(max_y, curr[0]);
                min_x = std::min(min_x, curr[1]);
                max_x = std::max(max_x, curr[1]);
        }
        for (int i=min_y;i<=max_y;i++) {
                for (int j=min_x;j<=max_x;j++) {
                        printf("%c", map[i][j]? '.' : '#');
                }
                printf("\n");
        }
        return 0;
}