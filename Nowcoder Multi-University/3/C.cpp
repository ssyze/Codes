/*
 * @Date         : 2020-07-18 13:23:40
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
    double len() { return hypot(x, y); }
} p[20];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        for (int i = 0; i < 20; i++) cin >> p[i].x >> p[i].y;
        int r = 0;
        point x(p[1].x - p[0].x, p[1].y - p[0].y);
        point y(p[2].x - p[1].x, p[2].y - p[1].y);
        if ((x ^ y) < 0) r = 1;
        if (r) {
            int flag = 0, i;
            for (i = 1; i < 20; i++) {
                point line(p[i].x - p[i - 1].x, p[i].y - p[i - 1].y);
                if (fabs(line.len() - 9.0) <= eps) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                point line(p[i].x - p[(i + 1) % 20].x,
                           p[i].y - p[(i + 1) % 20].y);
                if (fabs(line.len() - 6.0) <= eps) {
                    cout << "right" << '\n';
                    continue;
                }
                else {
                    cout << "left" << '\n';
                    continue;
                }
            }
            else {
                point line(p[18].x - p[19].x, p[18].y - p[19].y);
                if (fabs(line.len() - 8.0) <= eps) {
                    cout << "right" << '\n';
                    continue;
                }
                else {
                    cout << "left" << '\n';
                    continue;
                }
            }
        }
        else {
            int flag = 0, i;
            for (i = 1; i < 20; i++) {
                point line(p[i].x - p[i - 1].x, p[i].y - p[i - 1].y);
                if (fabs(line.len() - 9.0) <= eps) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                point line(p[i].x - p[(i + 1) % 20].x,
                           p[i].y - p[(i + 1) % 20].y);
                if (fabs(line.len() - 8.0) <= eps) {
                    cout << "right" << '\n';
                    continue;
                }
                else {
                    cout << "left" << '\n';
                    continue;
                }
            }
            else {
                point line(p[18].x - p[19].x, p[18].y - p[19].y);
                if (fabs(line.len() - 6.0) <= eps) {
                    cout << "right" << '\n';
                    continue;
                }
                else {
                    cout << "left" << '\n';
                    continue;
                }
            }
        }
    }
}