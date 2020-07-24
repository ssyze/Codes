/*
 * @Date         : 2020-04-04 17:27:56
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin >> n;
    vector<int> a(n), dp(n, 1);
    for (auto& x : a)
        cin >> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (auto& x : dp)
        cout << x << ' ';
    cout << endl;
}