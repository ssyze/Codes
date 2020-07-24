/*
 * @Date         : 2019-12-28 13:11:46
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = a[n - 1] + a[n - 2] + a[n - 3];
    if (ans < m)
        cout << "Waiver!" << endl;
    else
        cout << ans << endl;
}