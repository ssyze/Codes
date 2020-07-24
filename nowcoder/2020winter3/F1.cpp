/*
 * @Date         : 2020-02-09 14:39:08
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
char a[maxn];
ll sum, cnt, ans;
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        sum = (sum + cnt) % mod;
        cout << sum << endl;
        if (a[i] == '1') {
            cnt++;
            ans = (ans + sum) % mod;
        }
    }
    cout << ans % mod << endl;
}