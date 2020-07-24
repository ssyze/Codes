/*
 * @Date         : 2020-07-21 12:02:42
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1)
            cout << 26 << '\n';
        else if (n == 2)
            cout << 676 << '\n';
        else if (n == 3)
            cout << qpow(26, 3) << '\n';
        else
            cout << 26 * 25 * 24 << '\n';
    }
}