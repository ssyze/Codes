/*
 * @Date         : 2020-04-15 18:26:00
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int t, a[maxn], n, x, vis[maxn];
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> x;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            vis[a[i]] = 1;
        }
        int i, ans = 0;
        for (i = 1; x; i++) {
            if (vis[i])
                continue;
            else
                x--, ans = i;
        }
        while (vis[i])
            ans = i++;
        cout << ans << endl;
    }
}