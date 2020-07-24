/*
 * @Date         : 2020-02-15 14:49:37
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int g[maxn];
int dp[maxn];
bool vis[maxn];
int n;
vector<int> v;
int dfs(int u)
{
    int nxt = g[u];
    vis[u] = 1;
    if (dp[nxt])
        return dp[u] = dp[nxt] + 1;
    if (vis[nxt]) {
        v.push_back(nxt);
        return dp[u] = 1;
    }
    return dp[u] = dfs(nxt) + 1;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> g[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            if (v.size()) {
                int nxt = g[v[0]];
                while (nxt != v[0]) {
                    dp[nxt] = dp[v[0]];
                    nxt = g[nxt];
                }
                v.clear();
            }
        }
    }

    /*  for (int i = 1; i <= n; i++)
        cout << dp[i] << ' ';
    cout << endl; */
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
}