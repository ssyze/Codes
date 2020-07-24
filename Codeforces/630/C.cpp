/*
 * @Date         : 2020-04-01 17:41:31
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n, k;
bool vis[maxn];
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            int res = 0, mx = 0;
            vector<int> cnt(26);
            for (int j = i; j < n; j += k) {
                if (!vis[j]) {
                    vis[j] = 1;
                    cnt[s[j] - 'a']++;
                    res++;
                }
                else
                    break;
            }
            for (int j = n - i - 1; j >= 0; j -= k) {
                if (!vis[j]) {
                    vis[j] = 1;
                    cnt[s[j] - 'a']++;
                    res++;
                }
                else
                    break;
            }
            for (auto& x : cnt)
                mx = max(mx, x);
            //cout << res << ' ' << mx << endl;
            ans += res - mx;
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++)
            vis[i] = 0;
    }
}