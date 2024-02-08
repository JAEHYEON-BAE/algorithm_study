#include <iostream>
int power(const int a, const int b)
{
        if (b==0) return 1;
        if (a==0) return 0;
        if (a==1) return 1;
        int tmp = power(a, b/2);
        if (b%2==0)     return tmp*tmp;
        else return tmp*tmp*a;
}
int find(const int n, const int r, const int c)
{
        if (n==0) return 0;
        int mid = power(2, n-1);
        if (r<mid && c<mid) return find(n-1, r, c);
        else if (r<mid && c>=mid) return mid*mid + find(n-1, r, c-mid);
        else if (r>=mid && c<mid) return mid*mid*2 + find(n-1, r-mid, c);
        else return mid*mid*3 + find(n-1, r-mid, c-mid);
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, r, c;
        std::cin >> n >> r >> c;
        std::cout << find(n, r, c);
        return 0;
}