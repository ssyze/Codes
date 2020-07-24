/*
 * @Date         : 2020-02-13 13:01:16
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
string s1, s2;
int main()
{
    cin >> n >> m;
    cin >> s1 >> s2;
    if (n > m)
        swap(n, m), swap(s1, s2);
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            ans++;
    }
    cout << ans + m - n << endl;
}