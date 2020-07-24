/*
 * @Date         : 2020-05-14 22:39:18
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int a[35], b[35];
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n, greater<int>());
        int sum = 0;
        for (int i = 0; i < k; i++) {
            if (b[i] > a[i])
                sum += b[i];
            else
                sum += a[i];
        }
        for (int i = k; i < n; i++)
            sum += a[i];
        cout << sum << endl;
    }
}