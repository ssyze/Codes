/*
 * @Date         : 2020-04-01 15:03:59
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, d, x[3][2];
int main()
{
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        cin >> x[0][0] >> x[0][1] >> x[1][0] >> x[1][1] >> x[2][0] >> x[2][1];
        if (x[1][0] == x[2][0] && (a || b)) {
            cout << "NO" << endl;
            continue;
        }
        if (x[1][1] == x[2][1] && (c || d)) {
            cout << "NO" << endl;
            continue;
        }
        int tmpx = abs(a - b), tmpy = abs(c - d);
        if (a > b) {
            if (x[0][0] - tmpx < x[1][0]) {
                cout << "NO" << endl;
                continue;
            }
        }
        else {
            if (x[0][0] + tmpx > x[2][0]) {
                cout << "NO" << endl;
                continue;
            }
        }
        if (c > d) {
            if (x[0][1] - tmpy < x[1][1]) {
                cout << "NO" << endl;
                continue;
            }
        }
        else {
            if (x[0][1] + tmpy > x[2][1]) {
                cout << "NO" << endl;
                continue;
            }
        }
        cout << "YES" << endl;
    }
}