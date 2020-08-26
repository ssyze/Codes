/*
 * @Date         : 2020-08-19 20:23:29
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
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        if (a[0] + a[1] > a[n - 1])
            cout << "-1\n";
        else
            cout << "1 2 " << n << '\n';
    }
}