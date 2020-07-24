/*
 * @Date         : 2020-01-04 20:59:39
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
typedef long long ll;
const int maxn = 250005;
using namespace std;
ll f[maxn];
ll n, m;
void fac()
{
    f[0] = 1;
    for (int i = 1; i < maxn; i++)
        f[i] = (f[i - 1] * i) % m;
}
int main()
{
    cin >> n >> m;
    fac();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = ans + (n - i + 1) * (n - i + 1) % m * f[i] % m * f[n - i] % m;
        ans %= m;
    }
    cout << ans << endl;
}