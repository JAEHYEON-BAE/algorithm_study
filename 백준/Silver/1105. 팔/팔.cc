#include <ios>
#include <string>
int main()
{
        int l, r; scanf("%d%d", &l, &r);
        std::string str_l = std::to_string(l), str_r = std::to_string(r);

        if (str_l.size() != str_r.size()) {
                printf("0"); return 0;
        }

        int cnt = 0;
        for (int i=0;i<(int)str_l.size();i++) {
                if (str_l[i]==str_r[i] && str_l[i]=='8') {
                        ++cnt;
                }
                else if (str_l[i]!=str_r[i]) {
                        break;
                }
        }
        printf("%d", cnt);
        return 0;
}