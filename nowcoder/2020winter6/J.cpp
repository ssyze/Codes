/*
 * @Date         : 2020-02-15 13:18:47
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int a[3];
double r[3];
int main()
{
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] + a[1] <= a[2])
        cout << "wtnl" << endl;
    else {
        r[0] = (a[0] - a[1] + a[2]) / 2.0;
        r[1] = (a[0] + a[1] - a[2]) / 2.0;
        r[2] = (a[1] - a[0] + a[2]) / 2.0;
        sort(r, r + 3);
        if (r[0] <= 0 || r[1] <= 0 || r[2] <= 0)
            cout << "No" << endl;
        else {
            cout << "Yes" << endl;
            printf("%.2f %.2f %.2f\n", r[0], r[1], r[2]);
        }
    }
}