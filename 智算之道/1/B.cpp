/*
 * @Date         : 2020-07-12 19:06:44
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    int ans = 0;
    if (s[0] == '1') ans++;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '0' && s[i] == '1') ans += 2;
    }
    cout << ans << '\n';
}