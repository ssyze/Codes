/*
 * @Date         : 2020-02-15 16:39:20
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int a[maxn], b[maxn], cnt[maxn], sum[maxn], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) {
            puts("0");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        int pos = upper_bound(a + 1, a + 1 + n, b[i]) - a;
        cnt[1]++;
        cnt[pos]--;
    }
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + cnt[i];
    }
    sort(sum + 1, sum + n + 1);
    for (int i = 1; i <= n; i++) {
        ans = ans * (sum[i] - i + 1) % mod;
    }
    cout << ans << endl;
}