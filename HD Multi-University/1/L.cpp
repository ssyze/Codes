/*
 * @Date         : 2020-07-22 22:42:49
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 1005;
inline int sgn(double x) { return (x > eps) - (x < -eps); }
struct point {
    double x, y;
    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator==(const point &b) const
    {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    point operator+(const point &b) const { return point(x + b.x, y + b.y); }
    point operator-(const point &b) const { return point(x - b.x, y - b.y); }
    bool operator<(const point &b) const
    {
        sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
    }
    double operator*(const point &b) const { return x * b.x + y * b.y; }  //点积
    double operator^(const point &b) const { return x * b.y - y * b.x; }  //叉积
    double len() { return hypot(x, y); }                                  //返回长度
    double len2() { return x * x + y * y; }  //返回长度平方
    double dis(const point &b) const { return hypot(x - b.x, y - b.y); }  //返回两点距离
    point operator*(const double &b) const { return point(x * b, y * b); }
    point operator/(const double &b) const { return point(x / b, y / b); }
    point left() { return point(-y, x); }   //逆时针90度
    point right() { return point(y, -x); }  //顺时针90度
    bool inPi() const { return sgn(y) == 1 || (sgn(y) == 0 && sgn(x) == -1); }  // 0 -> pi
    point unit(const double &r = 1.0)  //默认为单位化向量，参数为化长度为r的向量
    {
        double l = len();
        return sgn(l) == 0 ? point(r, 0) : point(x * r / l, y * r / l);
    }
};
int cmpAng(const point &a, const point &b)
{
    return a.inPi() < b.inPi() || (a.inPi() == b.inPi() && sgn(a ^ b) > 0);
}

bool checkLineLine(point p1, point p2, point p3, point p4)
{
    return sgn(((p3 - p1) ^ (p4 - p1)) - ((p3 - p2) ^ (p4 - p2))) != 0;
}

point getLineLine(point p1, point p2, point p3, point p4)
{
    double w1 = (p1 - p3) ^ (p4 - p3), w2 = (p4 - p3) ^ (p2 - p3);
    return (p1 * w2 + p2 * w1) / (w1 + w2);
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
    int relation(const point &p)  //点和直线关系 1 左 0 上 -1 右
    {
        return sgn((e - s) ^ (p - s)) > 0;
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
        return point((s.x * a2 - e.x * a1) / (a2 - a1),
                     (s.y * a2 - e.y * a1) / (a2 - a1));
    }
};
bool sameDir(line l1, line l2)
{
    return l1.parallel(l2) && sgn(l1.dir() * l2.dir()) == 1;
}
bool operator<(line l1, line l2)
{
    if (sameDir(l1, l2)) return l2.relation(l1.s);
    return cmpAng(l1.dir(), l2.dir());
}

point getLineLine(line l1, line l2) { return getLineLine(l1.s, l1.e, l2.s, l2.e); }

int checkpos(line l1, line l2, line l3) { return l3.relation(getLineLine(l1, l2)); }

double area(vector<point> p)  //多边形面积
{
    double ans = 0;
    for (int i = 0; i < p.size(); i++) ans += p[i] ^ p[(i + 1) % p.size()];
    return ans / 2;
}

double perimeter(vector<point> p)  // 多边形周长
{
    double ans = 0;
    for (int i = 0; i < p.size(); i++) ans += p[i].dis(p[(i + 1) % p.size()]);
    return ans;
}

bool checkConvex(vector<point> p)  // 判断凸
{
    int n = p.size();
    p.push_back(p[0]);
    p.push_back(p[1]);
    for (int i = 0; i < n; i++)
        if (sgn((p[i + 1] - p[i]) * (p[i + 2] - p[i])) == -1) return 0;
    return 1;
}

int contain(vector<point> p, point q)
{  // 0 外部 1 边界 2 内部
    int pd = 0;
    p.push_back(p[0]);
    for (int i = 1; i < p.size(); i++) {
        point u = p[i - 1], v = p[i];
        line l(u, v);
        if (l.pointonseg(q)) return 1;
        if (sgn(u.y - v.y) > 0) swap(u, v);
        if (sgn(u.y - q.y) >= 0 || sgn(v.y - q.y) < 0) continue;
        if (sgn((u - v) ^ (q - v)) < 0) pd ^= 1;
    }
    return pd << 1;
}

vector<point> getConvex(vector<point> p, int flag = 1)  // 凸包
{                                                       // flag = 1严格
    int n = p.size();
    vector<point> ans(2 * n);
    sort(p.begin(), p.end());
    int now = -1;
    for (int i = 0; i < p.size(); i++) {
        while (now > 0 && sgn((ans[now] - ans[now - 1]) ^ (p[i] - ans[now - 1])) < flag)
            now--;
        ans[++now] = p[i];
    }
    int pre = now;
    for (int i = n - 2; i >= 0; i--) {
        while (now > pre && sgn((ans[now] - ans[now - 1]) ^ (p[i] - ans[now - 1])) < flag)
            now--;
        ans[++now] = p[i];
    }
    ans.resize(now);
    return ans;
}

double convexDiameter(vector<point> p)  //凸包直径
{
    int now = 0, n = p.size();
    double ans = 0;
    for (int i = 0; i < p.size(); i++) {
        now = max(now, i);
        while (1) {
            double k1 = p[i].dis(p[now % n]), k2 = p[i].dis(p[(now + 1) % n]);
            ans = max(ans, max(k1, k2));
            if (k2 > k1)
                now++;
            else
                break;
        }
    }
    return ans;
}

vector<line> getHPI(vector<line> &L)
{  // 半平面交 按逆时针输出
    sort(L.begin(), L.end());
    deque<line> q;
    for (int i = 0; i < (int)L.size(); i++) {
        if (i && sameDir(L[i], L[i - 1])) continue;
        while (q.size() > 1 && !checkpos(q[q.size() - 2], q[q.size() - 1], L[i]))
            q.pop_back();
        while (q.size() > 1 && !checkpos(q[1], q[0], L[i])) q.pop_front();
        q.push_back(L[i]);
    }
    while (q.size() > 2 && !checkpos(q[q.size() - 2], q[q.size() - 1], q[0]))
        q.pop_back();
    while (q.size() > 2 && !checkpos(q[1], q[0], q[q.size() - 1])) q.pop_front();
    vector<line> ans;
    for (int i = 0; i < q.size(); i++) ans.push_back(q[i]);
    return ans;
}

double closepoint(vector<point> &p, int l, int r)
{  // 最近点对, 先按X排序
    if (r - l <= 5) {
        double ans = 1e20;
        for (int i = l; i <= r; i++) {
            for (int j = i + 1; j <= r; j++) {
                ans = min(ans, p[i].dis(p[j]));
            }
        }
        return ans;
    }
    int mid = (l + r) >> 1;
    double ans = min(closepoint(p, l, mid), closepoint(p, mid + 1, r));
    vector<point> B;
    for (int i = l; i <= r; i++) {
        if (abs(p[i].x - p[mid].x) <= ans) B.push_back(p[i]);
    }
    sort(B.begin(), B.end(), [](point k1, point k2) { return k1.y < k2.y; });
    for (int i = 0; i < B.size(); i++) {
        for (int j = i + 1; j < B.size() && B[j].y - B[i].y < ans; j++) {
            ans = min(ans, B[i].dis(B[j]));
        }
    }
    return ans;
}

int t, n, r, a, b;

int main()
{
    // freopen("mow.in", "r", stdin);
    // freopen("mow.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> r >> a >> b;
        vector<point> p;
        for (int i = 0; i < n; i++) {
            double xx, yy;
            cin >> xx >> yy;
            p.push_back(point(xx, yy));
        }
        double S = area(p);
        if (S < 0) reverse(p.begin(), p.end()), S = -S;
        double ans1 = S * a;
        vector<line> hp;
        for (int i = 0; i < n; i++) {
            point l = p[(i + 1) % n] - p[i];
            l = l.left().unit(r);
            hp.push_back(line(p[i] + l, p[(i + 1) % n] + l));
        }
        hp = getHPI(hp);
        vector<point> ans;
        for (int i = 0; i < hp.size(); i++)
            ans.push_back(getLineLine(hp[i], hp[(i + 1) % hp.size()]));
        if (ans.size() > 2) {
            double S1 = area(ans) + perimeter(ans) * r + pi * r * r;
            double ans2 = S1 * b + (S - S1) * a;
            ans1 = min(ans1, ans2);
        }
        printf("%.10lf\n", ans1);
    }
}

// a = s + c * r + pi * r ** 2