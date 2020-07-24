/*
 * @Date         : 2020-05-10 13:18:20
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m;
int num[maxn], sum[maxn];
int main()
{
    cin >> n >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        num[l]++;
        num[r + 1]--;
    }
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + num[i];
    sort(sum + 1, sum + 1 + n, greater<int>());
    int tmp = n;
    long long ans = 0;
    for (int i = 1; sum[i] > 0; i++) {
        long long t = 1LL * sum[i] * n;
        ans += t;
        n--;
    }
    cout << ans << endl;
}
