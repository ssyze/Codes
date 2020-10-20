#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int a, b;
vector<int> fac;
int dp[40][100][2][2];
int dfs(int pos, int d, int lead, int lim)
{
    // cout << pos << ' ' << d << ' ' << lead << ' ' << lim << endl;
    if (pos < 0) return d >= 50;
    if (~dp[pos][d][lead][lim]) return dp[pos][d][lead][lim];
    int up = lim ? fac[pos] : 1, tmp = 0;
    for (int i = 0; i <= up; i++) {
        if (lead && i == 0)
            tmp += dfs(pos - 1, d, 1, lim && i == fac[pos]);
        else if (!lead && i == 0)
            tmp += dfs(pos - 1, d + 1, 0, lim && i == fac[pos]);
        else if (i == 1)
            tmp += dfs(pos - 1, d - 1, 0, lim && i == fac[pos]);
    }
    dp[pos][d][lead][lim] = tmp;
    return tmp;
}
int solve(int n)
{
    fac.clear();
    while (n) {
        fac.push_back(n % 2);
        n /= 2;
    }
    return dfs(fac.size() - 1, 50, 1, 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << endl;
}