/*
 * @Date         : 2019-12-19 23:25:05
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
int dp[maxn];
int fib(int x)
{
    if (dp[x])
        return dp[x];
    else if (x < 2)
        return 1;
    else
        return dp[x] = fib(x - 1) + fib(x - 2);
}
int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
}