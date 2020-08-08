/*
 * @Date         : 2020-07-25 14:56:58
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int n, a[maxn * 2], b[maxn];
int Search(int num, int low, int high)
{
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (num >= b[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int DP(int x)
{
    int i, len, pos;
    b[1] = a[x];
    len = 1;
    for (i = x + 1; i <= n + x - 1; i++) {
        if (a[i] >= b[len]) {
            len = len + 1;
            b[len] = a[i];
        }
        else {
            pos = Search(a[i], 1, len);
            b[pos] = a[i];
        }
    }
    return len;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        memset(b, 0, sizeof(b));
        ans = max(ans, DP(i));
    }
    cout << n - ans << endl;
}