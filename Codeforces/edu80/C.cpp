/*
 * @Date         : 2020-04-07 14:37:42
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int n, m;
ll dpa[15][1005], dpb[15][1005];
// dpa[i][j] a长度为i最大为j的序列个数
// dpb[i][j] b长度为i最小为j的序列个数
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        dpa[1][i] = dpb[1][i] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= j; k++)
                dpa[i][j] = (dpa[i][j] + dpa[i - 1][k]) % mod;
            for (int k = n; k >= j; k--)
                dpb[i][j] = (dpb[i][j] + dpb[i - 1][k]) % mod;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans = (ans + dpa[m][i] * dpb[m][j]) % mod;
        }
    }
    cout << ans << endl;
}
