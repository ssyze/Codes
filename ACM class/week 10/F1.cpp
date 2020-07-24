/*
 * @Date         : 2020-03-25 16:17:41
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, L;
int a[maxn];
int main()
{
    while (cin >> n >> L) {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int tmp = 0, ans = 0;
        while (tmp < L) {
            tmp += a[ans++];
        }
        if (tmp == L)
            cout << ans << endl;
        else
            cout << ans - 1 << endl;
    }
}