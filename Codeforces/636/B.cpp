/*
 * @Date         : 2020-06-14 16:35:34
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        n /= 2;
        if (n & 1)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                cout << i * 2 << ' ';
                sum += i * 2;
            }
            for (int i = 0; i < n - 1; i++) {
                cout << i * 2 + 1 << ' ';
                sum -= i * 2 + 1;
            }
            cout << sum << endl;
        }
    }
}