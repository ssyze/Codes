/*
 * @Date         : 2020-07-13 13:15:20
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5005;
int n, m, q;
int st[maxn][maxn][14];
int max(int a, int b, int c, int d)
{
    int mx = a;
    if (mx < b) mx = b;
    if (mx < c) mx = c;
    if (mx < d) mx = d;
    return mx;
}
ll ask(int r, int c, int len)
{
    int k = log2(len);
    int t1 = st[r][c][k];
    int t2 = st[r + len - (1 << k)][c][k];
    int t3 = st[r][c + len - (1 << k)][k];
    int t4 = st[r + len - (1 << k)][c + len - (1 << k)][k];
    int mx = max(t1, t2, t3, t4);
    return mx;
}
int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            st[i][j][0] = i * j / __gcd(i, j);
        }
    }
    for (int k = 1; k <= 13; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            for (int j = 1; j + (1 << k) - 1 <= m; j++) {
                int t1 = st[i][j][k - 1];
                int t2 = st[i + (1 << (k - 1))][j][k - 1];
                int t3 = st[i][j + (1 << (k - 1))][k - 1];
                int t4 = st[i + (1 << k - 1)][j + (1 << k - 1)][k - 1];
                st[i][j][k] = max(t1, t2, t3, t4);
            }
        }
    }
    ll sum = 0;
    for (int i = 1; i <= n - q + 1; i++) {
        for (int j = 1; j <= m - q + 1; j++) {
            sum += ask(i, j, q);
        }
    }
    cout << sum << endl;
}