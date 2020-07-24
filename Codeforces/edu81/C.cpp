/*
 * @Date         : 2020-04-05 16:39:20
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int t, nxt[maxn][26];
string s, z;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s >> z;
        for (int i = 0; i < s.length() + 5; i++) {
            for (int j = 0; j < 26; j++)
                nxt[i][j] = inf;
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                nxt[i][j] = nxt[i + 1][j];
            }
            nxt[i][s[i] - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0, pos = 0; i < z.length(); i++) {
            //cout << nxt[pos][z[i] - 'a'] << endl;
            if (nxt[pos][z[i] - 'a'] == inf) {
                if (nxt[0][z[i] - 'a'] == inf) {
                    ans = inf;
                    break;
                }
                ans++;
                pos = nxt[0][z[i] - 'a'];
            }
            pos = nxt[pos][z[i] - 'a'] + 1;
        }
        if (ans == inf)
            cout << -1 << endl;
        else
            cout << ans + 1 << endl;
    }
}