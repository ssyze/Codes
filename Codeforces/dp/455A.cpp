/*
 * @Date         : 2020-04-03 14:35:09
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
ll dp[maxn];
ll cnt[maxn], n;
int main()
{
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    dp[1] = cnt[1];
    for (ll i = 2; i < maxn; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
    }
    cout << dp[maxn - 1] << endl;
}