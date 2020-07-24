/*
 * @Date         : 2020-03-14 12:48:30
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
ll n, a[maxn], sum1[maxn], sum2[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        sum1[i] = sum1[i - 1] + a[i] * a[i];
        sum2[i] = sum2[i - 1] + a[i];
    }
    ll mx = -1, ans;
    for (int i = 1; i < n; i++) {
        //cout << sum1[i] << ' ' << sum2[n] - sum2[i] << endl;
        ans = sum1[i] * (sum2[n] - sum2[i]);
        mx = max(ans, mx);
    }
    cout << mx << endl;
}