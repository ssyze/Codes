/*
 * @Date         : 2020-01-06 01:36:45
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int q, n;
int main()
{
    cin >> q;
    while (q--) {
        cin >> n;
        int ans = n / 4;
        if (ans == 0)
            cout << -1 << endl;
        else if (ans * 4 == n || ans * 4 + 2 == n)
            cout << ans << endl;
        else if ((ans >= 2 && (ans - 2) * 4 + 9 == n) || (ans >= 3 && (ans - 3) * 4 + 15 == n))
            cout << ans - 1 << endl;
        else
            cout << -1 << endl;
    }
}