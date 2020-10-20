#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v[4] = { 0, 3, 5, 2 };
    int w[4] = { 0, 3, 2, 4 };
    int V = 10;
    int dp[15] = { 0 };
    for (int i = 1; i <= 3; i++) {
        for (int j = V; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            printf("dp[%d] = %d\n", j, dp[j]);
        }
    }
}