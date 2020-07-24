/*
 * @Descripttion: 
 * @Author: ssyze
 * @Date: 2019-12-17 00:20:02
 */
#include <bits/stdc++.h>
using namespace std;
int n, d;
string s;
int main()
{
    cin >> n >> d;
    cin >> s;
    int pos = 0, flag = 0, ans = 0;
    while (pos < s.length() - 1) {
        int npos = -1;
        for (int i = pos + 1; i <= pos + d; i++) {
            if (s[i] == '1')
                npos = i;
        }
        if (npos == -1) {
            flag = 1;
            break;
        }
        pos = npos;
        ans++;
    }
    if (flag)
        cout << -1 << endl;
    else
        cout << ans << endl;
}