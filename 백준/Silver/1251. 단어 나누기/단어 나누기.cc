#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string input;
vector<string> temps;

void tempReverse(int i, int j) {
        string temp = input;
        reverse(temp.begin(), temp.begin() + i+1);
        reverse(temp.begin() + i+1, temp.begin() + j+1);
        reverse(temp.begin() + j+1, temp.end());

        temps.push_back(temp);
}
int main()
{
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);

        cin >> input;
        int len =(int) input.length();
        for (int i=0; i<len-2; i++) {
                for (int j=i+1; j<len-1; j++) {
                        tempReverse(i, j);
                }
        }
        sort(temps.begin(), temps.end());
        cout << temps[0];
}