/*
 * @Date         : 2020-07-13 12:16:50
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const double eps = 1e-6;
int n, suma, sumb;
pair<int, int> p[maxn];
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int num(double x, double y)
{
    // cout << x << ' ' << y << endl;
    double r = x * x + y * y;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        double a = (x - p[i].first) * (x - p[i].first);
        double b = (y - p[i].second) * (y - p[i].second);
        if (fabs(a + b - r) <= eps) sum++;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        suma += p[i].first;
        sumb += p[i].second;
    }
    sort(p, p + n);
    int a = p[n / 2].first;
    sort(p, p + n, cmp);
    int b = p[n / 2].second;
    int ans = 0;
    // cout << a << ' ' << b << endl;
    for (double i = a - 25; i <= a + 25; i += 0.5) {
        for (double j = b - 25; j <= b + 25; j += 0.5) {
            ans = max(ans, num(i, j));
        }
    }
    a = suma / n;
    b = sumb / n;
    for (double i = a - 25; i <= a + 25; i += 0.5) {
        for (double j = b - 25; j <= b + 25; j += 0.5) {
            ans = max(ans, num(i, j));
        }
    }
    cout << ans << endl;
}