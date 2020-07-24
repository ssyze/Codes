/*
 * @Date         : 2020-07-24 01:48:04
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
typedef double db;
const db eps = 1e-6;
const db pi = acos(-1.0);
int sign(db k)
{
    if (k > eps)
        return 1;
    else if (k < -eps)
        return -1;
    return 0;
}
int cmp(db k1, db k2) { return sign(k1 - k2); }
int inmid(db k1, db k2, db k3) { return sign(k1 - k3) * sign(k2 - k3) <= 0; }  // k3 在 [k1,k2] 内
struct point {
    db x, y;
    point operator+(const point &k1) const { return (point){k1.x + x, k1.y + y}; }
    point operator-(const point &k1) const { return (point){x - k1.x, y - k1.y}; }
    point operator*(db k1) const { return (point){x * k1, y * k1}; }
    point operator/(db k1) const { return (point){x / k1, y / k1}; }
    int operator==(const point &k1) const { return cmp(x, k1.x) == 0 && cmp(y, k1.y) == 0; }
    // 逆时针旋转
    point turn(db k1) { return (point){x * cos(k1) - y * sin(k1), x * sin(k1) + y * cos(k1)}; }
    point turn90() { return (point){-y, x}; }
    bool operator<(const point k1) const  // x 为第一关键词 y 为第二关键词
    {
        int a = cmp(x, k1.x);
        if (a == -1)
            return 1;
        else if (a == 1)
            return 0;
        else
            return cmp(y, k1.y) == -1;
    }
    db abs() { return sqrt(x * x + y * y); }
    db abs2() { return x * x + y * y; }
    db dis(point k1) { return ((*this) - k1).abs(); }
    point unit()
    {
        db w = abs();
        return (point){x / w, y / w};
    }
    void scan()
    {
        double k1, k2;
        scanf("%lf%lf", &k1, &k2);
        x = k1;
        y = k2;
    }
    void print() { printf("%.11lf %.11lf\n", x, y); }
    db getw() { return atan2(y, x); }
    point getdel()
    {
        if (sign(x) == -1 || (sign(x) == 0 && sign(y) == -1))
            return (*this) * (-1);
        else
            return (*this);
    }
    int getP() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) == -1); }
};
int inmid(point k1, point k2, point k3)
{
    return inmid(k1.x, k2.x, k3.x) && inmid(k1.y, k2.y, k3.y);
}
db cross(point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
db dot(point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }
db rad(point k1, point k2) { return atan2(cross(k1, k2), dot(k1, k2)); }
// -pi -> pi
bool compareangle(const point &k1, const point &k2)
{
    return k1.getP() < k2.getP() || (k1.getP() == k2.getP() && sign(cross(k1, k2)) > 0);
}
/* pair<bool, pair<point, point>> getAA(point k1, point k2, point k3, point k4)
{  //求角度向量 [k1,k2]是否交角度向量[k3,k4] 返回是否交和交集
    vector<tuple<point, int, int>> v = {make_tuple(k1, 0, 1), make_tuple(k2, 0, -1),
                                        make_tuple(k3, 1, 1), make_tuple(k4, 1, -1)};
    sort(v.begin(), v.end(), [](auto &k1, auto &k2) {
        if (get<0>(k1).getP() == get<0>(k2).getP() && sign(cross(get<0>(k1), get<0>(k2))) == 0)
            return get<2>(k1) > get<2>(k2);
        return compareangle(get<0>(k1), get<0>(k2));
    });
    int cnt = 0;
    vector<bool> meet(2);
    for (auto [angle, id, t] : v) {
        if (!meet[id] && t == -1) cnt++;
        meet[id] = true;
    }
    if (cnt == 2) return make_pair(true, make_pair(get<0>(v.back()), get<0>(v.front())));
    for (int i = 0; i < v.size(); i++) {
        cnt += get<2>(v[i]);
        if (cnt == 2)
            return make_pair(true, make_pair(get<0>(v[i]), get<0>(v[(i + 1) % v.size()])));
    }
    return make_pair(false, make_pair(k1, k2));
} */
point proj(point k1, point k2, point q)
{  // q 到直线 k1,k2 的投影
    point k = k2 - k1;
    return k1 + k * (dot(q - k1, k) / k.abs2());
}
point reflect(point k1, point k2, point q)
{
    return proj(k1, k2, q) * 2 - q;
}  // q 对于直线 k1,k2 的对称点
int clockwise(point k1, point k2, point k3)
{  // k1 k2 k3 逆时针 1 顺时针 -1 否则 0
    return sign(cross(k2 - k1, k3 - k1));
}
int checkLL(point k1, point k2, point k3, point k4)
{  // 求直线 (L) 线段 (S)k1,k2 和 k3,k4 的交点
    return cmp(cross(k3 - k1, k4 - k1), cross(k3 - k2, k4 - k2)) != 0;
}
point getLL(point k1, point k2, point k3, point k4)
{
    db w1 = cross(k1 - k3, k4 - k3), w2 = cross(k4 - k3, k2 - k3);
    return (k1 * w2 + k2 * w1) / (w1 + w2);
}
int intersect(db l1, db r1, db l2, db r2)
{
    if (l1 > r1) swap(l1, r1);
    if (l2 > r2) swap(l2, r2);
    return cmp(r1, l2) != -1 && cmp(r2, l1) != -1;
}
int checkSS(point k1, point k2, point k3, point k4)
{  // 非规范相交 <= 0 ; 规范相交 < 0
    return intersect(k1.x, k2.x, k3.x, k4.x) && intersect(k1.y, k2.y, k3.y, k4.y) &&
           sign(cross(k3 - k1, k4 - k1)) * sign(cross(k3 - k2, k4 - k2)) <= 0 &&
           sign(cross(k1 - k3, k2 - k3)) * sign(cross(k1 - k4, k2 - k4)) <= 0;
}
db disSP(point k1, point k2, point q)
{  // 点 ( q ) 到线段 ( k1 , k2 ) 距离
    point k3 = proj(k1, k2, q);
    if (inmid(k1, k2, k3))
        return q.dis(k3);
    else
        return min(q.dis(k1), q.dis(k2));
}
db disSS(point k1, point k2, point k3, point k4)
{
    if (checkSS(k1, k2, k3, k4))
        return 0;
    else
        return min(min(disSP(k1, k2, k3), disSP(k1, k2, k4)),
                   min(disSP(k3, k4, k1), disSP(k3, k4, k2)));
}
int onS(point k1, point k2, point q)  //点q在点k1,k2之间
{
    return inmid(k1, k2, q) && sign(cross(k1 - q, k2 - k1)) == 0;
}
struct circle {
    point o;
    db r;
    void scan()
    {
        o.scan();
        scanf("%lf", &r);
    }
    int inside(point k) { return cmp(r, o.dis(k)); }
};
struct line {
    // p[0]->p[1]
    point p[2];
    line(point k1, point k2)
    {
        p[0] = k1;
        p[1] = k2;
    }
    point &operator[](int k) { return p[k]; }
    int include(point k) { return sign(cross(p[1] - p[0], k - p[0])) > 0; }
    point dir() { return p[1] - p[0]; }
    line push()
    {  // 向外 ( 左手边 ) 平移 eps
        const db eps = 1e-6;
        point delta = (p[1] - p[0]).turn90().unit() * eps;
        return {p[0] - delta, p[1] - delta};
    }
    line push(db k)
    {  //向内平移k
        point delta = (p[1] - p[0]).turn90().unit() * k;
        return {p[0] + delta, p[1] + delta};
    }
};
point getLL(line k1, line k2) { return getLL(k1[0], k1[1], k2[0], k2[1]); }
int parallel(line k1, line k2) { return sign(cross(k1.dir(), k2.dir())) == 0; }
int sameDir(line k1, line k2) { return parallel(k1, k2) && sign(dot(k1.dir(), k2.dir())) == 1; }
int operator<(line k1, line k2)
{
    if (sameDir(k1, k2)) return k2.include(k1[0]);
    return compareangle(k1.dir(), k2.dir());
}
int checkpos(line k1, line k2, line k3) { return k3.include(getLL(k1, k2)); }

int checkposCC(circle k1, circle k2)
{  // 返回两个圆的公切线数量
    if (cmp(k1.r, k2.r) == -1) swap(k1, k2);
    db dis = k1.o.dis(k2.o);
    int w1 = cmp(dis, k1.r + k2.r), w2 = cmp(dis, k1.r - k2.r);
    if (w1 > 0)
        return 4;
    else if (w1 == 0)
        return 3;
    else if (w2 > 0)
        return 2;
    else if (w2 == 0)
        return 1;
    else
        return 0;
}
vector<point> getCL(circle k1, point k2, point k3)
{  // 沿着 k2->k3 方向给出 , 相切给出两个
    point k = proj(k2, k3, k1.o);
    db d = k1.r * k1.r - (k - k1.o).abs2();
    if (sign(d) == -1) return {};
    point del = (k3 - k2).unit() * sqrt(max((db)0.0, d));
    return {k - del, k + del};
}
vector<point> getCC(circle k1, circle k2)
{  // 沿圆 k1 逆时针给出 , 相切给出两个
    int pd = checkposCC(k1, k2);
    if (pd == 0 || pd == 4) return {};
    db a = (k2.o - k1.o).abs2(),
       cosA = (k1.r * k1.r + a - k2.r * k2.r) / (2 * k1.r * sqrt(max(a, (db)0.0)));
    db b = k1.r * cosA, c = sqrt(max((db)0.0, k1.r * k1.r - b * b));
    point k = (k2.o - k1.o).unit(), m = k1.o + k * b, del = k.turn90() * c;
    return {m - del, m + del};
}
vector<point> TangentCP(circle k1, point k2)
{  // 沿圆 k1 逆时针给出
    db a = (k2 - k1.o).abs(), b = k1.r * k1.r / a, c = sqrt(max((db)0.0, k1.r * k1.r - b * b));
    point k = (k2 - k1.o).unit(), m = k1.o + k * b, del = k.turn90() * c;
    return {m - del, m + del};
}
vector<line> TangentoutCC(circle k1, circle k2)
{
    int pd = checkposCC(k1, k2);
    if (pd == 0) return {};
    if (pd == 1) {
        point k = getCC(k1, k2)[0];
        return {(line){k, k}};
    }
    if (cmp(k1.r, k2.r) == 0) {
        point del = (k2.o - k1.o).unit().turn90().getdel();
        return {(line){k1.o - del * k1.r, k2.o - del * k2.r},
                (line){k1.o + del * k1.r, k2.o + del * k2.r}};
    }
    else {
        point p = (k2.o * k1.r - k1.o * k2.r) / (k1.r - k2.r);
        vector<point> A = TangentCP(k1, p), B = TangentCP(k2, p);
        vector<line> ans;
        for (int i = 0; i < A.size(); i++) ans.push_back((line){A[i], B[i]});
        return ans;
    }
}
vector<line> TangentinCC(circle k1, circle k2)
{
    int pd = checkposCC(k1, k2);
    if (pd <= 2) return {};
    if (pd == 3) {
        point k = getCC(k1, k2)[0];
        return {(line){k, k}};
    }
    point p = (k2.o * k1.r + k1.o * k2.r) / (k1.r + k2.r);
    vector<point> A = TangentCP(k1, p), B = TangentCP(k2, p);
    vector<line> ans;
    for (int i = 0; i < A.size(); i++) ans.push_back((line){A[i], B[i]});
    return ans;
}
vector<line> TangentCC(circle k1, circle k2)
{
    int flag = 0;
    if (k1.r < k2.r) swap(k1, k2), flag = 1;
    vector<line> A = TangentoutCC(k1, k2), B = TangentinCC(k1, k2);
    for (line k : B) A.push_back(k);
    if (flag)
        for (line &k : A) swap(k[0], k[1]);
    return A;
}
db getarea(circle k1, point k2, point k3)
{
    // 圆 k1 与三角形 k2 k3 k1.o 的有向面积交
    point k = k1.o;
    k1.o = k1.o - k;
    k2 = k2 - k;
    k3 = k3 - k;
    int pd1 = k1.inside(k2), pd2 = k1.inside(k3);
    vector<point> A = getCL(k1, k2, k3);
    if (pd1 >= 0) {
        if (pd2 >= 0) return cross(k2, k3) / 2;
        return k1.r * k1.r * rad(A[1], k3) / 2 + cross(k2, A[1]) / 2;
    }
    else if (pd2 >= 0) {
        return k1.r * k1.r * rad(k2, A[0]) / 2 + cross(A[0], k3) / 2;
    }
    else {
        int pd = cmp(k1.r, disSP(k2, k3, k1.o));
        if (pd <= 0) return k1.r * k1.r * rad(k2, k3) / 2;
        return cross(A[0], A[1]) / 2 + k1.r * k1.r * (rad(k2, A[0]) + rad(A[1], k3)) / 2;
    }
}
circle getcircle(point k1, point k2, point k3)
{
    // 三点求圆
    db a1 = k2.x - k1.x, b1 = k2.y - k1.y, c1 = (a1 * a1 + b1 * b1) / 2;
    db a2 = k3.x - k1.x, b2 = k3.y - k1.y, c2 = (a2 * a2 + b2 * b2) / 2;
    db d = a1 * b2 - a2 * b1;
    point o = (point){k1.x + (c1 * b2 - c2 * b1) / d, k1.y + (a1 * c2 - a2 * c1) / d};
    return (circle){o, k1.dis(o)};
}
circle getScircle(vector<point> A)
{
    //随机增量法 最小圆覆盖
    random_shuffle(A.begin(), A.end());
    circle ans = (circle){A[0], 0};
    for (int i = 1; i < A.size(); i++)
        if (ans.inside(A[i]) == -1) {
            ans = (circle){A[i], 0};
            for (int j = 0; j < i; j++)
                if (ans.inside(A[j]) == -1) {
                    ans.o = (A[i] + A[j]) / 2;
                    ans.r = ans.o.dis(A[i]);
                    for (int k = 0; k < j; k++)
                        if (ans.inside(A[k]) == -1) ans = getcircle(A[i], A[j], A[k]);
                }
        }
    return ans;
}

int main()
{
    point p[5];
    p[0].x = 0, p[0].y = 0;
    p[1].x = 1, p[1].y = 0;
    p[2].x = 1, p[2].y = 1;
    p[3].x = 0, p[3].y = 1;
    vector<line> l;
    l.pb(line(p[0], p[2]));
    l.pb(line(p[0], p[1]));
    l.pb(line(p[0], p[3]));
    sort(l.begin(), l.end());
    for (auto &i : l) {
        cout << i[1].x << ' ' << i[1].y << endl;
    }
}