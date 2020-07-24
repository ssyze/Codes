/*
 * @Date         : 2020-01-07 12:17:19
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int a[105], dp1[105], dp2[105];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp1[i] = dp2[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j])
                dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            if (a[i] > a[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp1[i] + dp2[i] - 1);
    cout << n - ans << endl;
}