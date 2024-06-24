#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
struct Point
{
        int x, y;

        bool operator< (const Point& other) const 
        {
                double angleA = atan2(y, x);
                double angleB = atan2(other.y, other.x);
                if (angleA==angleB) {
                        if (y==other.y) return x<other.x;
                        else return y<other.y;
                } else return angleA < angleB;
        }
};
Point min_p(const std::vector<Point>& points)
{
        int x_min=40001, y_min=40001;
        for (Point p: points) {
                if (p.y < y_min) {
                        y_min = p.y;
                        x_min = p.x;
                } else if (p.y==y_min && p.x < x_min) {
                        x_min = p.x;
                }
        }
        return {x_min, y_min};
}
bool CCW(Point a, Point b, Point c)
{
        return (static_cast<long long int>(b.x-a.x))*(static_cast<long long int>(c.y-a.y)) > (static_cast<long long int>(b.y-a.y))*(static_cast<long long int>(c.x-a.x));
}
/*
void printPoints(const std::vector<Point>& p)
{
        std::cout << "Points: ";
        for (Point x: p) {
                std::cout << '(' << x.x << ", " << x.y << ") ";
        }
        std::cout << std::endl;
}
void printStack(std::stack<Point> p)
{
        std::cout << "------STACK------\n";
        while (!p.empty()) {
                std::cout << '(' << p.top().x << ", " << p.top().y << ')' << std::endl;
                p.pop();
        }
        std::cout << "-----------------" << std::endl;
}
*/
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n;  std::cin >> n;
        std::vector<Point> points(n);

        for (int i=0;i<n;++i) {
                int x, y;
                std::cin >> x >> y;
                points[i].x = x;
                points[i].y = y;
        }

        Point min = min_p(points);

        for (Point& p: points) {
                p.x -= min.x;
                p.y -= min.y;
        }

        std::sort(points.begin(), points.end());
        points.push_back(points[0]);

//      printPoints(points);

        std::stack<Point> stk;
        std::pair<Point, Point> v;
//      printStack(stk);
        for (int i=0;i<n;++i) {
//              std::cout << "STACK SIZE: " << stk.size() << std::endl;

                Point p = points[i];

                if (stk.size()==0) {
                        stk.push(p);
                        v.first = p;
                } else if (stk.size()==1) {
                        stk.push(p);
                        v.second = p;
                } else if (CCW(v.first, v.second, p)) {
                        v.first = stk.top();
                        v.second = p;
                        stk.push(p);
                } else {
                        stk.pop();
                        --i;
                        if (stk.size()>=2) {
                                v.second = stk.top();
                                stk.pop();
                                v.first = stk.top();
                                stk.push(v.second);
                        }
                }
//              printStack(stk);
//              std::cout << "v: " << "((" << v.first.x << ", " << v.first.y << "), (" << v.second.x << ", " << v.second.y << "))\n\n";
        }
        std::cout << stk.size();
        return 0;
}