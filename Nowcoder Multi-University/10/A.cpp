/*
 * @Date         : 2020-08-10 12:34:47
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
int t, p;
bool vis[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> p;
        for (int i = 0; i <= p; i++) vis[i] = 0;
        vector<int> ans;
        int flag = 1;
        ans.push_back(1);
        vis[1] = 1;
        for (int i = 1; i < p - 1; i++) {
            int cur = ans[i - 1];
            int nxt = cur * 2 % p;
            if (vis[nxt]) nxt = cur * 3 % p;
            if (vis[nxt]) flag = 0;
            vis[nxt] = 1;
            ans.push_back(nxt);
        }
        for (int i = 0; i < ans.size() - 1; i++)
            if ((ans[i] * 2 % p != ans[i + 1]) && (ans[i] * 3 % p != ans[i + 1])) {
                flag = 0;
                break;
            }
        if (flag) {
            for (auto& x : ans) cout << x << ' ';
            cout << '\n';
        }
        else
            cout << "-1\n";
    }
}