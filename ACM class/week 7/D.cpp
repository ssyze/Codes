/*
 * @Date         : 2020-03-04 16:55:15
 * @Author       : ssyze
 * @Description  : 
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const double eps = 1e-10;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 105;
int sgn(double x)
{
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}
inline double sqr(double x) { return x * x; }

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    void input()
    {
        scanf("%lf%lf", &x, &y);
    }
    void output()
    {
        printf("%.2f %.2f\n", x + eps, y + eps);
    }
    bool operator==(Point b) const
    {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    bool operator<(Point b) const
    {
        return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
    }
    Point operator-(const Point& b) const
    {
        return Point(x - b.x, y - b.y);
    }
    double operator^(const Point& b) const
    {
        return x * b.y - y * b.x;
    }
    double operator*(const Point& b) const
    {
        return x * b.x + y * b.y;
    }
    double distance(Point p)
    {
        return hypot(x - p.x, y - p.y);
    }
    Point operator/(const double& k) const
    {
        return Point(x / k, y / k);
    }
};
struct Line {
    Point s, e;
    Line() {}
    Line(Point _s, Point _e)
    {
        s = _s;
        e = _e;
    }
    bool operator==(Line v)
    {
        return (s == v.s) && (e == v.e);
    }
    void input()
    {
        s.input();
        e.input();
    }
};
struct polygon {
    int n;
    Point p[maxp];
    Line l[maxp];
    void input(int _n)
    {
        n = _n;
        for (int i = 0; i < n; i++)
            p[i].input();
    }
    void add(Point q) { p[n++] = q; }
    void getline()
    {
        for (int i = 0; i < n; i++) {
            l[i] = Line(p[i], p[(i + 1) % n]);
        }
    }
    struct cmp {
        Point p;
        cmp(const Point& p0) { p = p0; }
        bool operator()(const Point& aa, const Point& bb)
        {
            Point a = aa, b = bb;
            int d = sgn((a - p) ^ (b - p));
            if (d == 0) {
                return sgn(a.distance(p) - b.distance(p)) < 0;
            }
            return d > 0;
        }
    };
    void norm()
    {
        Point mi = p[0];
        for (int i = 1; i < n; i++)
            mi = min(mi, p[i]);
        sort(p, p + n, cmp(mi));
    }
    void getconvex(polygon& convex)
    {
        sort(p, p + n);
        convex.n = n;
        for (int i = 0; i < min(n, 2); i++) {
            convex.p[i] = p[i];
        }
        if (convex.n == 2 && (convex.p[0] == convex.p[1]))
            convex.n--;
        if (n <= 2)
            return;
        int& top = convex.n;
        top = 1;
        for (int i = 2; i < n; i++) {
            while (top && sgn((convex.p[top] - p[i]) ^ (convex.p[top - 1] - p[i])) <= 0)
                top--;
            convex.p[++top] = p[i];
        }
        int temp = top;
        convex.p[++top] = p[n - 2];
        for (int i = n - 3; i >= 0; i--) {
            while (top != temp && sgn((convex.p[top] - p[i]) ^ (convex.p[top - 1] - p[i])) <= 0)
                top--;
            convex.p[++top] = p[i];
        }
        if (convex.n == 2 && (convex.p[0] == convex.p[1]))
            convex.n--;
        convex.norm(); //原来得到的是顺时针的点，排序后逆时针
    }
};
int n;
int main()
{
    while (cin >> n && n) {
        polygon g, a;
        g.input(n);
        g.getconvex(a);
        if (a.n == 1) {
            double ans = 0.0;
            printf("%.2f\n", ans);
        }
        else if (a.n == 2) {
            printf("%.2f\n", a.p[0].distance(a.p[1]));
        }
        else {
            double ans = 0.0;
            for (int i = 0; i < a.n - 1; i++) {
                ans += a.p[i].distance(a.p[i + 1]);
            }
            ans += a.p[0].distance(a.p[a.n - 1]);
            printf("%.2f\n", ans);
        }
    }
}