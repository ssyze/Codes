/*
 * @Date         : 2020-04-28 15:06:12
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, n, a, b, vis[26];
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        memset(vis, 0, sizeof(vis));
        string ans = "";
        for (int i = 0; i < b; i++)
            ans += 'a' + i, vis[i] = 1;
        for (int i = b; i < a; i++)
            ans += 'a', vis[0]++;
        int cnt = b;
        for (int i = a; i < n; i++) {
            vis[ans[i - a] - 'a']--;
            if (vis[ans[i - a] - 'a'] == 0)
                cnt--;
            if (cnt == b)
                ans += 'a', vis[0]++;
            else {
                for (int i = 0; i < b; i++) {
                    if (vis[i] == 0) {
                        ans += 'a' + i;
                        vis[i]++;
                        cnt++;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}