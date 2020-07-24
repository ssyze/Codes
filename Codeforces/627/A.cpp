/*
 * @Date         : 2020-04-02 14:35:39
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int t, a[maxn], n;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int flag = 1, num = a[0] & 1;
        for (int i = 1; i < n; i++) {
            if ((a[i] & 1) != num) {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}