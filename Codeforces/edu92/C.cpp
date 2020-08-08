/*
 * @Date         : 2020-07-30 00:03:12
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
pair<int, int> num[10];
int t;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 10; i++) {
            string tmp = "";
            for (int j = 0; j < s.length(); j++) {
                if (s[j] - '0' == i) tmp += s[j];
            }
            if (tmp == "") continue;
            if (tmp.length() == 1) {
                int len = s.length() - 1;
                ans = min(ans, len);
                continue;
            }
            int len = s.length() - tmp.length();
            ans = min(ans, len);
        }
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                if (i == k) continue;
                string tmp = "";
                for (int j = 0; j < s.length(); j++) {
                    if ((s[j] - '0') == i && tmp.length() == 0) tmp += s[j];
                    if ((s[j] - '0') == i && (tmp[tmp.length() - 1] - '0') == k) tmp += s[j];
                    if ((s[j] - '0') == k && (tmp[tmp.length() - 1] - '0') == i) tmp += s[j];
                }
                if (tmp == "") continue;
                if (tmp.length() == 1) {
                    int len = s.length() - 1;
                    ans = min(ans, len);
                    continue;
                }
                int len = s.length() - tmp.length();
                if (tmp.length() % 2 == 0) len--;
                ans = min(ans, len + 1);
            }
        }
        cout << ans << endl;
    }
}