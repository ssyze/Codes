/*
 * @Date         : 2020-04-17 19:09:52
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
ll n, a[maxn], sum[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    map<ll, ll> pre;
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    ll ans = 0, mx = -1;
    for (int i = 1; i <= n; i++) {
        if (pre.count(sum[i]))
            mx = max(mx, pre[sum[i]]);
        ans += i - (mx + 1);
        pre[sum[i]] = i;
    }
    cout << ans << endl;
}