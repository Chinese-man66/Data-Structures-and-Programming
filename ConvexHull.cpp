#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point {
public:
    double x, y;

    Point(double x=0, double y=0): x(x), y(y) {}
    bool operator <(const Point& rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }

    Point operator -(const Point& rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }

    double operator ^(const Point& rhs) const {
        return x * rhs.y - y * rhs.x;
    }
};

class ConvexHull {
private:
    vector<Point> points;

public:
    ConvexHull(const vector<Point>& points): points(points) {}

    vector<Point> solve() {
        sort(points.begin(), points.end());
        vector<Point> result(points.size() * 2);
        int top = 0;

        for (int i = 0; i < points.size(); i++) {
            while (top > 1 && ((result[top - 1] - result[top - 2]) ^ (points[i] - result[top - 2])) < 0) {
                top--;
            }
            result[top++] = points[i];
        }

        for (int i = points.size() - 2, t = top; i >= 0; i--) {
        while (top > t && ((result[top - 1] - result[top - 2]) ^ (points[i] - result[top - 2])) < 0) {
                top--;
            }
            result[top++] = points[i];
        }

        result.resize(top - 2);
        return result;
    }
};

int main() {
    cout << "2125120058 申顺琦" << endl;
    vector<Point> points = {
        Point(0, 0), Point(1, -4), Point(-1, -5), Point(-5, -3), 
        Point(-3, -1), Point(-1, -3), Point(-2, -2), Point(-1, -1),
        Point(-2, -1), Point(-1, 1)
    };

    ConvexHull hull(points);

    vector<Point> result = hull.solve();

    cout << "Convex hull:" << endl;
    for (auto& point : result) {
        cout << "(" << point.x << ", " << point.y << ")" << endl;
    }

    return 0;
}