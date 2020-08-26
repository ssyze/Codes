/*
 * @Date         : 2020-08-19 21:30:10
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], sum[maxn];
int t, n;
map<int, int> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        mp.clear();
        mp[0]++;
        cin >> n;
        string s;
        cin >> s;
        long long ans = 0, pre = 0;
        for (int i = 0; i < s.length(); i++) a[i + 1] = s[i] - '1';
        for (int i = 1; i <= n; i++) {
            pre += a[i];
            if (mp[pre]) ans += mp[pre];
            mp[pre]++;
        }
        cout << ans << endl;
    }
}