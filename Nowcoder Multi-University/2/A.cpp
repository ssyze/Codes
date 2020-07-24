/*
 * @Date         : 2020-07-15 23:16:33
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e6 + 5;
const int mod = 998244353;
int n;
string s[maxn];
ull f[maxn];
int nxt[maxn], cnt[maxn];
map<ull, ll> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = f[i - 1] * 27;
    for (int i = 0; i < n; i++) {
        ull tmp = 0;
        for (int j = s[i].length() - 1; j >= 1; j--) {
            tmp = f[s[i].length() - j - 1] * (s[i][j] - 'a' + 1) + tmp;
            // cout << s[i].substr(j) << ' ' << tmp << endl;
            mp[tmp]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ull tmp = 0;
        for (int j = 1; j < s[i].length(); j++) {
            tmp = tmp * 27 + (s[i][j] - 'a' + 1);
            // cout << tmp << ' ';
            cnt[j] = mp[tmp];
            // cout << cnt[j] << endl;
        }
        for (int j = 2, k = 0; j < s[i].length(); j++) {
            while (k && s[i][j] != s[i][k + 1]) k = nxt[k];
            if (s[i][j] == s[i][k + 1]) k++;
            nxt[j] = k;
        }
        for (int j = 1; j < s[i].length(); j++) cnt[nxt[j]] -= cnt[j];
        for (int j = 1; j < s[i].length(); j++)
            ans = (ans + 1LL * cnt[j] * j % mod * j % mod) % mod;
    }
    cout << ans << endl;
}