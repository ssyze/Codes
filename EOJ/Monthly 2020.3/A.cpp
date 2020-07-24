/*
 * @Date         : 2020-03-20 19:33:43
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
pair<ll, ll> p[maxn];
ll n, m;
int t, k;
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
int main()
{
    cin >> t;
    while (t--) {
        cin >> k >> n >> m;
        for (int i = 0; i < k; i++) {
            scanf("%lld%lld", &p[i].first, &p[i].second);
        }
        sort(p, p + k, cmp);
        ll ans = -1;
        for (int i = 1; i <= k - 1; i++) {
            ll tmp = abs(p[i].first - p[i - 1].first) + abs(p[i].second - p[i - 1].second) - 1;
            tmp = tmp / 2 + 1;
            ans = max(ans, tmp);
        }
        ll dis[4] = { inf, inf, inf, inf };
        for (int i = 0; i < k; i++) {
            ll tmp = abs(p[i].first) + abs(p[i].second);
            dis[0] = min(tmp, dis[0]);
        }
        for (int i = 0; i < k; i++) {
            ll tmp = abs(p[i].first - n) + abs(p[i].second);
            dis[1] = min(tmp, dis[1]);
        }
        for (int i = 0; i < k; i++) {
            ll tmp = abs(p[i].first) + abs(p[i].second - m);
            dis[2] = min(tmp, dis[2]);
        }
        for (int i = 0; i < k; i++) {
            ll tmp = abs(p[i].first - n) + abs(p[i].second - m);
            dis[3] = min(tmp, dis[3]);
        }
        for (int i = 0; i < 4; i++) {
            //cout << dis[i] << endl;
            ans = max(ans, dis[i]);
        }
        printf("%lld\n", ans);
    }
}