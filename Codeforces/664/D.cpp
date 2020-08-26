/*
 * @Date         : 2020-08-14 20:48:47
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
ll n, d, m, suma[maxn], sumb[maxn], a[maxn], b[maxn], na, nb;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> m;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x > m)
            a[++na] = x;
        else
            b[++nb] = x;
    }
    sort(a + 1, a + na + 1, greater<int>());
    sort(b + 1, b + nb + 1, greater<int>());
    ll ans = 0;
    for (int i = 1; i <= nb; i++) sumb[i] = sumb[i - 1] + b[i];
    for (int i = 1; i <= na; i++) suma[i] = suma[i - 1] + a[i];
    for (int i = nb + 1; i < maxn; i++) sumb[i] = sumb[i - 1];
    for (int i = 0; i <= (n - 1) / (d + 1) + 1; i++) {
        ll sum = 0;
        sum += suma[i];
        ll day = n - 1LL * (i - 1) * (d + 1) - 1;
        sum += sumb[day];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}