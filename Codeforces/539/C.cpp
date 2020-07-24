/*
 * @Date         : 2020-04-10 17:49:52
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
const int maxn = 3e5 + 5;
typedef long long ll;
int sum[maxn], a[maxn], n;
ll cnt[2][1 << 21];
// cnt[i][j] i表示是奇数还是偶数 j表示异或前缀和
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] ^ a[i];
    cnt[0][0] = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += cnt[i & 1][sum[i]];
        cnt[i & 1][sum[i]]++;
    }
    printf("%lld\n", ans);
}