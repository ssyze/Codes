#include <bits/stdc++.h>
using namespace std;
const int maxn = 125;
int dp[125], a[125];
int main()
{
    int n;
    while (cin >> n)
    {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                dp[j] += dp[j - i];
            }
        }

        cout << dp[n] << endl;
    }
}