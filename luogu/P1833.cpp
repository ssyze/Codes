#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int h1, h2, m1, m2, n;
int v[maxn], w[maxn], p[maxn], dp[2005];
int main()
{
    scanf("%d:%d %d:%d %d", &h1, &m1, &h2, &m2, &n);
    int V = (h2 - h1) * 60 + (m2 - m1);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i] >> p[i];
        if (p[i] == 0) {
            for (int j = w[i]; j <= V; j++) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        } else {
            int k = 1;
            while (k < p[i]) {
                for (int j = V; j >= k * w[i]; j--) {
                    dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
                }
                p[i] -= k;
                k *= 2;
            }
            for (int j = V; j >= p[i] * w[i]; j--) {
                dp[j] = max(dp[j], dp[j - p[i] * w[i]] + p[i] * v[i]);
            }
        }
        // cout << dp[V] << endl;
    }
    cout << dp[V] << endl;
}