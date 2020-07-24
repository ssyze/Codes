/*
 * @Date         : 2020-04-05 17:29:09
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[15], b[15], c[15], d[15], dp[1005], amount[15];

void ZeroOnePack(int cost, int weight)
{
    for (int i = n; i >= cost; i--)
        dp[i] = max(dp[i], dp[i - cost] + weight);
}

void CompletePack(int cost, int weight)
{
    for (int i = cost; i <= n; i++)
        dp[i] = max(dp[i], dp[i - cost] + weight);
}

void MultiplePack(int cost, int weight, int amount)
{
    if (cost * amount >= n)
        CompletePack(cost, weight);
    else {
        int k = 1;
        while (k < amount) {
            ZeroOnePack(k * cost, k * weight);
            amount -= k;
            k <<= 1;
        }
        ZeroOnePack(amount * cost, amount * weight);
    }
}

int main()
{
    cin >> n >> m >> c[0] >> d[0];
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        amount[i] = a[i] / b[i];
    }
    amount[0] = n / c[0];
    for (int i = 0; i <= m; i++) {
        MultiplePack(c[i], d[i], amount[i]);
    }
    cout << dp[n] << endl;
}