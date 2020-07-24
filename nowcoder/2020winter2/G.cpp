/*
 * @Date         : 2020-02-06 13:30:43
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll t, a, b, c, d, e, f, g;
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int main()
{
    //cout << qpow(1, 0) << endl;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d >> e >> f >> g;
        ll sum = qpow(a, d) + qpow(b, e) + qpow(c, f);
        //cout << sum << endl;
        //cout << qpow(a, d) << ' ' << qpow(b, e) << ' ' << qpow(c, f) << endl;
        if (sum == g)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}