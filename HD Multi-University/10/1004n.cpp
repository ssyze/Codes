/*
 * @Date         : 2020-08-20 13:15:40
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 6000;
const int mod = 1e9 + 7;

int a[maxn], b[maxn], vis[maxn], t, n;
ll c[maxn][maxn], ans;

void init()
{
    c[0][0] = c[1][0] = c[1][1] = 1;
    for (int i = 2; i < maxn; ++i) {
        for (int j = 0; j < i; ++j) {
            if (j == 0 || j == i - 1)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
}

ll C(ll n, ll m) { return c[n + 1][m]; }

bool check()
{
    for (int i = 1; i <= n - 1; ++i) {
        if (b[i] < b[i + 1] && a[i] == 1)
            return 0;
        else if (b[i] > b[i + 1] && a[i] == 0)
            return 0;
    }
    return 1;
}

void dfs(int cur)
{
    if (cur == n + 1) {
        if (check()) {
            ans++;
            for (int i = 1; i <= n; i++) cout << b[i] << ' ';
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            vis[i] = 1;
            b[cur] = i;
            dfs(cur + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    init();
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n - 1; ++i) cin >> a[i];
        dfs(1);
        cout << ans << endl;
    }
}
