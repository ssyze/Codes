/*
 * @Date         : 2020-02-04 13:44:02
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[26];
string s;
int main()
{
    cin >> n >> k;
    cin >> s;
    int ans = 0x3f3f3f3f;
    a[s[0] - 'a']++;
    for (int i = 0, j = 0; i < s.length(), j < s.length();) {
        //cout << i << ' ' << j << endl;
        int max1 = -0x3f3f3f3f;
        for (int q = 0; q < 26; q++)
            max1 = max(max1, a[q]);
        //cout << max1 << endl;
        if (max1 < k) {
            ++j;
            if (j == s.length())
                break;
            a[s[j] - 'a']++;
        }
        else {
            ans = min(ans, j - i + 1);
            a[s[i] - 'a']--;
            i++;
        }
    }
    if (ans == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << ans << endl;
}