/*
 * @Date         : 2020-04-04 16:27:34
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n;
string s, ans;
int main()
{
    cin >> n >> s;
    string s1 = "a", s2 = "a";
    for (int i = 0; i < n; i++) {
        if (s[i] >= s1[s1.length() - 1]) {
            ans += "0";
            s1 += s[i];
        }
        else if (s[i] >= s2[s2.length() - 1]) {
            ans += "1";
            s2 += s[i];
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES\n"
         << ans << "\n";
}