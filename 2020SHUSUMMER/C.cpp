/*
 * @Date         : 2020-08-05 13:04:34
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
#define debug(x) cout << #x << ' ' << x << endl;
using namespace std;
typedef long long ll;
int t, n;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        double ans = n;
        int sum = 0;
        cin.get();
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == '2') {
                    sum++;
                    break;
                }
            }
        }
        // cout << sum << ' ' << ans << endl;
        cout << fixed << setprecision(10) << (double)sum / ans << endl;
    }
}