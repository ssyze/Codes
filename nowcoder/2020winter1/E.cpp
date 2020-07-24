/*
 * @Date         : 2020-02-04 13:18:33
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main()
{
    cin >> n;
    ll sum = n;
    ll ans = 0;
    while (sum != 2) {
        int k = 1;
        n = sum;
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
        //cout << k << endl;
        sum = k;
        ans++;
    }
    cout << ans << endl;
}