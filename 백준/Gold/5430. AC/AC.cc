#include <iostream>
#include <vector>
#include <string>
#include <deque>
void algorithm(const std::string& p, const int n, std::deque<std::string>& deq, int size)
{
        bool rev = false;
        for (int i=0;i<(int)p.size();i++) {
                if (p[i]=='R')  rev^=1;
                else {
                        if (size==0) {std::cout << "error\n"; return;}
                        if (!rev) {
                                deq.pop_front(); --size;
                                if (size!=0) {
                                        deq.pop_front();
                                }
                        }
                        else {deq.pop_back(); --size;
                                if (size!=0) {
                                        deq.pop_back();
                                }
                        }
                }
        }
        std::cout << "[";
        if (size==0) {std::cout << "]\n"; return;}
        if (!rev) {
                for (std::deque<std::string>::iterator it = deq.begin();it!=deq.end();it++) {
                        std::cout << *it;
                }
                std::cout << "]\n"; return;
        }
        else {
                for (std::deque<std::string>::reverse_iterator it = deq.rbegin();it!=deq.rend();it++) {
                        std::cout << *it;
                }
                std::cout << "]\n"; return;
        }
        return;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int t;  std::cin >> t;
        while (t--) {
                std::string p;
                int n;
                std::string list;
                std::cin >> p >> n >> list;
                std::deque<std::string> deq;
                std::string tmp="";
                int size = 0;
                for (char c: list) {
                        if (c>='0' && c<='9') {
                                tmp.push_back(c);
                                continue;}
                        if (c==',' || c==']') {
                                if (tmp!="") ++size;
                                deq.push_back(tmp);
                                tmp = "";
                        }
                        deq.push_back(std::string(1, c));
                }
                deq.pop_front(); deq.pop_back();
                algorithm(p, n, deq, size);
        }
        return 0;
}