/*
 * @Date         : 2020-04-15 20:15:23
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n, a[maxn], vis1[maxn], vis2[maxn], res[2][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            vis1[i] = vis2[i] = 0;
        }
        int ans = 0;
        vector<int> ans1[2], ans2[2];
        for (int i = 0; i < n; i++) {
            if (!vis1[a[i]]) {
                vis1[a[i]] = 1;
                ans1[0].push_back(a[i]);
            }
            else {
                for (int j = i; j < n; j++) {
                    ans1[1].push_back(a[j]);
                }
                break;
            }
        }
        sort(ans1[0].begin(), ans1[0].end());
        sort(ans1[1].begin(), ans1[1].end());
        int flag = 1;
        for (int i = 0; i < ans1[0].size(); i++) {
            if (ans1[0][i] != i + 1) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < ans1[1].size(); i++) {
                if (ans1[1][i] != i + 1) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) {
            res[ans][0] = ans1[0].size();
            res[ans][1] = n - ans1[0].size();
            ans++;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (!vis2[a[i]]) {
                vis2[a[i]] = 1;
                ans2[0].push_back(a[i]);
            }
            else {
                for (int j = i; j >= 0; j--) {
                    ans2[1].push_back(a[j]);
                }
                break;
            }
        }
        sort(ans2[0].begin(), ans2[0].end());
        sort(ans2[1].begin(), ans2[1].end());
        flag = 1;
        for (int i = 0; i < ans2[0].size(); i++) {
            if (ans2[0][i] != i + 1) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < ans2[1].size(); i++) {
                if (ans2[1][i] != i + 1) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) {
            res[ans][0] = ans2[1].size();
            res[ans][1] = n - ans2[1].size();
            ans++;
        }
        if (ans == 2 && (res[0][0] == res[1][0] && res[0][1] == res[1][1]))
            ans--;
        cout << ans << endl;
        for (int i = 0; i < ans; i++) {
            cout << res[i][0] << ' ' << res[i][1] << endl;
        }
    }
}