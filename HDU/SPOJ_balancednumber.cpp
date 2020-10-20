#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int t;
ull a, b;
vector<int> fac;
ull dp[20][515][515];
ull dfs(int pos, int sta, int exist, int pre, int lim)
{
    if (pos == -1) { int flag = 1, cnt = 0; }
}
ull solve(ull n)
{
    fac.clear();
    while (n) {
        fac.push_back(n % 10);
        n /= 10;
    }
    return dfs(fac.size(), 0, 1, 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << solve(b) - solve(a - 1) << '\n';
    }
}