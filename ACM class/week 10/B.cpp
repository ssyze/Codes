/*
 * @Date         : 2020-03-25 16:25:07
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
#define sgn(x) (fabs(x) < eps ? 0 : ((x) < 0 ? -1 : 1))
#define zero(x) ((fabs(x) < eps ? 1 : 0))
using namespace std;
typedef long long ll;
const double eps = 1e-7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 100;

struct point {
    double x, y;
    point(double a = 0, double b = 0) { x = a, y = b; }
    point operator-(const point& b) const { return point(x - b.x, y - b.y); }
    point operator+(const point& b) const { return point(x + b.x, y + b.y); } // 两点是否重合
    bool operator==(point& b) { return zero(x - b.x) && zero(y - b.y); } // 点积(以原点为基准)
    double operator*(const point& b) const { return x * b.x + y * b.y; } // 叉积(以原点为基准)
    double operator^(const point& b) const { return x * b.y - y * b.x; } // 绕P点逆时针旋转a弧度后的点
    point rotate(point b, double a)
    {
        double dx, dy;
        (*this - b).split(dx, dy);
        double tx = dx * cos(a) - dy * sin(a);
        double ty = dx * sin(a) + dy * cos(a);
        return point(tx, ty) + b;
    } // 点坐标分别赋值到a和b
    void split(double& a, double& b) { a = x, b = y; }
};

bool isconvex(point poly[], int n)
{
    bool s[3];
    memset(s, 0, sizeof(s));
    for (int i = 0; i < n; i++) {
        s[sgn((poly[(i + 1) % n] - poly[i]) ^ (poly[(i + 2) % n] - poly[i])) + 1] = 1;
        if (s[0] && s[2])
            return 0;
    }
    return 1;
}

double area(point p[], int n)
{
    double res = 0;
    for (int i = 0; i < n; i++)
        res += (p[i] ^ p[(i + 1) % n]) / 2;
    return fabs(res);
}
int t, Case;
point p[4];
int main()
{
    cin >> t;
    while (t--) {
        for (int i = 0; i < 4; i++)
            cin >> p[i].x >> p[i].y;
        printf("Case %d:\n", ++Case);
        if (isconvex(p, 4))
            printf("%.1f Convex\n", area(p, 4));
        else
            printf("%.1f Concave\n", area(p, 4));
    }
}