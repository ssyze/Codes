/*
 * @Date         : 2020-07-08 12:55:27
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        while (n != 1) {
            if (n % 6 == 0)
                n /= 6, ans++;
            else if (n % 3 == 0)
                n *= 2, ans++;
            else
                break;
        }
        if (n == 1)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
}