/*
 * @Date         : 2020-07-28 14:43:14
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
const double pi = acos(-1.0);
const int maxn = 1005;
typedef long long ll;
inline int sgn(double x) { return (x > eps) - (x < -eps); }
struct point {
    double x, y;
    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator==(const point &b) const { return sgn(x - b.x) == 0 && sgn(y - b.y) == 0; }
    point operator+(const point &b) const { return point(x + b.x, y + b.y); }
    point operator-(const point &b) const { return point(x - b.x, y - b.y); }
    bool operator<(const point &b) const { sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x; }
    double operator*(const point &b) const { return x * b.x + y * b.y; }  //点积
    double operator^(const point &b) const { return x * b.y - y * b.x; }  //叉积
    double len() { return hypot(x, y); }                                  //返回长度
    double len2() { return x * x + y * y; }                               //返回长度平方
    double dis(const point &b) const { return hypot(x - b.x, y - b.y); }  //返回两点距离
    point operator*(const double &b) const { return point(x * b, y * b); }
    point operator/(const double &b) const { return point(x / b, y / b); }
    point left() { return point(-y, x); }   //逆时针90度
    point right() { return point(y, -x); }  //顺时针90度
    point Rotate(double a) { return point(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a)); }
    point unit(const double &r = 1.0)  //默认为单位化向量，参数为化长度为r的向量
    {
        double l = len();
        return sgn(l) == 0 ? point(r, 0) : point(x * r / l, y * r / l);
    }
} v1, v2, v3, a, b, c, ori;
bool checkLineLine(point p1, point p2, point p3, point p4)
{
    return sgn(((p3 - p1) ^ (p4 - p1)) - ((p3 - p2) ^ (p4 - p2))) != 0;
}

point getLineLine(point p1, point p2, point p3, point p4)
{
    double w1 = (p1 - p3) ^ (p4 - p3), w2 = (p4 - p3) ^ (p2 - p3);
    return (p1 * w2 + p2 * w1) / (w1 + w2);
}

int inmid(double k1, double k2, double k3)
{
    return sgn(k1 - k3) * sgn(k2 - k3) <= 0;
}  // k3 在 [k1,k2] 内

int inmid(point k1, point k2, point k3)
{
    return inmid(k1.x, k2.x, k3.x) && inmid(k1.y, k2.y, k3.y);
}

int onS(point k1, point k2, point q)  //点q在点k1,k2之间
{
    return inmid(k1, k2, q) && sgn((k1 - q) ^ (k2 - k1)) == 0;
}

struct line {
    point s, e;
    line() {}
    line(point _s, point _e) : s(_s), e(_e) {}
    // 点和倾斜角构造直线
    line(point p, double ang)
    {
        s = p;
        if (sgn(ang - pi / 2) == 0)
            e = (s + point(0, 1));
        else
            e = (s + point(1, tan(ang)));
    }
    // 构造ax + by = c
    line(double a, double b, double c)
    {
        if (sgn(a) == 0) {
            s = point(0, -c / b);
            e = point(1, -c / b);
        }
        else if (sgn(b) == 0) {
            s = point(-c / a, 0);
            e = point(-c / a, 1);
        }
        else {
            s = point(0, -c / b);
            e = point(1, (-c - a) / b);
        }
    }
    bool operator==(const line &v) { return (s == v.s) && (e == v.e); }
    double len() { return s.dis(e); }  // 返回长度
    double ang()                       // 返回倾斜角
    {
        double k = atan2(e.y - s.y, e.x - s.x);
        if (sgn(k) < 0) k += pi;
        if (sgn(k - pi) == 0) k -= pi;
        return k;
    }
    point dir() { return e - s; }
    int relation(const point &p)  //点和直线关系 1左 2右 3上
    {
        int c = sgn((p - s) ^ (e - s));
        if (c < 0)
            return 1;
        else if (c > 0)
            return 2;
        else
            return 3;
    }
    bool pointonseg(const point &p)  // 点在线段上
    {
        return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) ^ (p - e)) <= 0;
    }
    bool parallel(line v) { return sgn((e - s) ^ (v.e - v.s)) == 0; }  // 直线平行
    int cross(line v)  //线段相交 0不相交 1非规范相交 2规范相交
    {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        int d3 = sgn((v.e - v.s) ^ (s - v.s));
        int d4 = sgn((v.e - v.s) ^ (e - v.s));
        if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 2;
        return (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0) ||
               (d2 == 0 && sgn((v.s - s) * (v.s - e)) <= 0) ||
               (d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0) ||
               (d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
    }
    point crosspoint(line v)  //两直线交点
    {
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
        return point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
    // p在直线上投影
    point lineprog(point p) { return s + ((e - s) * ((e - s) * (p - s))) / ((e - s).len2()); }
    // p关于直线p的对称点
    point symmetrypoint(point p)
    {
        point q = lineprog(p);
        return point(2 * q.x - p.x, 2 * q.y - p.y);
    }
    double disPointLine(point p)
    {
        point q = lineprog(p);
        if (pointonseg(q))
            return q.dis(p);
        else
            return min(e.dis(p), s.dis(p));
    }
} ab, ac, bc;
bool sameDir(line l1, line l2) { return l1.parallel(l2) && sgn(l1.dir() * l2.dir()) == 1; }

point getLineLine(line l1, line l2) { return getLineLine(l1.s, l1.e, l2.s, l2.e); }

int checkpos(line l1, line l2, line l3) { return l3.relation(getLineLine(l1, l2)); }

double h;

int t, L, x, y, vx, vy, k;

long long cal(double ti)
{
    long long res = 0;
    double d1 = v1.y * ti + y;
    res += abs(floor(d1 / h));
    // if (d1 < 0) res++;
    double d2 = v2.y * ti + bc.disPointLine(ori);
    res += abs(floor(d2 / h));
    // if (d2 < 0) res++;
    double d3 = v3.y * ti + ac.disPointLine(ori);
    res += abs(floor(d3 / h));
    // if (d3 < 0) res++;
    // cout << res << endl;
    return res;
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d%d%d", &L, &x, &y, &vx, &vy, &k);
        ori = point(x, y);
        a = point(L / 2.0, 0);
        b = point(-L / 2.0, 0);
        c = point(0, L * sqrt(3) / 2.0);
        ab = line(a, b);
        ac = line(a, c);
        bc = line(b, c);
        h = L * sqrt(3) / 2.0;
        v1 = point(vx, vy);
        v2 = v1.Rotate(pi * 2.0 / 3);
        v3 = v1.Rotate(pi * -2.0 / 3);
        double l = 0.0, r = 1e12;
        while ((r - l) > eps) {
            double mid = (l + r) / 2.0;
            if (cal(mid) >= k)
                r = mid;
            else
                l = mid;
        }
        printf("%.8f\n", (l + r) / 2);
    }
}