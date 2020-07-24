/*
 * @Date         : 2020-03-20 20:27:57
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn][maxn];
int b[maxn];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = 0; j < n; j++) {
            x |= a[i][j];
        }
        b[i] = x;
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << endl;
}