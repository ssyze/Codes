/*
 * @Date         : 2020-03-29 14:09:18
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, a, b;
int main()
{
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (b >= a) {
            cout << b - a << endl;
            continue;
        }
        int tmp = a / b, ans;
        if (a % b == 0)
            ans = 0;
        else
            ans = (tmp + 1) * b - a;
        cout << ans << endl;
    }
}