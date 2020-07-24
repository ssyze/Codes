/*
 * @Date         : 2020-03-24 16:35:09
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int n, m, k;
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < 2 * k; i++) {
        int x, y;
        cin >> x >> y;
    }
    int sum = n + m + n * m - 3;
    cout << sum << endl;
    if (sum == 0)
        return 0;
    for (int i = 0; i < m - 1; i++)
        cout << 'L';
    for (int i = 0; i < n - 1; i++)
        cout << 'D';
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            for (int i = 0; i < n - 1; i++)
                cout << 'U';
            continue;
        }
        cout << 'R';
        if (i & 1) {
            for (int j = 0; j < n - 1; j++)
                cout << 'D';
        }
        else {
            for (int j = 0; j < n - 1; j++)
                cout << 'U';
        }
    }
    cout << endl;
}