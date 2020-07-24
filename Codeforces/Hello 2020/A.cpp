/*
 * @Date         : 2020-01-04 20:04:28
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
string s[25], t[25];
int main()
{
    int n, m, q;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= m; i++)
        cin >> t[i];
    s[0] = s[n];
    t[0] = t[m];
    cin >> q;
    while (q--) {
        int y;
        cin >> y;
        cout << s[y % n] + t[y % m] << endl;
    }
}