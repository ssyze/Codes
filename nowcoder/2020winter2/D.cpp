#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 2005;
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
    int x, y;
    Point() {}
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    void input()
    {
        scanf("%lld%lld", &x, &y);
    }
    void output()
    {
        printf("%.2f %.2f\n", x + eps, y + eps);
    }
    bool operator==(Point b) const
    {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    bool operator<(const Point& t) const
    { /// 极角排序
        bool up[2] = { 0, 0 };
        if (y > 0 || (y == 0 && x > 0))
            up[0] = 1;
        if (t.y > 0 || (t.y == 0 && t.x > 0))
            up[1] = 1;
        if (up[0] ^ up[1])
            return up[0];
        return (*this) ^ t ? ((*this) ^ t) > 0 : ((*this) * (*this)) < (t * t);
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
    double rad(Point a, Point b)
    {
        Point p = *this;
        return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p)));
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
    int segcrossseg(Line v)
    {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        int d3 = sgn((v.e - v.s) ^ (s - v.s));
        int d4 = sgn((v.e - v.s) ^ (e - v.s));
        if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)
            return 2;
        return (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0) || (d2 == 0 && sgn((v.e - s) * (v.e - e)) <= 0) || (d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0) || (d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
    }
    bool parallel(Line v)
    {
        return sgn((e - s) ^ (v.e - v.s)) == 0;
    }
    bool pointonseg(Point p)
    {
        return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) * (p - e)) <= 0;
    }
    int relation(Point p)
    {
        int c = sgn((p - s) ^ (e - s));
        if (c < 0)
            return 1;
        else if (c > 0)
            return 2;
        else
            return 3;
    }
    int linecrossline(Line v)
    {
        if ((*this).parallel(v))
            return v.relation(s) == 3;
        return 2;
    }
    Point crosspoint(Line v)
    {
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
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
    int relationpoint(Point q)
    {
        for (int i = 0; i < n; i++) {
            if (p[i] == q)
                return 3;
        }
        getline();
        for (int i = 0; i < n; i++) {
            if (l[i].pointonseg(q))
                return 2;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            int k = sgn((q - p[j]) ^ (p[i] - p[j]));
            int u = sgn(p[i].y - q.y);
            int v = sgn(p[j].y - q.y);
            if (k > 0 && u < 0 && v >= 0)
                cnt++;
            if (k < 0 && v < 0 && u >= 0)
                cnt--;
        }
        return cnt != 0;
    }
    Point getbarycentre()
    {
        Point ret(0, 0);
        double area = 0;
        for (int i = 1; i < n - 1; i++) {
            double tmp = (p[i] - p[0]) ^ (p[i + 1] - p[0]);
            if (sgn(tmp) == 0)
                continue;
            area += tmp;
            ret.x += (p[0].x + p[i].x + p[i + 1].x) / 3 * tmp;
            ret.y += (p[0].y + p[i].y + p[i + 1].y) / 3 * tmp;
        }
        if (sgn(area))
            ret = ret / area;
        return ret;
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
};
int n;
Point p[maxp], v[maxp * 2];
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        p[i].input();
    int ans = n * (n - 1) * (n - 2) / 6, tmp = 0;
    int ans1 = ans;
    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            else
                v[num++] = p[j] - p[i];
        }
        sort(v, v + num);
        for (int j = 0; j < num; j++)
            v[j + num] = v[j];
        int num1 = 0;
        for (int j = 1; j < num; j++) {
            if ((v[j - 1] ^ v[j]) == 0 && (v[j - 1] * v[j]) > 0)
                num1++;
            else
                num1 = 0;
            tmp += num1;
        }
        int p1 = 0, p2 = 0;
        for (int j = 0; j < num; j++) {
            while (p1 <= j || (p1 < j + num && (v[p1] ^ v[j]) < 0 && (v[p1] * v[j]) >= 0))
                p1++;
            while (p2 <= j || (p2 < j + num && (v[p2] ^ v[j]) < 0))
                p2++;
            ans1 -= p2 - p1;
        }
    }
    cout << ans - (ans1 - tmp / 2) - tmp / 2 << endl;
}