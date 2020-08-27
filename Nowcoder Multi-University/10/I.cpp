#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
int vis[maxn][maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (j - 1 <= n - i) {
                    cout << j << ' ' << i << '\n';
                    vis[i][j] = vis[j][i] = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!vis[i][j]) {
                    cout << i << ' ' << j << '\n';
                    vis[i][j] = 1;
                }
            }
        }
    }
}