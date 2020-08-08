/*
 * @Date         : 2020-08-08 15:21:27
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll a, b, c, d, x, y, gcd, xx, yy, cnt[2][35];
vector<pair<int, int>> gg;
vector<pair<int, int>> chai(ll x)
{
    vector<pair<int, int>> c;
    for (int i = 2; i * i <= x; i++) {
        int num = 0;
        while (x % i == 0) {
            x /= i;
            num++;
        }
        if (num) c.push_back({i, num});
    }
    if (x != 1) c.push_back({x, 1});
    return c;
}
ll qpow(ll a, ll b)
{
    a %= mod;
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
    cin >> a >> b >> c >> d >> x >> y;
    gcd = __gcd(x, y), xx = x, yy = y;
    if (gcd == 1) {
        cout << 1 << endl;
        return 0;
    }
    gg = chai(gcd);
    // for (auto& f : gg) cout << f.first << ' ' << f.second << endl;
    int sz = gg.size();
    for (int i = 0; i < sz; i++) {
        int num1 = 0, num2 = 0;
        while (xx % gg[i].first == 0) {
            xx /= gg[i].first;
            num1++;
        }
        while (yy % gg[i].first == 0) {
            yy /= gg[i].first;
            num2++;
        }
        cnt[0][i] = num1;
        cnt[1][i] = num2;
    }
    ll ans = 1;
    for (int i = 0; i < sz; i++) {
        int now = gg[i].first;
        int numx = cnt[0][i], numy = cnt[1][i];
        int stx = numx * a, sty = numy * c;
        int edx = numx * b, edy = numy * d;
        // cout << now << ' ' << numx << ' ' << numy << endl;
        // cout << stx << ' ' << edx << ' ' << sty << ' ' << edy << endl;
        ll sum = 0;
        for (int j = a * numx; j <= edx && j <= edy; j += numx) {
            ll tmp = (edy - max(j, sty)) / numy + 1;
            sum = (sum + j * tmp) % (mod - 1);
        }
        ans = ans * qpow(now, sum) % mod;
        sum = 0;
        for (int j = c * numy; j < edx && j <= edy; j += numy) {
            ll tmp = (edx - max(j + 1, stx)) / numx + 1;
            sum = (sum + j * tmp) % (mod - 1);
        }
        ans = ans * qpow(now, sum) % mod;
    }
    cout << ans << endl;
}