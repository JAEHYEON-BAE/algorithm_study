#include <iostream>
#include <cmath>

int brute(int n, int r) 
{
    if (n<1 || 2*log(n)/log(3)<r) return 0;
    if (n==3) return r==2;
    int result=0;
    if (n%3==0 && r>=2) result+=brute(n/3, r-2);
    result+=brute(n-1, r+1);
    return result;
}

int solution(int n) {
    return brute(n-2, 2);
}