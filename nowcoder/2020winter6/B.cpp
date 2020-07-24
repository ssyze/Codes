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
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> g[i];
    int ans = 0;
    stack<int> s;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            s.push(i);
            while (!s.empty()) {
                cout << s.top() << endl;
                int nxt = g[s.top()];
                vis[s.top()] = 1;
                if (dp[nxt]) {
                    dp[s.top()] = dp[nxt] + 1;
                    s.pop();
                }
                if (vis[nxt]) {
                    dp[s.top()] = 2;
                    s.pop();
                }
                s.push(nxt);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    for (int i = 1; i <= n; i++)
        cout << dp[i] << ' ';
    cout << endl;
    cout << ans + 1 << endl;
}