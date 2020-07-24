/*
 * @Date         : 2020-07-18 14:14:22
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-2;
int t;
struct point {
    double x, y;
    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}
    double operator^(const point &b) const { return x * b.y - y * b.x; }
    double len() { return x * x + y * y; }
} p[20];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        for (int i = 0; i < 20; i++) cin >> p[i].x >> p[i].y;
        int i, j;
        for (i = 0; i < 20; i++) {
            point line(p[i].x - p[(i + 19) % 20].x,
                       p[i].y - p[(i + 19) % 20].y);
            if (fabs(line.len() - 81.0) <= eps) break;
        }
        j = (i + 19) % 20;
        point x(p[1].x - p[0].x, p[1].y - p[0].y);
        point y(p[2].x - p[1].x, p[2].y - p[1].y);
        point l1(p[i].x - p[(i + 1) % 20].x, p[i].y - p[(i + 1) % 20].y);
        point l2(p[j].x - p[(j + 19) % 20].x, p[j].y - p[(j + 19) % 20].y);
        int r = 0;
        if ((x ^ y) < 0) r = 1;
        if (r) {
            if (l1.len() < l2.len())
                cout << "right" << endl;
            else
                cout << "left" << endl;
        }
        else {
            if (l1.len() > l2.len())
                cout << "right" << endl;
            else
                cout << "left" << endl;
        }
    }
}