/*
 * @Date         : 2020-02-13 13:55:43
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const double eps = 1e-8;
struct node {
    double x, y;
    double dis(node a)
    {
        return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
    }
};
node a[maxn];
int n;
bool check(double x)
{
    double mx = 0.0;
    int pos;
    node cur { x, 0.0 };
    for (int i = 0; i < n; i++) {
        if (cur.dis(a[i]) > mx) {
            mx = cur.dis(a[i]);
            if (a[i].x - x >= eps)
                pos = 1;
            else
                pos = 0;
        }
    }
    return pos;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    int tm = 500;
    double ans;
    double l = -10000, r = 10000;
    while (tm--) {
        double mid = (l + r) / 2;
        //cout << l << ' ' << r << ' ' << endl;
        if (check(mid)) {
            ans = mid;
            l = mid;
        }
        else
            r = mid;
    }
    double res = 0.0;
    node x { ans, 0.0 };
    for (int i = 0; i < n; i++) {
        if (x.dis(a[i]) - res > eps)
            res = x.dis(a[i]);
    }
    printf("%.6f\n", res + eps);
}