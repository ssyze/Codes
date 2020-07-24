/*
 * @Date         : 2020-04-17 16:49:57
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << "W";
        for (int i = 0; i < m - 1; i++)
            cout << "B";
        cout << endl;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++)
                cout << "B";
            cout << endl;
        }
    }
}