#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2005;
const int mod = 1e9 + 7;
ll g[maxn][maxn];
int r[maxn], c[maxn];
int sum[maxn][maxn];
int n, m, h;
int main()
{
    scanf("%d%d%d", &n, &m, &h);
    for (int i = 0; i < h; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        r[x] += z;
        c[y] += z;
        g[x][y] -= z;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            g[i][j] += r[i] + c[j];
        }
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum += g[i][j] * (i + j);
            sum %= mod;
        }
    }
    cout << sum << endl;
}