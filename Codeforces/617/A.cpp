/*
 * @Date         : 2020-02-07 22:25:37
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int t, n;
int a[maxn];
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] & 1)
                odd++;
            else
                even++;
        }
        if ((odd & 1) == 0 && even == 0)
            cout << "NO" << endl;
        else if (odd == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}