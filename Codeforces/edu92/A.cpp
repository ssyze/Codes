/*
 * @Date         : 2020-07-29 22:36:21
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int t, l, r;
int main()
{
    cin >> t;
    while (t--) {
        cin >> l >> r;
        int x = l;
        if (2 * l > r)
            cout << -1 << ' ' << -1 << endl;
        else
            cout << l << ' ' << 2 * l << endl;
    }
}