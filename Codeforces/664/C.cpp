/*
 * @Date         : 2020-08-14 18:16:46
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[205], b[205], ans;
bool check(int x)
{
    for (int i = 1; i <= n; i++) {
        int tmp = -1;
        for (int j = 1; j <= m; j++) {
            tmp = x | a[i] & b[j];
            if (tmp == x) break;
        }
        if (tmp != x) return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 0; i < 1 << 9; i++) {
        if (check(i)) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}