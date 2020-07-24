/*
 * @Date         : 2020-06-13 13:49:07
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int a[maxn], p[maxn];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i] * p[i];
    ans *= 4;
    cout << ans << endl;
    if (ans > 39900)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}