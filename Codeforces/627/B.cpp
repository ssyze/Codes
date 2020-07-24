/*
 * @Date         : 2020-04-02 14:51:05
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int t, n, a[maxn];
int vis[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        memset(vis, 0, sizeof(vis));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool ok = 0;
        for (int i = 0; i < n; i++) {
            vis[a[i]]++;
            if (vis[a[i]] == 2) {
                if (a[i - 1] != a[i]) {
                    ok = 1;
                    break;
                }
            }
            if (vis[a[i]] == 3) {
                ok = 1;
                break;
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}