/*
 * @Date         : 2019-12-19 22:42:14
 * @Author       : ssyze
 * @Description  : 状压dp
 */
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int dp[8];
int n, c;
string s;
int main()
{
    for (int i = 1; i < 8; i++)
        dp[i] = inf;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> s;
        int m = 0;
        for (int j = 0; j < s.length(); j++) {
            m |= 1 << (s[j] - 'A');
        }
        //cout << m << endl;
        for (int j = 0; j < 8; j++) {
            dp[j | m] = min(dp[j | m], dp[j] + c);
            //printf("dp[%d] = %d\n", j, dp[j]);
        }
    }
    if (dp[7] == inf)
        cout << -1 << endl;
    else
        cout << dp[7] << endl;
}