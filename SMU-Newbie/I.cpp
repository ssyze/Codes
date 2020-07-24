/*
 * @Date         : 2019-12-28 14:57:16
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double inf = 1e20;
const int maxn = 4e3 + 5;
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
};
struct Line {
    Point s, e;
    Line() {}
    Line(Point _s, Point _e)
    {
        s = _s;
        e = _e;
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
} l[maxn];
int par[maxn], rank1[maxn], n;
//初始化n个元素
void init(int n)
{
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank1[i] = 0;
    }
}
//find函数 用于查询当前节点的根节点
int find1(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find1(par[x]); //路径压缩
}
//合并x y所在集合
void Unite(int x, int y)
{
    x = find1(x);
    y = find1(y);
    if (x == y)
        return;
    if (rank1[x] < rank1[y])
        par[x] = y;
    else {
        par[y] = x;
        if (rank1[x] == rank1[y])
            rank1[x]++;
    }
}
int main()
{
    scanf("%d", &n);
    init(n);
    for (int i = 0; i < n; i++) {
        l[i].input();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            else {
                if (l[i].segcrossseg(l[j]))
                    Unite(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (par[i] == i)
            ans++;
    }
    cout << ans << endl;
}