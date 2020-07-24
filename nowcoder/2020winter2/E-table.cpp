/*
 * @Date         : 2020-02-06 15:26:14
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    for (n = 100; n <= 100; n++) {
        int ans = 0;
        printf("n=%d: ", n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i * j > n)
                    break;
                //cout << sqrt(i * j) << ' ' << int(sqrt(i * j)) << endl;
                if (sqrt(i * j) == int(sqrt(i * j))) {
                    cout << i << ' ' << j << ' ' << ++ans;
                    cout << endl;
                }
            }
        }
        cout << ans << endl;
    }
}