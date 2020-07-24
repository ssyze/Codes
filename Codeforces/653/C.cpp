/*
 * @Date         : 2020-07-08 13:01:06
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ans = 0, now = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                now++;
            else if (s[i] == ')') {
                now--;
                if (now < 0) {
                    ans++;
                    now = 0;
                }
            }
        }
        cout << ans << endl;
    }
}