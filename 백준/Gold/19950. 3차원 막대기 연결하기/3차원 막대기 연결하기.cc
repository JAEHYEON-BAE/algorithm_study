// 19950

#include <iostream>
#include <algorithm>
#include <vector>

struct Point
{
  long long x, y;

  long long operator-(const Point& other) const {
    return (x-other.x)*(x-other.x)+(y-other.y)*(y-other.y);
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int x1, y1, z1, x2, y2, z2, n;
  std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> n;
  std::vector<int> sticks(n);

  int longest = 0, sum = 0;
  for (int i=0;i<n;++i) {
    std::cin >> sticks[i];
    sum+=sticks[i];  longest = std::max(longest, sticks[i]);
  }

  int dist = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1);

  if (dist<=sum*sum && ((longest*2<sum) || (longest*2-sum)*(longest*2-sum)<=dist)) std::cout << "YES";
  else std::cout << "NO";
}

