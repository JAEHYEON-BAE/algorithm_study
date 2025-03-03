#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool Compare(const std::string &a, const std::string &b)
{
    if (a.size()==b.size()) return a<b;
    return a.size()<b.size();
}

long long power[12];
long long cnts[12];
void init()
{
    cnts[0]=0; cnts[1]=26;
    power[0]=1; power[1]=26;
    long long tmp=26LL;
    for (int i=2;i<12;++i) {
        tmp*=26LL;
        power[i]=tmp;
        cnts[i]=cnts[i-1]+tmp;
    }
}

std::string solve(long long n)
{
    std::string result="";
    int size=0;
    for (int i=11;i>=0;--i) {
        if (cnts[i]<=n) {
            size=i;
            n-=cnts[i];
            break; 
        }
    }
    for (int i=size;i>=0;--i) {
        result+=static_cast<char>(n/power[i]%26LL+static_cast<long long>('a'));
    }
    return result;
}

string solution(long long n, vector<string> bans) {
    --n;
    init();
    std::sort(bans.begin(), bans.end(), Compare);
    long long x=0;
    for (const std::string &s:bans) {
        int nn=s.size();
        long long cnt=cnts[nn-1];
        for (int i=0;i<nn;++i) {
            long long idx=s[i]-'a';
            cnt+=idx*power[nn-i-1];
        }
        if (cnt>n+x) {
            return solve(n+x);
        }
        ++x;
    }
    return solve(n+x);
}