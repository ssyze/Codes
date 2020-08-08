/*
 * @Date         : 2020-08-03 23:29:57
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
int num[] = {6, 10, 14};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n < 31)
            cout << "NO" << '\n';
        else {
            if (n == 36)
                cout << "YES\n6 14 15 1\n";
            else if (n == 40)
                cout << "YES\n6 14 15 5\n";
            else if (n == 44)
                cout << "YES\n6 14 15 9\n";
            else
                cout << "YES\n6 10 14 " << n - 30 << '\n';
        }
    }
}