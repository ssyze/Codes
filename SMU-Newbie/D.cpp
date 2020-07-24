/*
 * @Date         : 2019-12-28 13:26:49
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n;
int a[maxn][maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= 1; j--)
            cout << a[j][i] << " ";
        cout << "\n";
    }
}