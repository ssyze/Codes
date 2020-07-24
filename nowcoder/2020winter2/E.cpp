/*
 * @Date         : 2020-02-06 15:55:28
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e7 + 5;
typedef long long ll;
int a[6350];
int n;
int main()
{
    for (int q = 1; q * q <= maxn; q++) {
        int k = 1;
        n = q * q;
        for (int i = 2; i * i <= n; i++) {
            int t = 1;
            //cout << n << endl;
            if ((n % i) == 0) {
                while ((n % i) == 0) {
                    n /= i;
                    t++;
                }
            }
            //cout << n << endl;
            k *= t;
        }
        if (n != 1)
            k *= 2;
        //cout << q << ' ' << k << endl;
        a[q] = (k / 2) * 2 + 1;
    }
    //cout << a[30] << endl;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i * i <= n; i++) {
        //cout << a[i] << endl;
        ans += a[i];
    }
    cout << ans << endl;
}