/*
 * @Date         : 2020-07-20 20:42:49
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n, prime[maxn], vis[maxn], tot, ansn;
vector<int> num[50000];
vector<pair<int, int> > ans;
void init()
{
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) prime[++tot] = i, vis[i] = tot;
        for (int j = 1; j <= tot && i * prime[j] < maxn; j++) {
            if (i % prime[j] == 0) {
                vis[i * prime[j]] = prime[j];
                break;
            }
            vis[i * prime[j]] = prime[j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> t;
    while (t--) {
        ansn = 0;
        ans.clear();
        cin >> n;
        for (int i = 2; i <= n; i++) num[vis[i]].push_back(i);
        for (int i = tot; i >= 2; i--) {
            if (num[i].size() <= 1) continue;
            if (num[i].size() % 2 == 1) {
                num[0].push_back(num[i][1]);
                ans.push_back({num[i][0], num[i][2]});
                for (int j = 3; j < num[i].size(); j += 2) {
                    ans.push_back({num[i][j], num[i][j + 1]});
                }
            }
            for (int j = 0; j < num[i].size(); j += 2)
                ans.push_back({num[i][j], num[i][j + 1]});
        }
        for (int i = 0; i < num[1].size(); i += 2)
            ans.push_back({num[1][i], num[1][i + 1]});
        cout << ans.size() << '\n';
        for (auto& x : ans) cout << x.first << ' ' << x.second << '\n';
        for (int i = 1; i <= tot; i++) num[i].clear();
    }
}