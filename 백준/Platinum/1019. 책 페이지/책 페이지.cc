#include <iostream>
#include <string>
#include <vector>
int power(int base, int n)
{
        if (n==1) return base;
        if (n==0) return 1;
        if (n&1) {
                return base*power(base, n/2)*power(base, n/2);
        }
        else return power(base, n/2) * power(base, n/2);
}
void _000to999(int digit, int n, std::vector<int>& answer)
{
        for (int&x : answer) {
                x += n*digit*power(10, digit-1);
        }
//      std::cout << "\tall += " << n*digit*power(10, digit-1) << std::endl;
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n;  std::cin >> n;
        std::string str = std::to_string(n);
        std::vector<int> answer(10);

        int digit = str.size();

        for (int i=0;i<digit;++i) {
                int p = power(10, i);
//              std::cout << "P: " << p << std::endl;
                int number = (n/p)%10;
                for (int j=digit-1;j>i;--j) {
                        answer[(n/power(10, j))%10] += number * p;
//                      std::cout << "For HIGHER digits:\n";
//                      std::cout << "\tanswer[" << (n/power(10, j))%10 << "] += " << '(' << number << ") * (" << p << ')' << std::endl;
                }
//              std::cout << "----------------------------------------------------" << std::endl;
                for (int j=0;j<number;++j) {
                        answer[j] += p;
//                      std::cout << "For SELF digits:\n";
//                      std::cout << "\tanswer[" << j << "] += " << '(' << p << ')' << std::endl;
                }
//              std::cout << "----------------------------------------------------" << std::endl;

                if (i>0) {
//                      std::cout << "For LOWER digits:\n";
                        _000to999(i, number, answer);
                }

                answer[number]++;
                answer[0] -= p;
        }

        for (const int& x: answer) {
                std::cout << x << ' ';
        }

        return 0;
}