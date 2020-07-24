/*
 * @Date         : 2020-04-16 20:44:28
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, d, m;
ll cal(ll x)
{
    return min(x - 1, d) - (x / 2) + 2;
}
int main()
{
    cin >> t;
    while (t--) {
        cin >> d >> m;
        ll ans = 1;
        for (int i = 1; i <= d; i <<= 1) {
            //cout << i << endl;
            //cout << cal(i * 2) << endl;
            ans = ans * cal(i * 2) % m;
        }
        ans--;
        ans = (ans + m) % m;
        cout << ans << endl;
    }
}