/*
 * @Date         : 2020-08-13 21:12:29
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int t, c[4];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        for (int i = 0; i < 4; i++) cin >> c[i];
        int flag = 1, sum1 = 0, z = 0;
        for (int i = 0; i < 4; i++)
            if (c[i] & 1) sum1++;
        for (int i = 0; i < 3; i++)
            if (c[i] == 0) {
                z = 1;
                break;
            }
        if (sum1 <= 1 || (!z && (sum1 == 3 || sum1 == 4)))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}