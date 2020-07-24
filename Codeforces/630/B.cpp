/*
 * @Date         : 2020-04-01 15:24:50
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int use[12];
int a[maxn], ans[maxn], t, n, prim[maxn], cnt;
int main()
{
    cnt = 2, prim[0] = 2, prim[1] = 3;
    for (int i = 4; i * i <= 1000; i++) {
        int flag = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag)
            prim[cnt++] = i;
    }
    cin >> t;
    while (t--) {
        memset(use, 0, sizeof(use));
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int tot = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < cnt; j++) {
                if (a[i] % prim[j] == 0) {
                    if (!use[j])
                        use[j] = ++tot;
                    ans[i] = use[j];
                    break;
                }
            }
        }
        cout << tot << endl;
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
}