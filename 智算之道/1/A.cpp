/*
 * @Date         : 2020-07-12 18:58:53
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn], m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        for (int i = x; i <= n; i += x) a[i] = 1;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (!a[i]) sum++;
    cout << sum << '\n';
}