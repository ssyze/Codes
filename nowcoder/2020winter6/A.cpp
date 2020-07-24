/*
 * @Date         : 2020-02-15 13:27:25
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll sum[maxn], a[maxn], b[maxn], n, k;
int main()
{
    cin >> n >> k;
    k = n - k + 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(b + k, b + n + 1, greater<int>());
    for (int i = 0; i < n - k + 1; i++) {
        sum[i] = a[k + i] + b[k + i];
    }
    sort(sum, sum + n - k + 1);
    cout << sum[0] << endl;
}