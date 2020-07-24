/*
 * @Date         : 2020-07-23 12:29:20
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 55;
int t, n, k;
struct item {
    ll a, b, c, d;
    ll DMG;
    item() {}
    item(ll _a, ll _b, ll _c, ll _d, ll _DMG) : a(_a), b(_b), c(_c), d(_d), DMG(_DMG) {}
    item operator+(item& x) { return item(a + x.a, b + x.b, c + x.c, d + x.d, DMG + x.DMG); }
} dp[maxn];
vector<item> it[maxn];
ll DMG(item a) { return (100 + a.a) * (100 + a.b) * (100 + a.c) * (100 + a.d); }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            ll type, a, b, c, d;
            cin >> type >> a >> b >> c >> d;
            it[type].push_back(item(a, b, c, d, 0));
        }
        for (int q = 1; q <= k; q++) {
            for (int i = k; i >= 0; i--) {
                for (int j = 0; j < it[q].size(); j++) {
                    if (i >= 1) {
                        item x = it[q][j];
                        ll d = DMG(x);
                        item tmp = dp[i - 1] + x;
                        if (DMG(tmp) > DMG(dp[i])) {
                            dp[i] = dp[i - 1] + x;
                            dp[i].DMG = DMG(dp[i]);
                        }
                    }
                }
            }
            // cout << dp[k].DMG << endl;
        }
        cout << dp[k].DMG << '\n';
        for (int i = 0; i <= k; i++) it[i].clear();
        memset(dp, 0, sizeof(dp));
    }
}
