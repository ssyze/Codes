/*
 * @Date         : 2019-12-21 23:10:45
 * @Author       : ssyze
 * @Description  : hungary algorithm with bipartite graph
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
int g[maxn][maxn];
int vis[maxn], line[maxn][maxn];
int ly[maxn], lx[maxn];
int n, m, p;
int a[maxn], b[maxn];
bool find1(int u)
{
    for (int v = 1; v <= m; v++) {
        if (g[u][v] && !vis[v]) {
            vis[v] = 1;
            if (ly[v] == -1 || find1(ly[v])) {
                ly[v] = u;
                lx[u] = v;
                return 1;
            }
        }
    }
    return 0;
}
int match()
{
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (find1(i))
            ans++;
    }
    return ans;
}
int main()
{
    memset(lx, -1, sizeof(lx));
    memset(ly, -1, sizeof(ly));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (abs(a[i] - b[j]) <= 1) {
                g[i][j] = 1;
            }
        }
    }
    int ans = match();
    cout << ans << endl;
}