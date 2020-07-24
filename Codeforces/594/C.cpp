/*
 * @Date         : 2020-04-09 17:27:52
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
ll n, m, dp[maxn];
int main()
{
    cin >> n >> m;
    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 4;
    for (int i = 3; i <= max(n, m); i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    cout << (dp[n] + dp[m] - 2) % mod << endl;
}