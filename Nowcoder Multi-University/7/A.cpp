/*
 * @Date         : 2020-08-01 15:04:42
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
const double pi = acos(-1.0);
const int maxn = 1005;
inline int sgn(double x) { return (x > eps) - (x < -eps); }
int t, n, r, ans;
vector<pair<int, int>> p[8];
vector<pair<int, int>> v;
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
} po[8];
void solve()
{
    int sum = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            int x = v[i].first - v[j].first;
            int y = v[i].second - v[j].second;
            sum += x * x + y * y;
        }
    }
    ans = max(ans, sum);
    /* if (sum > ans) {
        ans = sum;
        cout << sum << endl;
        for (auto &x : v) cout << x.first << ' ' << x.second << endl;
    } */
}
void dfs(int cur)
{
    if (cur >= n) {
        solve();
        return;
    }
    for (int i = 0; i < p[cur].size(); ++i) {
        v.push_back(p[cur][i]);
        dfs(cur + 1);
        v.pop_back();
    }
}
int main()
{
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        for (int i = 0; i < 8; i++) p[i].clear();
        v.clear();
        cin >> n >> r;
        po[0].x = r, po[0].y = 0, ans = 0;
        p[0].push_back({r, 0});
        double rad = 2 * pi / n;
        for (int i = 1; i < n; i++) {
            po[i] = po[i - 1].Rotate(rad);
            int Xdown = int(floor(po[i].x + eps)), Ydown = int(floor(po[i].y + eps));
            int Xup = int(ceil(po[i].x - eps)), Yup = int(ceil(po[i].y - eps));
            for (int j = Xdown - 22; j <= Xup + 22; j++) {
                for (int k = Ydown - 22; k <= Yup + 22; k++) {
                    if (j * j + k * k == r * r) p[i].push_back({j, k});
                }
            }
        }
        dfs(0);
        cout << ans << '\n';
    }
    // cout << (double)clock() / CLOCKS_PER_SEC << endl;
}