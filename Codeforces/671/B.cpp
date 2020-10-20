#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll x, sum[31];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1, tmp = 1; i <= 30; i++) {
        sum[i] = sum[i - 1] + tmp;
        tmp *= 2;
    }
    for (int i = 1; i <= 30; i++) {
        sum[i] = (1 + sum[i]) * sum[i] / 2;
        sum[i] += sum[i - 1];
        // cout << sum[i] << endl;
    }
    cin >> t;
    while (t--) {
        cin >> x;
        int ans = upper_bound(sum + 1, sum + 31, x) - sum;
        cout << ans - 1 << endl;
    }
}