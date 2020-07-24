/*
 * @Date         : 2020-04-17 21:02:26
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int t, n, p[maxn], c[maxn];
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        int maxp = -1, maxc = -1, flag = 1;
        for (int i = 0; i < n; i++)
            cin >> p[i] >> c[i];
        for (int i = 0; i < n; i++) {
            if (p[i] < p[i - 1])
                flag = 0;
            if (c[i] < c[i - 1])
                flag = 0;
            if (c[i] - c[i - 1] > p[i] - p[i - 1])
                flag = 0;
            if (!flag)
                break;
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}