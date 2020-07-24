/*
 * @Date         : 2020-04-02 15:33:31
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], c[maxn], n, pos;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        c[i] = a[i] - b[i];
    sort(c + 1, c + n + 1, greater<int>());
    //pos = lower_bound(c + 1, c + n + 1, 0, greater<int>()) - c;
    long long ans = 0;
    for (int i = 1; c[i] > 0 && i <= n; i++) {
        pos = lower_bound(c + 1, c + n + 1, -c[i], greater<int>()) - c;
        //cout << pos << endl;
        ans += pos - i - 1;
    }
    cout << ans << endl;
}