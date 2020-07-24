/*
 * @Date         : 2020-04-21 14:26:40
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        for (int i = (n + 1) / 2, j = 1; i >= 1 && i <= n; j++) {
            cout << a[i] << ' ';
            if (j & 1)
                i += j;
            else
                i -= j;
        }
        cout << endl;
    }
}