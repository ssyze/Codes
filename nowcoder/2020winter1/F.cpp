/*
 * @Date         : 2020-02-04 15:53:22
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
vector<int> g[maxn];
int n;
ll ans;
ll par[maxn], rank1[maxn], vis[maxn];
ll cnt[maxn];
string c;
void init()
{
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        rank1[i] = 0;
        cnt[i] = 1;
    }
}
int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]); //路径压缩
}
void Unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    else
        par[x] = y, cnt[y] += cnt[x];
}
void dfs(int u, int f)
{
    for (int i = 0; i < g[u].size(); i++) {
        if (g[u][i] != f) {
            dfs(g[u][i], u);
            if (c[u - 1] == 'W' && c[g[u][i] - 1] == 'W')
                Unite(u, g[u][i]);
        }
    }
}
int main()
{
    cin >> n;
    cin >> c;
    init();
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (c[i - 1] == 'W')
            continue;
        ll sum = 0;
        for (int j = 0; j < g[i].size(); j++) {
            if (c[g[i][j] - 1] == 'B')
                continue;
            int v = find(g[i][j]);
            ans += cnt[v] * (sum + 1);
            sum += cnt[v];
        }
    }
    cout << ans << endl;
}