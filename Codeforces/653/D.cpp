/*
 * @Date         : 2020-07-11 19:53:39
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long t, n, k, a;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        map<long long, long long> mp;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if ((a % k) != 0) {
                mp[a % k]++;
            }
        }
        long long mx = -1, tmp = 0;
        for (auto& x : mp) {
            //cout << x.first << ' ' << x.second << endl;
            if (mx < x.second) {
                mx = x.second;
                tmp = x.first;
            }
        }
        //cout << mx << ' ' << tmp << endl;
        if (mx == -1)
            cout << 0 << endl;
        else
            cout << k - tmp + (mx - 1) * k + 1 << endl;
    }
}