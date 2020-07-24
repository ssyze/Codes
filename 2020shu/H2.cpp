/*
 * @Date         : 2020-04-18 15:36:29
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, k;
string s;
int main()
{
    cin >> t;
    while (t--) {
        cin >> s >> k;
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        string ans = "";
        vector<int> v(10), mod(3);
        for (int i = 0; i < s.length(); i++) {
            v[s[i] - '0']++;
            mod[(s[i] - '0') % 3]++;
        }
        if (k == 1) {
            if (v[9])
                cout << 9 << endl;
            else if (v[6])
                cout << 6 << endl;
            else if (v[3])
                cout << 3 << endl;
            else if (v[0])
                cout << 0 << endl;
            else
                cout << -1 << endl;
            continue;
        }
        int m = 0, i;
        for (i = 0; i < s.length() && ans.length() <= k - 2; i++) {
            int tmp = s[i] - '0';
            tmp %= 3;
            if ((m + tmp) % 3 == 0) {
                ans += s[i];
                m = 0;
            }
            else if ((m + tmp) % 3 == 1) {
                if (tmp == 2) {
                    if (mod[2] >= 2 || mod[1] >= 2)
                        ans += s[i];
                }
                else if (tmp == 1) {
                    if (mod[2] || mod[1] >= 3)
                        ans += s[i];
                }
                else {
                    if (mod[2] || mod[1] >= 2)
                        ans += s[i];
                }
                m = 1;
            }
            else if ((m + tmp) % 3 == 2) {
                if ((s[i] - '0' % 3) == 1) {
                    if (mod[2] >= 2 || mod[1] >= 2)
                        ans += s[i];
                }
                else if ((s[i] - '0' % 3) == 2) {
                    if (mod[1] || mod[2] >= 3)
                        ans += s[i];
                }
                else {
                    if (mod[1] || mod[2] >= 2)
                        ans += s[i];
                }
                m = 2;
            }
            v[s[i] - '0']--;
            mod[(s[i] - '0') % 3]--;
            cout << m << ' ' << mod[0] << ' ' << mod[1] << ' ' << mod[2] << ' ' << ans << endl;
        }
        cout << m << endl;
        if (m == 0) {
            if (v[9])
                ans += '9';
            else if (v[6])
                ans += '6';
            else if (v[3])
                ans += '3';
            else if (v[0])
                ans += '0';
        }
        if (m == 1) {
            if (v[8])
                ans += '8';
            else if (v[5])
                ans += '5';
            else if (v[2])
                ans += '2';
        }
        if (m == 2) {
            if (v[7])
                ans += '7';
            else if (v[4])
                ans += '4';
            else if (v[1])
                ans += '1';
        }
        if (ans[0] == '0' || ans.size() != k)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}