/*
 * @Date         : 2020-07-13 14:49:19
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int n, m, k;
long long sum;
int a[maxn][maxn], ans[maxn][maxn], que[maxn];
void getmax(int r)
{
    memset(que, 0, sizeof(que));
    int i, head = 1, tail = 1;
    for (int i = 1; i < k; i++) {
        while (tail >= head && a[i][r] > a[que[tail]][r]) tail--;
        tail++;
        que[tail] = i;
    }
    for (int i = k; i <= n; i++) {
        while (tail >= head && i - que[head] >= k) head++;
        while (tail >= head && a[i][r] > a[que[tail]][r]) tail--;
        tail++;
        que[tail] = i;
        if (i != n) {
            ans[i - k + 1][r] = a[que[head]][r];
        }
    }
    ans[n - k + 1][r] = a[que[head]][r];
}
void getmax1(int c)
{
    memset(que, 0, sizeof(que));
    int i, head = 1, tail = 1;
    for (int i = 1; i < k; i++) {
        while (tail >= head && ans[c][i] > ans[c][que[tail]]) tail--;
        tail++;
        que[tail] = i;
    }
    for (int i = k; i <= m; i++) {
        while (tail >= head && i - que[head] >= k) head++;
        while (tail >= head && ans[c][i] > ans[c][que[tail]]) tail--;
        tail++;
        que[tail] = i;
        if (i != m) sum += ans[c][que[head]];
    }
    sum += ans[c][que[head]];
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) a[i][j] = i * j / __gcd(i, j);

    for (int i = 1; i <= m; i++) {
        getmax(i);
    }
    /* for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    } */
    for (int i = 1; i <= n; i++) {
        getmax1(i);
    }
    cout << sum << endl;
}