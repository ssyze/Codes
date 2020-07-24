/*
 * @Date         : 2020-01-03 15:03:26
 * @Author       : ssyze
 * @Description  : 
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 6005;
bool vis[maxn];
vector<int> g[maxn];
int dp[maxn][2], fa[maxn];
// dp[i][0]表示不邀请 dp[i][1]表示邀请
int n;
void dfs(int u)
{
    for (int i = 0; i < g[u].size(); i++)
        dfs(g[u][i]);
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        dp[u][0] += max(dp[v][1], dp[v][0]);
        dp[u][1] += dp[v][0];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n) {
        memset(dp, 0, sizeof(dp));
        memset(fa, -1, sizeof(fa));
        for (int i = 1; i <= n; i++) {
            cin >> dp[i][1];
            dp[i][0] = 0;
        }
        int f, s;
        while (cin >> s >> f && f && s) {
            g[f].push_back(s);
            fa[s] = f;
        }
        int root = 1;
        while (fa[root] != -1)
            root = fa[root];
        dfs(root);
        cout << max(dp[root][0], dp[root][1]) << endl;
        for (int i = 0; i < n; i++)
            g[i].clear();
    }
}