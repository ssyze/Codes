/*
 * @Date         : 2019-12-28 13:38:37
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
string a[7] = { "do", "re", "mi", "fa", "sol", "la", "si" };
int n;
int num[maxn];
string y[maxn];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[num[i] - 1] != y[i])
            ans++;
    }
    cout << ans << endl;
}