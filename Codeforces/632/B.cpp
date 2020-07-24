/*
 * @Date         : 2020-04-17 17:01:54
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, n, a[maxn], b[maxn];
int vis[maxn][3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            vis[i][0] = vis[i][1] = vis[i][2] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        for (int i = 2; i <= n; i++) {
            vis[i][0] = vis[i - 1][0];
            vis[i][1] = vis[i - 1][1];
            vis[i][2] = vis[i - 1][2];
            if (a[i - 1] == -1)
                vis[i][0] = 1;
            else if (a[i - 1] == 0)
                vis[i][1] = 1;
            else
                vis[i][2] = 1;
        }
        int flag = 1;
        for (int i = n; i >= 1; i--) {
            if (a[i] == b[i])
                continue;
            if (a[i] > b[i]) {
                if (vis[i][0])
                    continue;
                else {
                    flag = 0;
                    break;
                }
            }
            if (a[i] < b[i]) {
                if (vis[i][2])
                    continue;
                else {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}