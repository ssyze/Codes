/*
 * @Date         : 2020-02-11 13:05:23
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n, f[100], ans[100];
int main()
{
    ans[0] = 1;
    ans[1] = 3;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= 85; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    for (int i = 1; i <= 85; i++) {
        ans[i] = f[i + 1] + f[i];
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << ans[n] << endl;
    }
}