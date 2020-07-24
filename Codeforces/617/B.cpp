/*
 * @Date         : 2020-02-07 22:38:46
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        while (n > 10) {
            ans += n - n % 10;
            n = n % 10 + n / 10;
            //cout << n << endl;
        }
        cout << ans + n / 10 + n << endl;
    }
}