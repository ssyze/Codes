#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
ll n, sum[maxn], cnt[maxn];
char a[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--) {
        sum[i] = sum[i + 1];
        cnt[i] = cnt[i + 1];
        if (a[i] == '1')
            sum[i] += i, cnt[i]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == '1') {
            cout << sum[i] << ' ' << cnt[i] << endl;
            ans = (ans + sum[i + 1] - cnt[i + 1] * i) % mod;
        }
    }
    cout << ans << endl;
}
