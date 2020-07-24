/*
 * @Date         : 2020-02-09 15:44:12
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
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
    ll a, b;
    cin >> a >> b;
    ll p = a * qpow(b, mod - 2) % mod;
    cout << p << ' ' << (mod + 1 - p) % mod << endl;
}