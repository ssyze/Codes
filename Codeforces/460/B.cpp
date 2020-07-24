/*

dp[i][s] = number of numbers with i digits (leading 0-s counts) and sum of
digits Every possible number [i][s] is a path from [i][s] to [0][0]. So you
start looking at some number of digits and the sum you want. Try putting a 0 in
the last position. dp[i — 1][s — 0] is the number of such numbers. If that's
lesser than the n that you are looking for, you know that the number you want
has some number greater than 0 in this position, so you exclude the numbers that
have the same prefix and 0 in this position (n -= dp[i — 1][s — 0]) and try it
for 1. Keep on trying for all the next digits 0 <= j <= 9 until n <= dp[i — 1][s
— j]. Now you know that the number you are looking for has digit j in this
position and can do the same process for i — 1 until getting to i == 0.

 */

#include <iostream>

const int ms = 18;

long long dp[ms][11];

int main()
{
    dp[0][0] = 1;
    for (int i = 1; i < ms; i++) {
        for (int j = 1; j <= 10; j++) {
            dp[i - 1][j] += dp[i - 1][j - 1];
        }

        for (int j = 0; j <= 10; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        dp[i][10]--;

        for (int j = 10; j > 0; j--) {
            dp[i - 1][j] -= dp[i - 1][j - 1];
        }
    }
    long long k;
    std::cin >> k;
    long long ans = 0;
    for (int i = ms - 1, s = 10; i > 0; i--) {
        int j = 0;
        while (dp[i - 1][s - j] < k) {
            k -= dp[i - 1][s - j++];
        }
        s -= j;
        ans = j + ans * 10;
    }
    std::cout << ans << '\n';
}