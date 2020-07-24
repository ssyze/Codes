/*
 * @Date         : 2020-01-07 12:41:40
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[15][15][3];
//dp[pos][mod][one]
//记录末尾是不是1,有没有13
int num[15];
int n;

ll dfs(int pos, int mod, int one3, bool lim)
{
    if (pos == -1)
        return mod == 0 && one3 == 2;
    if (!lim && dp[pos][mod][one3] != -1)
        return dp[pos][mod][one3];
    int up = lim ? num[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= up; i++) {
        int m = (mod * 10 + i) % 13;
        int tmp = one3;
        if (one3 == 0 && i == 1)
            tmp = 1;
        if (one3 == 1 && i != 1)
            tmp = 0;
        if (one3 == 1 && i == 3)
            tmp = 2;
        ans += dfs(pos - 1, m, tmp, lim && i == up);
    }
    if (!lim)
        dp[pos][mod][one3] = ans;
    return ans;
}

int main()
{
    while (cin >> n) {
        memset(dp, -1, sizeof(dp));
        memset(num, 0, sizeof(num));
        int l = 0;
        while (n) {
            num[l++] = n % 10;
            n /= 10;
        }
        cout << dfs(l, 0, 0, 1) << endl;
    }
}