/*
 * @Date         : 2020-03-25 15:07:02
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
long long a[maxn], b[maxn];
int n;
int main()
{
    cin >> n;
    a[1] = 10;
    b[1] = 10;
    long long tmp = 100, sum = 20;
    for (int i = 2; i <= n; i++) {
        a[i] = (tmp * i % mod - sum + mod) % mod;
        b[i] = (b[i - 1] + a[i]) % mod;
        sum = (sum + b[i] + a[i]) % mod;
        tmp = tmp * 10 % mod;
    }
    for (int i = n; i >= 1; i--)
        cout << a[i] << ' ';
    cout << endl;
}