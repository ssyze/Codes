/*
 * @Date         : 2020-01-05 15:26:56
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int ans = n / k;
        ans *= k;
        int tmp = k / 2;
        if (ans + tmp <= n)
            cout << ans + tmp << endl;
        else
            cout << n << endl;
    }
}