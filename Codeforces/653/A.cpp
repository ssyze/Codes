/*
 * @Date         : 2020-07-08 12:46:32
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, x, y, n;
int main()
{
    cin >> t;
    while (t--) {
        cin >> x >> y >> n;
        int tmp = n / x;
        int ans = tmp * x + y;
        if (ans > n)
            cout << ans - x << endl;
        else
            cout << ans << endl;
    }
}