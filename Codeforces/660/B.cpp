/*
 * @Date         : 2020-08-03 23:47:16
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int e = (n + 3) / 4;
        for (int i = 0; i < n - e; i++) cout << '9';
        for (int i = 0; i < e; i++) cout << '8';
        cout << '\n';
    }
}