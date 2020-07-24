/*
 * @Date         : 2020-05-01 01:11:42
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n, cnt[maxn], num, mx;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i <= n; i++)
            cnt[i] = 0;
        num = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (!cnt[x])
                num++;
            cnt[x]++;
        }
        for (int i = 0; i <= n; i++)
            mx = max(mx, cnt[i]);
        cout << max(min(mx - 1, num), min(mx, num - 1)) << '\n';
    }
}