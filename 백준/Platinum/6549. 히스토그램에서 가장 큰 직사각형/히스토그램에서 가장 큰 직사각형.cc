#include <iostream>
#include <vector>
#include <algorithm>
long long int dnq(const std::vector<long long int>& v, const int& s, const int& e)
{
        if (s==e)       {
                return v[s];
        }
        int mid = (s+e)/2;
        long long int left = dnq(v, s, mid);
        long long int right = dnq(v, mid+1, e);


        long long int merge = 2*std::min(v[mid], v[mid+1]);
        int l=mid, r=mid+1;
        long long int width = 2;
        long long int height = std::min(v[l], v[r]);
        while (s<=l && r<=e) {
                height = std::min(height, std::min(v[l], v[r]));
                merge = std::max(merge, height*width);
                if (l==s && r==e) break;
                if (s<l) {
                        if (r<e) {
                                if (height > v[l-1] && height > v[r+1]) {
                                        (v[r+1] > v[l-1]) ? ++r : --l;
                                        ++width;
                                } 
                                else {
                                        if (height <= v[l-1]) {--l; ++width;}
                                        if (height <= v[r+1]) {++r; ++width;}
                                }
                        }
                        else {--l; ++width;}
                }
                else {
                        if (r<e) {++r; ++width;}
                        else break;
                }
        }

        return std::max(merge, std::max(left, right));
}


int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        while (true) {
                int n;  std::cin >> n;
                if (n==0) break;
                std::vector<long long int> v(n);
                for (int i=0;i<n;i++) {
                        std::cin >> v[i];
                }
                std::cout << dnq(v, 0, n-1) << "\n";
        }
        return 0;
}