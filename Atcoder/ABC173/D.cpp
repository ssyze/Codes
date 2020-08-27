/*
 * @Date         : 2020-08-10 15:25:18
 * @Author       : ssyze
 * @Description  :
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 2; i < a.size(); i++) {
        ans += a[i / 2];
    }
    cout << ans + a[0] << endl;
}