#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, k, Case;
ll l, r;
ll dp[20][1100][15];
vector<int> fac;
int newSta(int sta, int n)
{
    for (int i = n; i <= 9; i++)
        if ((1 << i) & sta) return (sta ^ (1 << i)) | (1 << n);
    return sta | (1 << n);
}
ll dfs(int pos, int sta, int pre, int lim)
{
    if (pos < 0) {
        int cnt = 0;
        while (sta) {
            if (sta & 1) cnt++;
            sta >>= 1;
        }
        return cnt == k;
    }
    if (!lim && !pre && ~dp[pos][sta][k]) return dp[pos][sta][k];
    int up = lim ? fac[pos] : 9;
    // cout << pos << ' ' << sta << ' ' << pre << ' ' << lim << ' ' << up << endl;
    ll tmp = 0;
    for (int i = 0; i <= up; i++) {
        tmp += dfs(pos - 1, (pre && i == 0) ? 0 : newSta(sta, i), pre && i == 0, lim && i == up);
    }
    if (!lim && !pre) dp[pos][sta][k] = tmp;
    return tmp;
}
ll solve(ll x)
{
    fac.clear();
    while (x) {
        fac.push_back(x % 10);
        x /= 10;
    }
    return dfs(fac.size() - 1, 0, 1, 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> t;
    while (t--) {
        cin >> l >> r >> k;
        cout << "Case #" << ++Case << ": " << solve(r) - solve(l - 1) << '\n';
    }
}