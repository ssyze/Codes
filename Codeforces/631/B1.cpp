/*
 * @Date         : 2020-04-15 21:07:06
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int t, n, a[maxn], vis1[maxn][2], vis2[maxn][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            vis1[i][0] = vis2[i][0] = 0;
            vis1[i][1] = vis2[i][1] = 0;
        }
        int flag1 = 1, flag2 = 1, l1, l2;
        for (int i = 1; i <= n; i++) {
            if (!vis1[i][0]) {
                vis1[i][0] = 1;
            }
            else {
                l1 = i - 1;
                for (int j = i; j <= n; j++) {
                    if (!vis1[i][1]) {
                        vis1[i][1] = 1;
                    }
                }
            }
        }
    }
}