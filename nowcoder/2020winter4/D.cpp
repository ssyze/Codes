/*
 * @Date         : 2020-02-11 15:16:02
 * @Author       : ssyze
 * @Description  : 
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
typedef long long ll;
ll n, sum, ans;
int a[maxn];
map<int, ll> m;
int main()
{
    cin >> n;
    m[0] = 1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        sum = sum ^ a[i];
        ans += m[sum];
        m[sum]++;
    }
    cout << ans << endl;
}