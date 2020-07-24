/*
 * @Date         : 2020-04-02 15:19:20
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        s += 'R';
        int cnt = 1, ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') {
                ans = max(ans, cnt);
                cnt = 1;
            }
            else
                cnt++;
        }
        cout << ans << endl;
    }
}