/*
 * @Date         : 2020-03-25 15:30:04
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
typedef long long ll;
ll p[maxn] = { 1 };
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n + 3; i++)
        p[i] = p[i - 1] * 10 % mod;
    for (int i = 1; i < n; i++) {
        ll res = 2 * 10 * 9 * p[n - i - 1] % mod;
        res = (res + (n - i - 1) * 10 * 9 * 9 * p[n - i - 2] % mod) % mod;
        cout << res << ' ';
    }
    cout << 10 << endl;
}