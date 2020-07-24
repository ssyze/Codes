/*
 * @Date         : 2020-01-29 12:38:04
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
long long n, ans;
int a[maxn];
void dfs(int pos, long long sum)
{
    if (pos == n) {
        ans += sum;
        return;
    }
    dfs(pos + 1, sum);
    dfs(pos + 1, sum | a[pos]);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dfs(0, 0);
    cout << ans << endl;
}