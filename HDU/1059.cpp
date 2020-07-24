/*
 * @Date         : 2020-02-24 15:08:42
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int dp[maxn], Case, a[7], sum;
void ZeroOnePack(int cost, int weight) //01背包
{
    for (int i = sum; i >= cost; i--)
        dp[i] = max(dp[i], dp[i - cost] + weight);
}
void CompletePack(int cost, int weight) //完全背包
{
    for (int i = cost; i <= sum; i++)
        dp[i] = max(dp[i], dp[i - cost] + weight);
}
void MultiplePack(int cost, int weight, int amount) //多重背包
{
    if (amount == 0)
        return;
    if (cost * amount >= sum)
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
    while (cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6]) { //输入
        sum = 0;
        for (int i = 1; i <= 6; i++) { //求和
            sum += a[i] * i;
        }
        if (sum == 0)
            break;
        if (sum & 1) { //奇数时无法分解
            printf("Collection #%d:\nCan't be divided.\n\n", ++Case);
            continue;
        }
        sum /= 2;
        memset(dp, 0, sizeof(dp)); //初始化
        for (int i = 1; i <= 6; i++) { //对6个物品开始做多重背包
            MultiplePack(i, i, a[i]);
        }
        if (dp[sum] == sum) //若可以凑成容量为sum的背包价值也为sum，则可以分成两堆
            printf("Collection #%d:\nCan be divided.\n\n", ++Case);
        else
            printf("Collection #%d:\nCan't be divided.\n\n", ++Case);
    }
}