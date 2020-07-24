/*
 * @Date         : 2020-03-28 18:15:47
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 4005;
int a[maxn], n;
int main()
{
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (n - i - 1) * a[i];
        }
        cout << ans << endl;
    }
}