/*
 * @Date         : 2020-07-15 12:47:01
 * @Author       : ssyze
 * @Description  : O(n^2)遍历每个点，算出角度存下来，再取众数
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const double eps = 1e-12;
int n, ans;
struct point {
    double x, y;
    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}
    double operator*(const point &b) const { return x * b.x + y * b.y; }
    double operator^(const point &b) const { return x * b.y - y * b.x; }
    double len() { return hypot(x, y); }
} p[maxn];
int solve(int now)
{
    vector<double> v;
    for (int i = 0; i < n; i++) {
        if (i == now || p[now] ^ p[i] >= 0) continue;
        point x(p[i].x - p[now].x, p[i].y - p[now].y);
        double ang = p[i] * x / p[i].len() / x.len();
        v.push_back(ang);
    }
    sort(v.begin(), v.end());
    int cnt = 1, sum = 0;
    if (!v.empty()) {
        for (int i = 1; i < v.size(); i++) {
            if (fabs(v[i] - v[i - 1]) < eps)
                cnt++;
            else
                sum = max(sum, cnt), cnt = 1;
        }
        sum = max(sum, cnt);
    }
    return sum + 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    for (int i = 0; i < n; i++) ans = max(ans, solve(i));
    cout << ans << endl;
}